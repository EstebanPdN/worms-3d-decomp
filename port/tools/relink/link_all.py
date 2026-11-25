#!/usr/bin/env python3
"""Enlaza el juego entero por direcciones originales.

Cada objeto de lift_all.py se copia con sus símbolos renombrados a A<dirección>. Genera:
  gen_image.s   bloque de datos vacío con una etiqueta por dirección (el contenido llega del DOL del usuario)
  gen_stubs.s   funciones aún sin definir: avisan con su dirección y abortan
  gen_tables.s  tabla dirección->función y disposición de los datos (sin datos del juego)
  link_report.json

Uso: link_all.py <carpeta de datos> [--extra obj.o ...] [--out binario]
"""
import argparse, collections, concurrent.futures as cf, json, os, re, struct, subprocess, sys, glob
W3DP = __import__('os').environ.get('W3DP', '/tmp/w3dp')  # Carpeta de trabajo; cada agente puede tener la suya.

sys.path.insert(0, os.path.dirname(__file__))
import symbols as S
T3DS = os.environ.get('W3D_TARGET') == '3ds'  # 3DS: objetos ELF de ARM, punteros reales de 32 bits, sin ventana.
if T3DS: from elf_rename import read_symbols, rename, BIN as ARM_BIN
else: from macho_rename import read_symbols, rename
from abi_census import ir_signatures
if T3DS:
    from thunks_arm import thunk_body, keep_first as arm_keep_first
else:
    from thunks import thunk_body

ap = argparse.ArgumentParser()
ap.add_argument('data')
ap.add_argument('--extra', nargs='*', default=[])
ap.add_argument('--out', default=W3DP + '/link/worms3d')
ap.add_argument('--overrides', default=None)
ap.add_argument('--extra-ll', nargs='*', default=[])
a = ap.parse_args()
ROOT = S.ROOT
L = W3DP + '/link'; os.makedirs(L + '/objs', exist_ok=True)
led = json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))
errors = json.load(open(W3DP + '/lift-errors.json'))
by_src = collections.defaultdict(dict); led_name = {}
for f in led['functions']:
    n = f.get('name') or f.get('symbol')
    by_src[f['source']][n] = int(f['address'], 16); led_name[n] = int(f['address'], 16)
maps = S.load_unit_maps(); glob_map = S.load_global()


def obj_of(s):
    # Lua se convierte aparte (port/core/lua) con su piloto de comparación.
    if s.startswith(('build/lua', 'source/vendor/lua-5.0')): return W3DP + '/lua/' + os.path.basename(s).rsplit('.', 1)[0] + '.o'
    return W3DP + '/objs/' + re.sub(r'[^\w]', '_', s) + '.o'


def unit_map(s):
    u = re.sub(r'_v\d+$', '', S.unit_id(s))
    for k in ('game-game_' + S.unit_id(s), 'game-' + S.unit_id(s), S.unit_id(s), 'game-game_' + u):
        if k in maps: return maps[k]
    return {}


overrides = set()
if a.overrides and os.path.exists(a.overrides):
    overrides = {int(x, 16) for x in json.load(open(a.overrides))}
ZONE = (0x802e5574, 0x802f4ef0)  # libm, newlib, libgcc: los da core/libc.
srcs = [s for s in sorted(by_src) if s not in errors and os.path.exists(obj_of(s)) and not all(ZONE[0] <= x < ZONE[1] for x in by_src[s].values())]
print('objetos', len(srcs), 'con error', len(errors))
syms = {}
with cf.ThreadPoolExecutor(12) as ex:
    for s, r in zip(srcs, ex.map(lambda s: read_symbols(obj_of(s)), srcs)): syms[s] = r
if T3DS:
    # El objeto reescrito desde el IR (ir_inherit.py) puede conservar referencias que -O1 quitó del objeto original.
    def _ll_refs(s):
        p = W3DP + '/ll/' + re.sub(r'[^\w]', '_', s) + '.ll'
        if not os.path.exists(p): return s, None
        txt = open(p, errors='replace').read()
        names = re.findall(r'^(?:declare [^@]*@|@)("?[\w.$]+"?)(?:\(| = external )', txt, flags=re.M)
        # Lo definido en -O0 que -O2 inlineó en el objeto original: al reescribir vuelve a salir, y cada unidad debe conservar el suyo.
        defs_ = re.findall(r'^define (?!internal)[^@\n]*@("?[\w.$]+"?)\(', txt, flags=re.M)
        return s, ([n.strip('"') for n in names], [n.strip('"') for n in defs_])
    with cf.ThreadPoolExecutor(12) as ex:
        for s, r_ in ex.map(_ll_refs, srcs):
            if not r_: continue
            ns, ds = r_
            have = {x[1] for x in syms[s]}
            ds_ = {n for n in ds if '_' + n not in have}
            syms[s] = list(syms[s]) + [(0, '_' + n, 1, 1, 0, 0) for n in ds_] + [(0, '_' + n, 1, 0, 0, 0) for n in ns if '_' + n not in have and n not in ds_ and not n.startswith('llvm.')]
all_mangled = {n[1:] for r in syms.values() for _, n, t, *_ in r if n.startswith('__Z') and t & 1}
dem = S.demangle(all_mangled)

# Nombres que da la libc del núcleo y el código de plataforma (ya tienen su enlace).
provided = set()
for o in a.extra:
    for _, n, t, sect, *_ in read_symbols(o):
        if t & 1 and sect: provided.add(n)
print('símbolos de plataforma', len(provided))
overrides |= {int(n[2:], 16) for n in provided if re.fullmatch(r'_A[0-9a-f]{8}', n)}

CXX_BUILTIN = {'__Znwj': '__builtin_new', '__Znaj': '__builtin_vec_new', '__ZdlPvj': '__builtin_delete', '__ZdaPvj': '__builtin_vec_delete', '__Znwm': '__builtin_new', '__Znam': '__builtin_vec_new', '__ZdlPv': '__builtin_delete', '__ZdaPv': '__builtin_vec_delete', '__ZdlPvm': '__builtin_delete', '__ZdaPvm': '__builtin_vec_delete'}
alloc_thunks = {}
CXX_RUNTIME = {'__Znwj': '_w3d_op_new', '__Znaj': '_w3d_op_new', '__ZdlPvj': '_w3d_op_delete', '__ZdaPvj': '_w3d_op_delete', '__Znwm': '_w3d_op_new', '__Znam': '_w3d_op_new', '__ZdlPv': '_w3d_op_delete', '__ZdaPv': '_w3d_op_delete', '__ZdlPvm': '_w3d_op_delete', '__ZdaPvm': '_w3d_op_delete'}
undefine = collections.defaultdict(set)
# Su inicializador lee datos del DOL, que aún no están cargados antes de main: lo sustituye core/native.
NO_HOST_INIT = {'source/matching/game/sol35c11/sol35c11_static_vectors_80141b14.cpp'}
defs = {}                    # dirección -> (fuente, símbolo)
rename_map = {}              # fuente -> {nombre: nuevo}
unresolved_by_src = collections.defaultdict(list)
call_targets = json.load(open(f'{ROOT}/port/docs-data/call-targets.json')) if os.path.exists(f'{ROOT}/port/docs-data/call-targets.json') else {}   # tools/relink/call_targets.py
vtables = json.load(open(f'{ROOT}/port/docs-data/vtables.json'))['resolved']   # tools/relink/vtable_resolve.py
stat = collections.Counter(); unresolved = collections.Counter(); strong_other = collections.Counter(); ref_addr = collections.Counter()
helper_defs = {}
# Clases con la dirección del constructor en el nombre: su destructor no está ahí.
DTOR_HOST = {'__ZN16F7aText_8020bb54D1Ev': '_w3d_f7a_text_destroy'}
for s in srcs:
    res = S.UnitResolver(unit_map(s), glob_map, led_name)
    mine = by_src[s]; mine_members = {}
    for ln, ad in mine.items():
        k = S.parse_gcc2(ln)
        if k: mine_members.setdefault(k, ad)
    m = {}
    for _, n, t, sect, desc, value in syms[s]:
        if not t & 1: continue
        name = n[1:] if n.startswith('_') else n
        mang = n.startswith('__Z')
        key = S.parse_demangled(dem.get(name, '')) if mang else None
        if sect:  # definido
            ad = mine.get(name)
            if ad is None and key: ad = mine_members.get(key)
            if ad is None:
                # Variable de la unidad con sitio en el DOL: la dueña es la imagen, no el objeto.
                da, _h = res.plain(name)
                if da is not None and 0x8035f3e0 <= da < 0x804b3280:
                    m[n] = '_' + S.canon(da); undefine[s].add('_' + S.canon(da)); ref_addr[da] += 1; stat['datos_en_imagen'] += 1
                    continue
                # Ayudante propio de la unidad: fuera del registro y sin chocar con el sistema.
                strong_other[name] += 1
                helper_defs.setdefault(name, []).append(s)
                m[n] = '_U_' + name
                continue
            if ad in overrides:
                m[n] = '_' + S.canon(ad); undefine[s].add('_' + S.canon(ad)); stat['sustituida'] += 1; continue
            if ad in defs and defs[ad] != (s, n):
                m[n] = '_D%08x_%d' % (ad, len(m)); stat['definicion_repetida'] += 1
            else:
                defs[ad] = (s, n); m[n] = '_' + S.canon(ad); stat['definida'] += 1
        else:
            if n in provided: continue
            if n.startswith('___vt_') and n[1:] in vtables.get(s, {}):
                ad = int(vtables[s][n[1:]], 16); m[n] = '_' + S.canon(ad); ref_addr[ad] += 1; stat['tablas_virtuales'] += 1
                continue
            # new y delete de cada unidad: en el original van a montones distintos (por ejemplo el de la IA, 0x8001523c).
            builtin_ = CXX_BUILTIN.get(n)
            if builtin_ and builtin_ in res.u:
                ad = res.u[builtin_]; ref_addr[ad] += 1
                if T3DS:
                    m[n] = '_' + S.canon(ad)
                elif n in ('__Znwm', '__Znam'):
                    t_ = '_' + S.canon(ad)
                    alloc_thunks[(t_, 'new')] = (t_ + '__new', f'  stp x29, x30, [sp, #-16]!\n  mov x29, sp\n  bl {t_}\n  mov w0, w0\n  cbz w0, 1f\n  movk x0, #1, lsl #32\n1:\n  ldp x29, x30, [sp], #16\n  ret')
                    m[n] = t_ + '__new'
                else:
                    m[n] = '_' + S.canon(ad)
                continue
            if n in CXX_RUNTIME:
                m[n] = CXX_RUNTIME[n]; continue
            if n in DTOR_HOST:
                m[n] = DTOR_HOST[n]; stat['destructores_propios'] += 1; continue
            if mang and key: ad, how = res.member(key, S.demangled_arity(dem.get(name, '')))
            elif mang: ad, how = None, 'cxx_sin_forma'
            else: ad, how = res.plain(name)
            stat['ref_' + how] += 1
            if ad is None and n in call_targets.get(s, {}):
                ad = int(call_targets[s][n], 16); how = 'destino_bl'; stat['ref_destino_bl'] += 1
            if ad is None:
                unresolved[n] += 1; unresolved_by_src[s].append(n)
                continue
            m[n] = '_' + S.canon(ad); ref_addr[ad] += 1
    rename_map[s] = m

# Unidades distintas tienen tipos locales con el mismo nombre (Entry, Rec, Ref...) y sus plantillas salen con el mismo
# símbolo y otro tamaño: cada unidad usa las suyas. Si el enlazador las uniera, unas pisarían la memoria de otras.
helper_name = {}
for name, owners in helper_defs.items():
    if len(owners) > 1:
        stat['ayudantes_repetidos'] += 1
        for i, s in enumerate(owners):
            rename_map[s]['_' + name] = '_U%d_%s' % (i, name)
    helper_name[name] = rename_map[owners[0]]['_' + name]

# Referencias sin dirección a ayudantes que otra unidad define.
# En ELF (3DS) clang emite los constructores y destructores inline solo en su variante base (C2/D2) y, dentro de esa
# unidad, cambia las llamadas a la completa (C1/D1) por la base: otra unidad que llama a la completa no la encontraba
# (el teclado del juego, d43l, llamaba a Ref::~Ref y caía en w3d_unresolved_symbol al crear un equipo). Sin bases
# virtuales, que el juego no usa, las dos variantes son la misma función: se enlaza con la base (como hace Mach-O, que
# las emite las dos).
def base_variant(name):
    for k_ in re.finditer(r'[CD]1E', name):
        alt = name[:k_.start() + 1] + '2' + name[k_.start() + 2:]
        if alt in strong_other: return alt
    return None
for s, m in rename_map.items():
    for _, n, t, sect, *_ in syms[s]:
        if t & 1 and not sect and n not in m and n not in provided:
            name = n[1:] if n.startswith('_') else n
            if name in strong_other:
                m[n] = helper_name[name]; stat['ref_ayudante'] += 1
                unresolved.pop(n, None)
            elif T3DS and base_variant(name):
                m[n] = helper_name[base_variant(name)]; stat['ref_ayudante_base'] += 1
                unresolved.pop(n, None)

# Del sistema: el compilador los pide por su cuenta y no son del juego.
HOST_NAMES = ('___stack_chk_fail', '___stack_chk_guard', '___chkstk_darwin', '_abs', '_bzero', '_memset_pattern16', '___bzero', '___cxa_atexit', '_atexit')

# Vistas de ABI: cada objeto llama con la forma que declaró; si difiere de la definición, pasa por un thunk.
def ll_of(s):
    if s.startswith(('build/lua', 'source/vendor/lua-5.0')): return W3DP + '/lua_ll/' + os.path.basename(s).rsplit('.', 1)[0] + '.ll'
    return W3DP + '/ll/' + re.sub(r'[^\w]', '_', s) + '.ll'
if T3DS:
    from ir_inherit import apply as ir_apply
    _ll_base = ll_of; _obj_base = obj_of
    _rw = ir_apply(srcs, rename_map, _ll_base, _obj_base, f'{ROOT}/port/docs-data/inherit-census.json', W3DP, 'armv6k-none-eabihf')
    stat['unidades_reescritas_ir'] = len(_rw); stat['funciones_con_herencia'] = sum(v[2] for v in _rw.values())
    def ll_of(s): return _rw[s][0] if s in _rw else _ll_base(s)
    def obj_of(s): return _rw[s][1] if s in _rw else _obj_base(s)
def_sig = {}; use_sig = {}; libc_sig = {}
for s in srcs:
    p = ll_of(s)
    if not os.path.exists(p): continue
    m = rename_map[s]; us = {}
    for kind, name, sig in ir_signatures(p):
        new = m.get('_' + name)
        if not new or not re.fullmatch(r'_A[0-9a-f]{8}', new): continue
        if kind == 'define': def_sig[new] = sig
        else: us['_' + name] = (new, sig)
    use_sig[s] = us
for p in a.extra_ll:
    for kind, name, sig in ir_signatures(p):
        if kind == 'define' and re.fullmatch(r'A[0-9a-f]{8}', name): def_sig['_' + name] = sig
        elif kind == 'define' and name.startswith('w3d_'): libc_sig[name[4:]] = sig
# libc por dirección: las unidades declaran memcpy(...) para forzar crclr en PPC, y en Apple arm64 eso va por pila.
for ad_, names_ in ((a_, n_) for n_, ads_ in glob_map.items() for a_ in ads_ if 0x802e9eac <= a_ < 0x802f356c for n_ in [n_]):
    if names_ in libc_sig and '_' + S.canon(ad_) not in def_sig: def_sig['_' + S.canon(ad_)] = libc_sig[names_]
# GCC 2.95 deja el primer argumento en r3 en constructores y funciones declaradas void cuyo resultado
# usa el llamador; en arm64 x0 no sobrevive. Esas definiciones pasan por una envoltura que lo conserva.
open_refs = set()
for o in a.extra:
    if os.path.basename(o).startswith('open_'):
        for _, n, t, sect, *_ in read_symbols(o):
            if t & 1 and not sect and re.fullmatch(r'_A[0-9a-f]{8}', n): open_refs.add(n)
void_used = set(open_refs)
for us in use_sig.values():
    for n, (new, sig) in us.items():
        if sig[0] != 'V': void_used.add(new)
# ¿Qué deja r3 una función "void" del original? Se mira su último escritor antes de volver:
# una llamada (reenvía el resultado de esa llamada: x0 ya lo trae) o nada o un mr (conserva o devuelve this).
_dol_all = open(a.data + '/sys/main.dol', 'rb').read()
_offs = struct.unpack_from('>18I', _dol_all, 0); _adrs = struct.unpack_from('>18I', _dol_all, 0x48); _szs = struct.unpack_from('>18I', _dol_all, 0x90)
_bytes = {int(f_['address'], 16): f_['bytes'] for f_ in led['functions']}
def game_word(ad):
    for i_ in range(18):
        if _szs[i_] and _adrs[i_] <= ad < _adrs[i_] + _szs[i_]:
            return struct.unpack_from('>I', _dol_all, _offs[i_] + ad - _adrs[i_])[0]
    return None
def forwards_call_result(ad):
    size = _bytes.get(ad)
    if not size: return False
    for i_ in range(18):
        if _szs[i_] and _adrs[i_] <= ad < _adrs[i_] + _szs[i_]:
            base_ = _offs[i_] + ad - _adrs[i_]; break
    else: return False
    for o_ in range(size - 4, -1, -4):
        w = struct.unpack_from('>I', _dol_all, base_ + o_)[0]
        op = w >> 26
        if w in (0x4e800421, 0x4e800420, 0x4e800021): return True      # bctrl, bctr, blrl
        if op == 18: return True                            # bl, b
        rd_, ra_ = (w >> 21) & 31, (w >> 16) & 31
        if op in (14, 15, 32, 33, 34, 35, 40, 41, 42, 43, 7, 8, 12, 13) and rd_ == 3: return False
        if op in (24, 25, 26, 27, 28, 29, 20, 21, 23) and ra_ == 3: return False
        if op == 31:
            xo = (w >> 1) & 0x3ff
            logical = xo in (444, 28, 60, 124, 284, 316, 412, 476, 536, 792, 824, 922, 954, 24, 26, 0)
            if logical and ra_ == 3: return False
            if not logical and xo not in (0, 32, 40 + 1000) and rd_ == 3 and xo not in (151, 215, 407, 439, 662, 918, 150, 247, 183): return False
    return False
keep_first = {}
for ad, (s_, n_) in defs.items():
    new = '_' + S.canon(ad)
    d = def_sig.get(new)
    if d is None or d[0] != 'V' or new not in void_used: continue
    if d[1] and d[1][0] == 'R': continue  # x0 no es el primer argumento: va por x8.
    if forwards_call_result(ad):
        def_sig[new] = ('L', d[1]); stat['void_reenvia_llamada'] += 1
        continue
    if not [x for x in d[1] if x in 'ILP'] or (not T3DS and len([x for x in d[1] if x in 'ILP']) > 8) or '...' in d[1]: continue
    rename_map[s_][n_] = new + '__d'
    keep_first[new] = arm_keep_first(new + '__d', d[1]) if T3DS else '\n'.join(['  stp x0, x30, [sp, #-16]!', f'  bl {new}__d', '  ldp x0, x30, [sp], #16', '  ret'])
    def_sig[new] = ('L', d[1])
stat['envolturas_primer_argumento'] = len(keep_first)
thunks = dict(alloc_thunks); manual = collections.Counter()
dtor_plus = []
for s, us in use_sig.items():
    for n, (new, sig) in us.items():
        d = def_sig.get(new)
        if d is None or d == sig: continue
        # GCC 2.95 pasa a los destructores una bandera oculta (bit 1: borrar). Clang no la pasa, y x1 llevaría basura.
        if re.search(r'D[12]Ev$', n) and len(d[1]) == len(sig[1]) + 1 and d[1][-1] in 'IL' and len(sig[1]) == 1:
            key = (new, sig, 'dtor')
            if key not in thunks:
                fix = '  mov w0, w0\n  cbz w0, 1f\n  movk x0, #1, lsl #32\n1:\n' if d[1][0] == 'P' and not T3DS else ''
                thunks[key] = (f'{new}__t{len(thunks)}', '  mov r1, #2\n  b ' + new if T3DS else f'{fix}  mov w1, #2\n  b {new}')
            rename_map[s][n] = thunks[key][0]; stat['destructores_con_bandera'] += 1
            continue
        # v39: lo mismo cuando la definición, además de la bandera, hereda más argumentos (los pasa tal cual a otra
        # función): antes solo se reponían las palabras de pila y r1 llegaba con lo que hubiera. Fallo de la consola con la
        # v38 al salir de la partida: ~G5aActorOwner destruye su miembro en +0x14c (A8020803c) con r1 impar, el destructor
        # del miembro hace operator delete de un puntero interior y free() lee como cabecera lo que haya delante (en
        # español, texto: tamaño 0x6e617374 y excepción). En arm64 los ocho primeros van en registros: basta el mov.
        if re.search(r'D[12]Ev$', n) and len(sig[1]) == 1 and len(d[1]) > 2 and d[1][1] in 'IL' and not any(x in ('S', 'A', '...') for x in d[1]):
            key = (new, sig, 'dtor+')
            if key not in thunks:
                if T3DS:
                    from thunks_arm import stack_words as _sw, inherit_call as _ic
                    dk_ = _sw(d[1])
                    body_ = '  mov r1, #2\n' + (_ic(new, 0, dk_) if dk_ else '  b ' + new)
                else:
                    fix = '  mov w0, w0\n  cbz w0, 1f\n  movk x0, #1, lsl #32\n1:\n' if d[1][0] == 'P' else ''
                    body_ = f'{fix}  mov w1, #2\n  b {new}'
                thunks[key] = (f'{new}__t{len(thunks)}', body_)
            rename_map[s][n] = thunks[key][0]; stat['destructores_con_bandera_y_herencia'] += 1
            dtor_plus.append(f'{n} -> {new} {d[1]}')
            continue
        body = thunk_body(sig, d, new)
        if body is None: continue
        if body == 'manual': manual[new] += 1; continue
        key = (new, sig)
        if key not in thunks: thunks[key] = (f'{new}__t{len(thunks)}', body)
        rename_map[s][n] = thunks[key][0]
# ARM: los argumentos 5 a 8 van en pila. En PPC y arm64 una función puente que no los declara los hereda en sus registros, y
# aquí su marco los esconde. Las definiciones que reciben más pila de la que declaran guardan esas palabras en w3d_inh al
# entrar, y las llamadas que pasan menos de lo que la definición espera las reponen desde ahí.
inh_save = set()
if T3DS:
    from thunks_arm import stack_words, inherit_call, inherit_entry
    def _plain(p): return not any(x in ('S', 'A', '...') for x in p)
    _ll_cache = {}
    def _only_called(s, name):
        # El thunk es para llamadas: si se toma la dirección de la función, debe seguir siendo la real.
        t = _ll_cache.get(s)
        if t is None: t = _ll_cache[s] = open(ll_of(s), errors='replace').read()
        e = re.escape(name)
        if re.search(r'(?:ptr|i32|,)\s+(?:noundef\s+)?@"?' + e + r'"?\b(?!\()', t): return False
        return re.search(r'call [^\n]*@"?' + e + r'"?\(', t) is not None
    for s, us in use_sig.items():
        for n, (new, sig) in us.items():
            d = def_sig.get(new)
            if d is None or not _plain(sig[1]) or not _plain(d[1]): continue
            uk, dk = stack_words(sig[1]), stack_words(d[1])
            if uk > dk: inh_save.add(new)
            elif dk > uk and rename_map[s].get(n) == new and _only_called(s, n[1:]):
                key = (new, sig, 'inh')
                if key not in thunks: thunks[key] = (f'{new}__t{len(thunks)}', inherit_call(new, uk, dk))
                rename_map[s][n] = thunks[key][0]; stat['llamadas_con_herencia_en_pila'] += 1
    for new in sorted(inh_save):
        ad_ = int(new[2:], 16)
        if ad_ not in defs: continue
        s_, n_ = defs[ad_]
        if new in keep_first:
            keep_first[new + '__k'] = keep_first.pop(new)
            keep_first[new] = inherit_entry(new + '__k')
        else:
            rename_map[s_][n_] = new + '__s'
            keep_first[new] = inherit_entry(new + '__s')
    stat['entradas_que_guardan_pila'] = len(inh_save)
stat['thunks'] = len(thunks); stat['abi_manual_addresses'] = len(manual)
if dtor_plus:
    print(f'destructores con bandera y herencia: {len(dtor_plus)}')
    for x_ in sorted(set(dtor_plus)): print('   ', x_)
# Punteros a función en los datos: el llamador pasa todo en la forma de 32 bits.
fn_view = {}
for new, d in def_sig.items():
    if not T3DS and ('P' in d[1] or d[0] == 'P'):
        as_int = ('L' if d[0] == 'P' else d[0], tuple('L' if x == 'P' else x for x in d[1]))
        body = thunk_body(as_int, d, new)
        if body and body != 'manual': fn_view[new] = (new + '__v', body)

# Direcciones que pide el código de plataforma y el nativo.
for o in a.extra:
    for _, n, t, sect, *_ in read_symbols(o):
        if t & 1 and not sect and re.fullmatch(r'_A[0-9a-f]{8}', n): ref_addr[int(n[2:], 16)] += 1

DATA_LO, DATA_HI = 0x8035f3e0, 0x804b3280
LOW_LO, LOW_HI = 0x80000000, 0x80003100
provided_addr = {int(n[2:], 16) for n in provided if re.fullmatch(r'_A[0-9a-f]{8}', n)}
data_refs = sorted(x for x in ref_addr if DATA_LO <= x < DATA_HI)
low_refs = sorted(x for x in ref_addr if LOW_LO <= x < LOW_HI)
high_refs = sorted(x for x in ref_addr if x >= DATA_HI or x < LOW_LO)
text_refs = sorted(x for x in ref_addr if LOW_HI <= x < DATA_LO)

# DOL del usuario: solo para decidir qué palabras son punteros y la disposición. No se copia nada.
dol = open(a.data + '/sys/main.dol', 'rb').read()
offs = struct.unpack_from('>18I', dol, 0); addrs = struct.unpack_from('>18I', dol, 0x48); sizes = struct.unpack_from('>18I', dol, 0x90)
secs = [(addrs[i], offs[i], sizes[i]) for i in range(18) if sizes[i]]
access = json.load(open(f'{ROOT}/port/docs-data/data-access.json'))
RAW, WORD, HALF, DBL, FLT = 0, 1, 2, 3, 4
layout_ex = json.load(open(f'{ROOT}/port/core/data/layout_exceptions.json'))
# Primero lo declarado en las unidades y por último las excepciones escritas a mano, que mandan.
if os.path.exists(f'{ROOT}/port/core/data/layout_types.json'):
    layout_ex = [x for x in json.load(open(f'{ROOT}/port/core/data/layout_types.json')) if x['kind'] != 'word'] + layout_ex
PRINT = set(range(32, 127)) | {9, 10, 13}
all_labels = sorted({int(k, 16) for k in access} | set(data_refs))
import bisect
fn_starts = set(int(x, 16) for x in (json.loads(l)['address'] for l in open(f'{ROOT}/source/recovered/refined/functions.jsonl')))
layout = []; pointer_targets = set(); short_strings = []
data_word_targets = set()
for sa, so, sz in secs:
    if DATA_LO <= sa < DATA_HI:
        data_word_targets |= {w for w in struct.unpack_from('>%dI' % (sz // 4), dol, so) if DATA_LO <= w < DATA_HI and not w & 3}
for sa, so, sz in secs:
    if not (DATA_LO <= sa < DATA_HI): continue
    blob = dol[so:so + sz]
    kind = bytearray([WORD]) * sz
    # Cadenas: tramos imprimibles terminados en NUL.
    i = 0
    while i < sz:
        if blob[i] in PRINT:
            j = i
            while j < sz and blob[j] in PRINT: j += 1
            if j < sz and blob[j] == 0 and j - i >= 4:
                e = j + 1
                while e < sz and e % 4 and blob[e] == 0: e += 1
                for q in range(i, e): kind[q] = RAW
                i = e; continue
            i = j
        i += 1
    # Cadenas de menos de 4 letras ("512", "64", "%d"): solas no se distinguen de un entero, así que hacen falta
    # pruebas: estar pegadas a otra cadena, o ser una etiqueta de la que solo se toma la dirección y que no da
    # sitio a nada más. Los flotantes frecuentes (0.5, 2.0, 8.0) empiezan por ?, @ o A y no valen por la segunda vía.
    loaded = set()
    for lab in all_labels:
        if sa <= lab < sa + sz and set(access.get('0x%08x' % lab, {})) - {'addr'}: loaded.add(lab - sa)
    def short_str(o):
        w = blob[o:o + 4]
        n = w.find(0)
        return len(w) == 4 and 1 <= n <= 3 and all(c in PRINT for c in w[:n]) and not any(w[n:])
    changed = True
    while changed:
        changed = False
        for o in range(0, sz - 3, 4):
            if kind[o] == WORD and o not in loaded and short_str(o) and ((o and kind[o - 1] == RAW) or (o + 4 < sz and kind[o + 4] == RAW)):
                kind[o:o + 4] = bytes([RAW]) * 4
                short_strings.append(sa + o); changed = True
    for lab in all_labels:
        o = lab - sa
        if not (0 <= o < sz - 3) or o % 4 or o in loaded or kind[o] != WORD or not short_str(o) or 0x3c <= blob[o] <= 0x4f: continue
        ni = bisect.bisect_right(all_labels, lab)
        if (all_labels[ni] if ni < len(all_labels) else sa + sz) - lab <= 8:
            kind[o:o + 4] = bytes([RAW]) * 4
            short_strings.append(lab)
    # Tercera vía: una palabra de datos apunta a ella (el nombre de una propiedad, como "Uzi"). Solo letras y números.
    for o in range(0, sz - 3, 4):
        if kind[o] != WORD or o in loaded or not short_str(o) or (sa + o) not in data_word_targets: continue
        n = blob[o:o + 4].find(0)
        if all(chr(c).isalnum() or c in b'._' for c in blob[o:o + n]):
            kind[o:o + 4] = bytes([RAW]) * 4
            short_strings.append(sa + o)
    # Accesos directos: lo que el código hace con cada dirección manda sobre lo anterior.
    def inside_long_text(o):
        # Un registro reutilizado da accesos falsos en mitad de una cadena larga. Convertirlos gira el texto: "Weapon.CtaereGraphic".
        if not (0 < o < sz and blob[o - 1] in PRINT and blob[o] in PRINT): return False
        lo, hi = o, o
        while lo > 0 and blob[lo - 1] in PRINT: lo -= 1
        while hi < sz and blob[hi] in PRINT: hi += 1
        return hi < sz and blob[hi] == 0 and hi - lo >= 8
    for lab in all_labels:
        if not (sa <= lab < sa + sz): continue
        acc = access.get('0x%08x' % lab, {})
        ni = bisect.bisect_right(all_labels, lab)
        nxt = min(all_labels[ni] if ni < len(all_labels) else sa + sz, sa + sz)
        o = lab - sa
        if inside_long_text(o): continue
        if 'lfd' in acc or 'stfd' in acc:
            for q in range(o, min(o + 8, sz)): kind[q] = DBL
        elif 'lfs' in acc or 'stfs' in acc:
            for q in range(o, min(o + 4, sz)): kind[q] = FLT
        elif ('lhz' in acc or 'lha' in acc or 'sth' in acc) and not ('lwz' in acc or 'stw' in acc):
            for q in range(o, nxt - sa): kind[q] = HALF
        elif ('lbz' in acc or 'stb' in acc) and not ('lwz' in acc or 'stw' in acc):
            for q in range(o, nxt - sa): kind[q] = RAW
    # Una etiqueta declarada char[] deja crudo solo su primer byte: la palabra es del tramo que sigue.
    for o in range(0, sz - 3, 4):
        if (sa + o) % 4 == 0 and kind[o] == RAW and kind[o + 1] != RAW and kind[o + 1] == kind[o + 2] == kind[o + 3]:
            kind[o] = kind[o + 1]
    # Una etiqueta leída solo con lhz o lbz marca todo su tramo, y a veces es solo la base de un lis. Si la palabra es una dirección válida es un puntero.
    for o in range(0, sz - 3, 4):
        if kind[o] in (RAW, HALF) and (sa + o) % 4 == 0:
            v = struct.unpack_from('>I', blob, o)[0]
            if DATA_LO <= v < DATA_HI or v in fn_starts: kind[o:o + 4] = bytes([WORD]) * 4
    for ex_ in layout_ex:
        a_ = int(ex_['addr'], 16)
        if sa <= a_ < sa + sz:
            for q in range(a_ - sa, min(a_ - sa + ex_['size'], sz)): kind[q] = {'raw': RAW, 'word': WORD, 'half': HALF, 'double': DBL, 'float': FLT}[ex_['kind']]
    # Un lhz falso sobre una etiqueta deja texto como medias palabras, y el texto sale girado: "EalspdeoRnuTdmi" hacía fallar toda búsqueda de ElapsedRoundTime.
    for m_ in re.finditer(rb'[\x20-\x7e]{5,}(?=\x00)', blob):
        if re.search(rb'[A-Za-z]{3}', m_.group()) and HALF in kind[m_.start():m_.end()]:
            for q in range(m_.start() & ~1, m_.end() + 1): kind[q] = RAW
    # Una palabra a medias entre char y palabra cuyo valor es una dirección válida es un puntero.
    for o in range(0, sz - 3, 4):
        if len(set(kind[o:o + 4])) > 1 and RAW in kind[o:o + 4]:
            v = struct.unpack_from('>I', blob, o)[0]
            if DATA_LO <= v < DATA_HI or v in fn_starts: kind[o:o + 4] = bytes([WORD]) * 4
    i = 0
    while i < sz:
        j = i
        while j < sz and kind[j] == kind[i]: j += 1
        layout.append((sa + i, j - i, kind[i]))
        i = j
    for o in range(0, sz - 3, 4):
        if kind[o] == WORD:
            v = struct.unpack_from('>I', blob, o)[0]
            if LOW_HI <= v < DATA_LO and v in fn_starts: pointer_targets.add(v)

# Ensamblador generado.
def E(n): return n[1:] if T3DS and n.startswith('_') else n   # ELF no lleva el '_' de Mach-O.
SEC_IMG, SEC_LOW, SEC_HIGH = ('.section .bss.w3ddol,"aw",%nobits\n.p2align 12', '.section .bss.w3dlow,"aw",%nobits\n.p2align 12', '.section .bss.w3dhigh,"aw",%nobits\n.p2align 4') if T3DS else ('.section __DATA,__w3ddol\n.p2align 16', '.section __DATA,__w3dlow\n.p2align 12', '.section __DATA,__w3dhigh\n.p2align 4')
with open(L + '/gen_image.s', 'w') as f:
    f.write(f'{SEC_IMG}\n.globl {E("_w3d_dol_image")}\n{E("_w3d_dol_image")}:\n')
    cur = DATA_LO
    for x in data_refs:
        if x != cur: f.write(f'.space {x - cur}\n')
        f.write(f'.globl {E("_" + S.canon(x))}\n{E("_" + S.canon(x))}:\n'); cur = x
    f.write(f'.space {DATA_HI - cur}\n')
    f.write(f'{SEC_LOW}\n.globl {E("_w3d_low_image")}\n{E("_w3d_low_image")}:\n')
    cur = LOW_LO
    for x in low_refs:
        if x != cur: f.write(f'.space {x - cur}\n')
        f.write(f'.globl {E("_" + S.canon(x))}\n{E("_" + S.canon(x))}:\n'); cur = x
    f.write(f'.space {LOW_HI - cur}\n')
    f.write(f'{SEC_HIGH}\n')
    for x in high_refs:
        f.write(f'.globl {E("_" + S.canon(x))}\n{E("_" + S.canon(x))}:\n.space 64\n')

libc_names = {n[len('_w3d_'):]: n for n in provided if n.startswith('_w3d_')}
stubs = {}; aliases = {}
# Ajustes de this de las tablas virtuales: restan N y saltan a la función real.
this_thunks = {}
for f_ in led['functions']:
    m_ = re.match(r'__thunk_(\d+)_.*?_?(80[0-9a-f]{6})__', f_.get('name') or '')
    if m_: this_thunks[int(f_['address'], 16)] = (int(m_.group(1)), int(m_.group(2), 16))
need_text = set(text_refs) | pointer_targets | {t_ for _, t_ in this_thunks.values()}
for x in sorted(need_text):
    if x in defs or x in provided_addr: continue
    z = S.where(x)
    target = None
    if z in ('libm', 'newlib', 'libgcc'):
        for nm in glob_map:
            pass
    stubs[x] = target
# Nombres de libc por dirección.
addr_names = collections.defaultdict(set)
for n, ads in glob_map.items():
    for ad in ads: addr_names[ad].add(n)
if T3DS:
  with open(L + '/gen_stubs.s', 'w') as f:
    f.write('.arch armv6k\n.fpu vfpv2\n.arm\n.bss\n.p2align 2\n.globl w3d_inh\nw3d_inh:\n.space 16\n.text\n.p2align 2\n')
    f.write('w3d_missing_function:\n  mov r0, ip\n  mov r1, lr\n  b w3d_report_missing\n')
    f.write('w3d_unresolved_symbol:\n  mov r0, ip\n  mov r1, lr\n  b w3d_report_unresolved\n')
    aliased = 0
    for x in sorted(stubs):
        cand = [n for n in addr_names.get(x, ()) if n in libc_names]
        f.write(f'.globl {S.canon(x)}\n{S.canon(x)}:\n')
        if x in this_thunks:
            n_, t_ = this_thunks[x]
            f.write(f'  ldr ip, =#{n_}\n  sub r0, r0, ip\n  b {S.canon(t_)}\n  .ltorg\n')
            continue
        if S.where(x) == 'game_text' and game_word(x) == 0x4e800020:
            f.write('  bx lr\n'); stat['stubs_vacios'] += 1
            continue
        if cand and S.where(x) in ('libm', 'newlib', 'libgcc'):
            f.write(f'  b {E(libc_names[cand[0]])}\n'); aliased += 1
        else:
            f.write(f'  ldr ip, =0x{x:08x}\n  b w3d_missing_function\n  .ltorg\n')
    for name, body in keep_first.items():
        f.write(f'.globl {E(name)}\n{E(name)}:\n{re.sub(r"_(A[0-9a-f]{8})", r"\1", body)}\n  .ltorg\n')
    for name, body in thunks.values():
        f.write(f'.globl {E(name)}\n{E(name)}:\n{re.sub(r"_(A[0-9a-f]{8})", r"\1", body)}\n  .ltorg\n')
    for n in set(HOST_NAMES) | {'_abs', '_fmod', '_atan2', '_pow', '_ldexp', '___cxa_guard_acquire', '___cxa_guard_release', '___dso_handle', '___aeabi_memcpy', '___aeabi_memset', '___aeabi_memclr', '___aeabi_memmove', '___aeabi_memcpy4', '___aeabi_memclr4', '___aeabi_memset4', '___aeabi_memmove4', '___aeabi_memcpy8', '___aeabi_memclr8', '___aeabi_memset8', '___aeabi_memmove8', '___aeabi_idiv', '___aeabi_uidiv', '___aeabi_idivmod', '___aeabi_uidivmod', '___aeabi_ldivmod', '___aeabi_uldivmod', '___aeabi_llsl', '___aeabi_llsr', '___aeabi_lasr', '___aeabi_lmul', '___aeabi_d2lz', '___aeabi_d2ulz', '___aeabi_f2lz', '___aeabi_f2ulz', '___aeabi_l2d', '___aeabi_ul2d', '___aeabi_l2f', '___aeabi_ul2f', '___aeabi_unwind_cpp_pr0', '___aeabi_unwind_cpp_pr1', '___cxa_pure_virtual'}: unresolved.pop(n, None)
    for n in list(unresolved):
        if n.startswith('___aeabi') or n.startswith('___clz') or n.startswith('___gnu'): unresolved.pop(n)
    unresolved.pop('_w3d_low_image', None)
    missing_vt = [n for n in unresolved if n.startswith('___vt_')]
    for n in missing_vt:
        unresolved.pop(n, None); f.write(f'.weak {E(n)}\n.set {E(n)}, 0\n')
    for i, n in enumerate(sorted(unresolved)):
        f.write(f'.globl {E(n)}\n{E(n)}:\n  ldr ip, =#{i}\n  b w3d_unresolved_symbol\n  .ltorg\n')
  stat['stubs'] = len(stubs); stat['stubs_libc'] = aliased; stat['stubs_sin_direccion'] = len(unresolved)
  with open(L + '/gen_tables.s', 'w') as f:
    f.write('.section .rodata.w3dtab,"a"\n.p2align 3\n.globl w3d_fn_table\nw3d_fn_table:\n')
    tbl = sorted({x for x in (need_text | set(defs) | provided_addr) if LOW_HI <= x < DATA_LO})
    for x in tbl: f.write(f'.long {x}, 0, {S.canon(x)}\n')
    f.write(f'.globl w3d_fn_table_count\nw3d_fn_table_count:\n.long {len(tbl)}\n')
    f.write('.globl w3d_layout\nw3d_layout:\n')
    for ad, n, k in layout: f.write(f'.long {ad}, {n}, {k}\n')
    f.write(f'.globl w3d_layout_count\nw3d_layout_count:\n.long {len(layout)}\n')
    f.write('.globl w3d_unresolved_names\nw3d_unresolved_names:\n')
    for n in sorted(unresolved): f.write(f'.asciz "{n}"\n')
    f.write('.byte 0\n.p2align 2\n')
else:
  with open(L + '/gen_stubs.s', 'w') as f:
      f.write('.text\n.p2align 2\n')
      f.write('_w3d_missing_function:\n  mov w0, w16\n  mov x1, x30\n  b _w3d_report_missing\n')
      f.write('_w3d_unresolved_symbol:\n  mov w0, w16\n  mov x1, x30\n  b _w3d_report_unresolved\n')
      aliased = 0
      for x in sorted(stubs):
          cand = [n for n in addr_names.get(x, ()) if n in libc_names]
          f.write(f'.globl _{S.canon(x)}\n_{S.canon(x)}:\n')
          if x in this_thunks:
              n_, t_ = this_thunks[x]
              ref_ = '_' + S.canon(t_)
              f.write(f'  sub w0, w0, #{n_}\n  b {fn_view[ref_][0] if ref_ in fn_view else ref_}\n')
              continue
          # Sin fuente pero sin cuerpo: un blr del juego deja los registros intactos.
          if S.where(x) == 'game_text' and game_word(x) == 0x4e800020:
              f.write('  ret\n'); stat['stubs_vacios'] += 1
              continue
          if cand and S.where(x) in ('libm', 'newlib', 'libgcc'):
              f.write(f'  b {libc_names[cand[0]]}\n'); aliased += 1
          else:
              f.write(f'  movz w16, #{x & 0xffff}\n  movk w16, #{x >> 16}, lsl #16\n  b _w3d_missing_function\n')
      for name, body in keep_first.items():
          f.write(f'.globl {name}\n{name}:\n{body}\n')
      for name, body in list(thunks.values()) + list(fn_view.values()):
          f.write(f'.globl {name}\n{name}:\n{body}\n')
      for n in set(HOST_NAMES) | {'_abs', '_fmod', '_atan2', '_pow', '_ldexp', '___chkstk_darwin', '___cxa_guard_acquire', '___cxa_guard_release', '___dso_handle'}: unresolved.pop(n, None)
      missing_vt = [n for n in unresolved if n.startswith('___vt_')]
      for n in missing_vt: unresolved.pop(n, None)
      for i, n in enumerate(sorted(unresolved)):
          f.write(f'.globl {n}\n{n}:\n  movz w16, #{i}\n  b _w3d_unresolved_symbol\n')
  stat['stubs'] = len(stubs); stat['stubs_libc'] = aliased; stat['stubs_sin_direccion'] = len(unresolved)
  with open(L + '/gen_tables.s', 'w') as f:
      f.write('.section __DATA,__const\n.p2align 3\n.globl _w3d_fn_table\n_w3d_fn_table:\n')
      for name, _ in fn_view.values(): f.write(f'.globl {name}\n')
      tbl = sorted((need_text | set(defs) | provided_addr) & set(range(LOW_HI, DATA_LO)) if False else {x for x in (need_text | set(defs) | provided_addr) if LOW_HI <= x < DATA_LO})
      for x in tbl:
          c_ = '_' + S.canon(x)
          f.write(f'.long {x}, 0\n.quad {fn_view[c_][0] if c_ in fn_view else c_}\n')
      f.write(f'.globl _w3d_fn_table_count\n_w3d_fn_table_count:\n.long {len(tbl)}\n.p2align 3\n')
      f.write('.globl _w3d_layout\n_w3d_layout:\n')
      for ad, n, k in layout: f.write(f'.long {ad}, {n}, {k}\n')
      f.write(f'.globl _w3d_layout_count\n_w3d_layout_count:\n.long {len(layout)}\n')
      f.write('.p2align 3\n.globl _w3d_unresolved_names\n_w3d_unresolved_names:\n')
      for n in sorted(unresolved): f.write(f'.asciz "{n}"\n')
      f.write('.byte 0\n')

json.dump(rename_map, open(L + '/rename.json', 'w'))
json.dump(unresolved_by_src, open(L + '/unresolved-by-src.json', 'w'))
# Objetos renombrados y enlace.
outs = []
def do(s):
    o = f'{L}/objs/' + os.path.basename(obj_of(s))
    rename(obj_of(s), o, rename_map[s], undefine.get(s, ()), keep_init=s not in NO_HOST_INIT); return o
with cf.ThreadPoolExecutor(12) as ex: outs = list(ex.map(do, srcs))
open(L + '/objs.txt', 'w').write('\n'.join(outs) + '\n')
gen = []
if T3DS:
    for g in ('gen_image', 'gen_stubs', 'gen_tables'):
        subprocess.check_call([ARM_BIN + 'as', '-march=armv6k', '-mfloat-abi=hard', '-mfpu=vfpv2', f'{L}/{g}.s', '-o', f'{L}/{g}.o'])
        gen.append(f'{L}/{g}.o')
    open(L + '/objs_rsp.txt', 'w').write('\n'.join(gen + outs + list(a.extra)) + '\n')
    cmd = [os.environ['W3D_ELF_LINK'], L + '/objs_rsp.txt', a.out]
else:
    for g in ('gen_image', 'gen_stubs', 'gen_tables'):
        subprocess.check_call(['clang', '-target', 'arm64-apple-macos27', '-c', f'{L}/{g}.s', '-o', f'{L}/{g}.o'])
        gen.append(f'{L}/{g}.o')
    cmd = ['clang++', '-target', 'arm64-apple-macos27', '-filelist', L + '/objs.txt'] + gen + a.extra + [f'-Wl,-U,{n}' for n in missing_vt] + ['-L/opt/homebrew/lib', '-lSDL3', '-framework', 'AppKit', '-framework', 'Metal', '-framework', 'QuartzCore', '-framework', 'Foundation', '-Wl,-rpath,/opt/homebrew/lib', '-Wl,-w', '-o', a.out]
r = subprocess.run(cmd, capture_output=True, text=True, errors='replace')
und = re.findall(r"undefined reference to [`']([^']+)'", r.stderr) if T3DS else re.findall(r'"([^"]+)", referenced from', r.stderr)
dup = re.findall(r"multiple definition of [`']([^']+)'", r.stderr) if T3DS else re.findall(r"duplicate symbol '([^']+)'", r.stderr)
if not T3DS: json.dump([hex(x) for x in sorted(short_strings)], open(f'{ROOT}/port/docs-data/short-strings.json', 'w'))
report = dict(objects=len(srcs), stat=stat, data_labels=len(data_refs), low_labels=low_refs[:60], high_labels=[hex(x) for x in high_refs[:40]], text_refs=len(text_refs), pointer_targets=len(pointer_targets), stubs_by_zone=collections.Counter(S.where(x) for x in stubs), layout_runs=len(layout), link_rc=r.returncode, undefined=len(und), duplicates=len(dup), unresolved_top=unresolved.most_common(60), strong_other=len(strong_other))
report['stubs_game_text'] = sorted(hex(x) for x in stubs if S.where(x) == 'game_text')
_gt = [x for x in stubs if S.where(x) == 'game_text']
report['stubs_game_text_clases'] = dict(ajuste_this=sum(x in this_thunks for x in _gt), blr_original=sum(x not in this_thunks and game_word(x) == 0x4e800020 for x in _gt),
    abortan=sorted(hex(x) for x in _gt if x not in this_thunks and game_word(x) != 0x4e800020))
json.dump(report, open(W3DP + '/link-report-3ds.json' if T3DS else f'{ROOT}/port/docs-data/link-report.json', 'w'), indent=1, default=str)
for k, v in report.items():
    if k not in ('unresolved_top', 'stubs_game_text', 'stubs_game_text_clases', 'low_labels', 'high_labels'): print(k, v)
print(r.stderr[:1500] if r.returncode else 'ENLAZADO: ' + a.out)
print('sin dirección', unresolved.most_common(20))
print('sin definir', und[:30]); print('duplicados', dup[:30])

sys.exit(r.returncode)
