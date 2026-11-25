#!/usr/bin/env python3
"""Argumentos heredados en ARM, reescribiendo el IR de LLVM.

En PPC una función puede reenviar r4-r10 y f1-f8 sin mencionarlos (docs-data/inherit-census.json lo calcula sobre el listado). En
arm64 sobrevivían casi siempre, porque clang usa x8+ como temporales; en ARM usa r1-r3 y los pisa. Aquí esas funciones declaran los
argumentos que necesitan y los añaden a cada llamada que pasa menos: lo mismo que hacían los registros vivos en el original.
"""
import concurrent.futures as cf, json, os, re, subprocess
from abi_census import cls, split_args, SIG

# v34: también la conversión implícita de Ptr32 (W3dPtr32Conv, core/runtime/w3d_ptr.h): no es una llamada del juego y no
# debe pisar r3 (sin esto, 13 335 conversiones en 1879 unidades cambiaban el r3 heredado; en Azahar, salto a 0 al pausar).
SKIP_CALL = re.compile(r'^@(llvm\.|_ZN[VK]*5Ptr32|_ZN[VK]*12W3dPtr32Conv|_ZN3w3d|_ZNK?V?K?5Ptr32)')


def int_slots(c): return 2 if c == 'L' else 1 if c in 'IPR' else 0


CALL = re.compile(r'\b(?:tail |musttail |notail )?call\b')


def parse_call(b):
    """(destino, inicio de args, fin de args, args) de una línea con call, o None."""
    m = CALL.search(b)
    if not m or b.startswith(('define', 'declare')): return None
    rest = b[m.end():]
    d = re.search(r'(%[\w.$-]+|@"?[\w.$-]+"?)\(', rest)
    if not d: return None
    pre = rest[:d.start()]
    if '...' in pre or '(' in pre: return None   # Tipo de función explícito: variádica.
    st = m.end() + d.end(); depth = 1; j = st
    while j < len(b) and depth:
        depth += b[j] in '([{<'; depth -= b[j] in ')]}>'; j += 1
    return d.group(1), st, j - 1, split_args(b[st:j - 1])


def count_args(ca):
    hi = hf = 0; simple = True
    for x in ca:
        c = cls(x); t = x.strip()
        if t.startswith('['):
            q = re.match(r'\[(\d+) x i32\]', t); hi += int(q.group(1)) if q else 0
        elif c == 'S': simple = False
        else: hi += int_slots(c); hf += c in 'FD'
    return hi, hf, simple


LARGE = re.compile(r'^\s*\[(\d+) x i32\]')


def byref_large(lines):
    """Agregados de más de 16 B: PPC y arm64 pasan un puntero a una copia; AAPCS los reparte entre registros y pila."""
    out = []; tmp = 0; i = 0
    while i < len(lines):
        b = lines[i]; i += 1
        if b.startswith(('define', 'declare')):
            g = SIG.match(b)
            if g and '[' in g.group(4):
                args = split_args(g.group(4)); new = []; entry = []; ren = {}
                for a in args:
                    m = LARGE.match(a)
                    if m and int(m.group(1)) > 4:
                        tok = a.strip().split()[-1] if b.startswith('define') else ''
                        new.append(f'ptr {tok}'.rstrip())
                        if tok:
                            nm = f'%w3d_bv{tok[1:]}'; entry.append(f'  {nm} = load [{m.group(1)} x i32], ptr {tok}, align 4'); ren[tok] = nm
                    else: new.append(a.strip())
                if len(new) == len(args) and new != [a.strip() for a in args]:
                    b = b[:g.start(4)] + ', '.join(new) + b[g.end(4):]
                    out.append(b); out.extend(entry)
                    if ren:
                        while i < len(lines) and not lines[i].startswith('}'):
                            l = lines[i]
                            for k, v in ren.items(): l = re.sub(re.escape(k) + r'(?![\w.$])', v, l)
                            # La copia debe ir antes que su uso: se reescribe la línea con el mismo trato de llamadas de abajo.
                            lines[i] = l; break_ = False
                            i += 1
                            pc = parse_call(l)
                            if pc and any(LARGE.match(x) and int(LARGE.match(x).group(1)) > 4 for x in pc[3]):
                                i -= 1; lines[i] = l; break
                            out.append(l)
                        # El resto de la función sigue con el bucle general, con los nombres ya cambiados.
                        j = i
                        while j < len(lines) and not lines[j].startswith('}'):
                            for k, v in ren.items(): lines[j] = re.sub(re.escape(k) + r'(?![\w.$])', v, lines[j])
                            j += 1
                    continue
            out.append(b); continue
        pc = parse_call(b)
        if pc and any(LARGE.match(x) and int(LARGE.match(x).group(1)) > 4 for x in pc[3]):
            callee, st, en, ca = pc; new = []
            for x in ca:
                m = LARGE.match(x)
                if m and int(m.group(1)) > 4:
                    tmp += 1; nm = f'%w3d_cp{tmp}'; ty = f'[{m.group(1)} x i32]'; val = x.strip().split()[-1]
                    out.append(f'  {nm} = alloca {ty}, align 4'); out.append(f'  store {ty} {val}, ptr {nm}, align 4'); new.append(f'ptr {nm}')
                else: new.append(x.strip())
            b = b[:st] + ', '.join(new) + b[en:]
        out.append(b)
    return out


def rewrite(text, want_by_name, want_of_callee):
    out = []; lines = byref_large(text.split('\n')); i = 0; n_done = 0; final = {}; ext = {}
    defined = {SIG.match(x).group(3).strip('"') for x in lines if x.startswith('define') and SIG.match(x)}
    def target(callee, ki, kf):
        if callee.startswith('%'): return ki, kf
        n = callee[1:].strip('"')
        # Destructores: la bandera oculta la pone su thunk de enlace (bit 1, borrar).
        if SKIP_CALL.match(callee) or n not in want_of_callee or re.search(r'D[012]Ev$', n): return 0, 0
        return want_of_callee[n]
    while i < len(lines):
        l = lines[i]
        g = SIG.match(l) if l.startswith('define') else None
        name = g.group(3).strip('"') if g else None
        if not g or name not in want_by_name or '...' in g.group(4):
            out.append(l); i += 1; continue
        ki, kf, strong = want_by_name[name]
        if not strong:
            # Solo si alguna llamada pasa menos de lo que su destino puede leer.
            e = i + 1; need = False
            while e < len(lines) and not lines[e].startswith('}'):
                pc = parse_call(lines[e])
                if pc:
                    ti, tf = target(pc[0], ki, kf); hi, hf, sim = count_args(pc[3])
                    if sim and (hi < ti or hf < tf): need = True; break
                e += 1
            if not need:
                out.append(l); i += 1; continue
        args = split_args(g.group(4))
        new_args = list(args); entry = []; regs = []; fps = []
        for a in args:
            c = cls(a); t = a.strip(); val = t.split()[-1]
            if t.startswith('['):
                m = re.match(r'\[(\d+) x i32\]', t)
                for k in range(int(m.group(1)) if m else 0):
                    nm = f'%w3d_x{len(regs)}'; entry.append(f'  {nm} = extractvalue {t.rsplit(" ", 1)[0]} {val}, {k}'); regs.append(nm)
            elif c in 'PR':
                nm = f'%w3d_x{len(regs)}'; entry.append(f'  {nm} = ptrtoint ptr {val} to i32'); regs.append(nm)
            elif c == 'I':
                ty = t.split()[0]; nm = f'%w3d_x{len(regs)}'
                entry.append(f'  {nm} = zext {ty} {val} to i32' if ty != 'i32' else f'  {nm} = add i32 {val}, 0'); regs.append(nm)
            elif c == 'L': regs += ['undef', 'undef']
            elif c == 'F': fps.append(val)
            elif c == 'D': fps.append(None)
        while len(regs) < ki:
            nm = f'%w3d_a{len(regs)}'; new_args.append(f'i32 {nm}'); regs.append(nm)
        while len(fps) < kf:
            nm = f'%w3d_f{len(fps)}'; new_args.append(f'float {nm}'); fps.append(nm)
        head = l[:g.start(4)] + ', '.join(x.strip() for x in new_args) + l[g.end(4):]
        final[name] = (len(regs), len(fps))
        out.append(head); out.extend(entry); i += 1; n_done += 1
        # r3 del original: empieza con el primer argumento y lo pisa cada llamada con resultado entero.
        tmp = 0
        out.append('  %w3d_r3 = alloca i32, align 4')
        if regs and regs[0] != 'undef': out.append(f'  store i32 {regs[0]}, ptr %w3d_r3, align 4')
        while i < len(lines) and not lines[i].startswith('}'):
            b = lines[i]
            pc = parse_call(b)
            if pc:
                callee, st, en, ca = pc
                ti, tf = target(callee, ki, kf); hi, hf, sim = count_args(ca)
                # Agregado devuelto por registros: la definición lo escribe en un destino oculto, y el thunk lo reparte.
                if re.search(r'call [^@%]*%struct', b[:st]) or re.search(r'call [^@%]*\{', b[:st]): sim = False
                add = []
                if sim:
                    for k in range(hi, min(ti, len(regs))):
                        if k == 0:
                            tmp += 1; out.append(f'  %w3d_l{tmp} = load i32, ptr %w3d_r3, align 4'); add.append(f'i32 %w3d_l{tmp}')
                        else: add.append(f'i32 {regs[k]}')
                    for k in range(hf, min(tf, len(fps))):
                        if fps[k]: add.append(f'float {fps[k]}')
                if add:
                    b = b[:en] + (', ' if b[st:en].strip() else '') + ', '.join(add) + b[en:]
                    if callee.startswith('@'):
                        cn = callee[1:].strip('"'); na = sum(a.startswith('i32') for a in add); nf = len(add) - na
                        e_ = ext.get(cn, (0, 0)); ext[cn] = (max(e_[0], hi + na), max(e_[1], hf + nf))
                # Una llamada void también deja algo en r3: el original lo aprovecha al encadenar con funciones vacías.
                if re.match(r'\s*(?:tail |notail )?call void ', b) and not SKIP_CALL.match(callee) and not (callee.startswith('@') and callee[1:].strip('"') in defined):
                    tmp += 1; b = re.sub(r'^(\s*)((?:tail |notail )?call )void ', rf'\1%w3d_c{tmp} = \2i32 ', b, count=1)
                r = re.match(r'\s*(%[\w.$-]+) = (?:tail |musttail |notail )?call [^%@]*?\b(i32|ptr)\b[^%@]*(?:%|@)', b)
                if r and not SKIP_CALL.match(callee):
                    out.append(b)
                    if r.group(2) == 'i32': b = f'  store i32 {r.group(1)}, ptr %w3d_r3, align 4'
                    else: b = f'  store ptr {r.group(1)}, ptr %w3d_r3, align 4'
            out.append(b); i += 1
    # Una llamada con menos argumentos a una definición del mismo módulo sería indefinida, y LLVM la borraría.
    if final:
        for q, b in enumerate(out):
            pc = parse_call(b)
            if not pc or not pc[0].startswith('@') or pc[0][1:].strip('"') not in final: continue
            callee, st, en, ca = pc
            hi, hf, _ = count_args(ca); ti, tf = final[callee[1:].strip('"')]
            add = ['i32 undef'] * max(0, ti - hi) + ['float undef'] * max(0, tf - hf)
            if add: out[q] = b[:en] + (', ' if b[st:en].strip() else '') + ', '.join(add) + b[en:]
    # La declaración debe decir lo que de verdad se pasa: de ella salen los thunks del enlace.
    if ext:
        for q, b in enumerate(out):
            if not b.startswith('declare'): continue
            g = SIG.match(b)
            if not g or g.group(3).strip('"') not in ext or '...' in g.group(4): continue
            ca = split_args(g.group(4)); hi, hf, _ = count_args(ca); ti, tf = ext[g.group(3).strip('"')]
            add = ['i32'] * max(0, ti - hi) + ['float'] * max(0, tf - hf)
            if add: out[q] = b[:g.end(4)] + (', ' if g.group(4).strip() else '') + ', '.join(add) + b[g.end(4):]
    # Función con valor que llega al final sin return: en el original queda en r3 lo último que dejó una llamada.
    cur = None; last = None; fixed = []
    for b in out:
        if b.startswith('define'):
            g = SIG.match(b); cur = None
            if g:
                toks = [t for t in g.group(2).split() if t not in ('noundef', 'signext', 'zeroext', 'dso_local', 'internal', 'weak_odr', 'linkonce_odr', 'nonnull', 'noalias', 'hidden') and not t.startswith(('align', 'dereferenceable'))]
                cur = ' '.join(toks[-1:]) if toks else None
            last = None
        elif re.match(r'^[\w.$"-]+:', b): last = None
        else:
            r = re.match(r'\s*(%[\w.$-]+) = (?:tail )?call [^%@]*?\bi32\b', b)
            if r: last = r.group(1)
            if 'call void @llvm.trap()' in b and cur and cur != 'void':
                fixed.append(f'  ret i32 {last}' if cur == 'i32' and last else f'  ret {cur} undef')
                continue
        if b.strip() == 'unreachable' and fixed and fixed[-1].startswith('  ret '): continue
        fixed.append(b)
    out = fixed
    # El IR sale de -O0: sin esto nada se inlinearía, ni los accesos de Ptr32.
    txt = pad_functions('\n'.join(out))
    txt = re.sub(r'^(attributes #\d+ = \{.*)$', lambda m: re.sub(r'"frame-pointer"="\w+" ?', '', re.sub(r'\bnoinline\b ?', '', m.group(1))).replace('{', '{ "frame-pointer"="all" ', 1), txt, flags=re.M)
    # Cada ayudante definido debe existir en el objeto: otra unidad puede enlazar con él. --gc-sections quita lo que sobre.
    txt = txt.replace('define linkonce_odr ', 'define weak_odr ')
    return txt, n_done


# v34: relleno de pila. Con los Ptr32 sin volatile (core/runtime/w3d_ptr.h) cada puntero vive en un registro y el marco de
# las funciones ya no tiene los huecos de antes; una variable local más pequeña que lo que escribe quien la recibe (la Mat de
# 60 B de d27h_distance_light, que f4c_normalize llena con 64) pisaba un registro guardado del llamador. Cada función con
# estructuras o arrays locales lleva 16 B de relleno como primer alloca: queda justo debajo de los registros guardados.
# Va con W3D_PAD=1 (pensado para W3D_PTR_FAST; por defecto no). W3D_PAD_CHECK=1 (diagnóstico): el relleno lleva un patrón que se comprueba al volver, y si alguien lo
# pisó se llama a w3d_pad_hit(función) (platform/3ds/diag.cpp: lo anota una vez por función y el juego sigue).
PAD = os.environ.get('W3D_PAD', '0') != '0' or os.environ.get('W3D_PAD_CHECK', '') not in ('', '0')   # solo con W3D_PTR_FAST
PAD_CHECK = os.environ.get('W3D_PAD_CHECK', '') not in ('', '0')
PAD_AGG = re.compile(r'= alloca (\[|%(struct|class|union)\.(?!Ptr32(\.\d+)? |Ref32))')
# Patrón 0: con 0x5A5A5A5A el juego se caía al arrancar (g3c_register_converters_8020ea2c llama con menos argumentos de los
# que la función lee, y el que falta salía de la pila con el patrón de un relleno anterior). Un 0 se detecta igual si lo pisan.
PAD_WORD = 0


def pad_functions(txt):
    if not PAD: return txt
    lines = txt.split('\n'); out = []; i = 0; used = False; n = 0
    while i < len(lines):
        l = lines[i]
        if not (l.startswith('define ') and l.rstrip().endswith('{')):
            out.append(l); i += 1; continue
        j = i + 1
        while j < len(lines) and lines[j] != '}': j += 1
        body = lines[i + 1:j]
        if not any(PAD_AGG.search(b) for b in body):
            out.extend(lines[i:j]); i = j; continue
        m = re.search(r'@("[^"]+"|[\w.$-]+)\(', l)
        fname = m.group(1) if m else None
        out.append(l)
        out.append('  %w3d_pad = alloca [4 x i32], align 8')
        k = 0
        while k < len(body) and re.match(r'\s+%[\w.$-]+ = alloca ', body[k]): out.append(body[k]); k += 1
        if PAD_CHECK and fname:
            for w in range(4):
                if w: out.append(f'  %w3d_pe{w} = getelementptr inbounds i8, ptr %w3d_pad, i32 {4 * w}')
                out.append(f'  store volatile i32 {PAD_WORD}, ptr {"%w3d_pad" if not w else f"%w3d_pe{w}"}, align 4')
        else:
            out.append('  call void asm sideeffect "", "r"(ptr %w3d_pad)')
        for b in body[k:]:
            r = re.match(r'(\s+)ret\b', b)
            if not (PAD_CHECK and fname and r):
                out.append(b); continue
            n += 1; used = True
            for w in range(4):
                a = '%w3d_pad' if not w else f'%w3d_pa{w}_{n}'
                if w: out.append(f'  {a} = getelementptr inbounds i8, ptr %w3d_pad, i32 {4 * w}')
                out.append(f'  %w3d_pq{w}_{n} = load volatile i32, ptr {a}, align 4')
                out.append(f'  %w3d_px{w}_{n} = xor i32 %w3d_pq{w}_{n}, {PAD_WORD}')
            out.append(f'  %w3d_po1_{n} = or i32 %w3d_px0_{n}, %w3d_px1_{n}')
            out.append(f'  %w3d_po2_{n} = or i32 %w3d_po1_{n}, %w3d_px2_{n}')
            out.append(f'  %w3d_po3_{n} = or i32 %w3d_po2_{n}, %w3d_px3_{n}')
            out.append(f'  %w3d_pb_{n} = icmp ne i32 %w3d_po3_{n}, 0')
            out.append(f'  br i1 %w3d_pb_{n}, label %w3d_ph_{n}, label %w3d_pr_{n}')
            out.append(f'w3d_ph_{n}:')
            out.append(f'  call void @w3d_pad_hit(ptr @{fname})')
            out.append(f'  br label %w3d_pr_{n}')
            out.append(f'w3d_pr_{n}:')
            out.append(b)
        i = j
    if used: out.append('declare void @w3d_pad_hit(ptr)')
    return '\n'.join(out)


def apply(srcs, rename_map, ll_of, obj_of_fn, census_path, work, target):
    census = {}
    for e in json.load(open(census_path)):
        census[int(e['addr'], 16)] = (e.get('need_int', 0), e.get('need_fp', 0), e.get('ints', 0), e.get('fps', 0))
    os.makedirs(work + '/ll_r', exist_ok=True); os.makedirs(work + '/objs_r', exist_ok=True)
    # Funciones vacías (solo blr): devuelven lo que haya en r3, así que leen un argumento aunque no declaren ninguno.
    import struct
    dol = open(os.path.join(os.path.dirname(census_path), '../../gamedata/GWMP8P/sys/main.dol'), 'rb').read()
    off = struct.unpack_from('>18I', dol, 0); adr = struct.unpack_from('>18I', dol, 0x48); sz = struct.unpack_from('>18I', dol, 0x90)
    def is_blr(ad):
        for i_ in range(7):
            if sz[i_] and adr[i_] <= ad < adr[i_] + sz[i_]:
                return struct.unpack_from('>I', dol, off[i_] + ad - adr[i_])[0] == 0x4e800020
        return False
    # Lo que declaran quienes llaman: si pasan más de lo que la definición recibe, es un puente.
    view = {}
    from abi_census import ir_signatures
    def sigs(s_):
        p = ll_of(s_)
        return s_, ir_signatures(p) if os.path.exists(p) else []
    with cf.ThreadPoolExecutor(12) as ex:
        allsig = dict(ex.map(sigs, srcs))
    for s_, ss in allsig.items():
        m = rename_map[s_]
        for kind, name, (rt, ps) in ss:
            new = m.get('_' + name)
            if new and re.fullmatch(r'_A[0-9a-f]{8}', new) and '...' not in ps and not any(x in ('S', 'A') for x in ps):
                ad = int(new[2:], 16); vi = sum(int_slots(x) for x in ps)
                if vi > view.get(ad, 0): view[ad] = vi
    jobs = []
    for s in srcs:
        p = ll_of(s)
        if not os.path.exists(p): continue
        m = rename_map[s]; here = {}; callee = {}
        for k, new in m.items():
            q = re.fullmatch(r'_A([0-9a-f]{8})', new)
            if not q: continue
            ad = int(q.group(1), 16)
            ni, nf, di, df = census.get(ad, (0, 0, 0, 0))
            ni = max(ni, view.get(ad, 0))
            if is_blr(ad): ni = max(ni, 1)
            if ni > di or nf > df: here[k[1:]] = (min(ni, 8), min(nf, 8), True)
            else: here[k[1:]] = (max(4, min(di, 8)), min(df, 8), False)
            callee[k[1:]] = (min(max(ni, di), 8), min(max(nf, df), 8))
        jobs.append((s, p, here, callee))
    res = {}

    def one(j):
        s, p, here, callee = j
        t, n = rewrite(open(p, errors='replace').read(), here, callee)
        base = os.path.basename(p)
        np_ = f'{work}/ll_r/{base}'; no = f'{work}/objs_r/{os.path.basename(obj_of_fn(s))}'
        # Todas las unidades salen del IR, cambien o no: así todas definen los mismos ayudantes. Caché por contenido.
        if os.path.exists(no) and os.path.exists(np_) and open(np_, errors='replace').read() == t: return s, (np_, no, n)
        open(np_, 'w').write(t)
        r = subprocess.run(['clang', '-target', target, '-mfloat-abi=hard', '-mfpu=vfpv2', '-mtune=mpcore', '-O2', '-w', '-Wno-override-module', '-ffunction-sections', '-fdata-sections', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-mframe-chain=aapcs', '-c', np_, '-o', no], capture_output=True, text=True, errors='replace')
        if r.returncode:
            print('ir_inherit falla', s, r.stderr[:400]); return s, None
        return s, (np_, no, n)
    with cf.ThreadPoolExecutor(12) as ex:
        for s, v in ex.map(one, jobs):
            if v: res[s] = v
    return res
