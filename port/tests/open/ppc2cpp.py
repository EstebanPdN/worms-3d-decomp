#!/usr/bin/env python3
"""Traduce a C++ del anfitrión las funciones del juego sin fuente admitida, instrucción a instrucción desde los bytes PPC.

No es un emulador: cada función PPC pasa a una función C++ con registros locales, goto y memoria de la ventana de 32 bits.
La memoria es little-endian, así que las cargas de 1/2/4/8 B son directas. Excepción: los dobles en la pila (stfd/lfd con base
r1) se guardan con la palabra alta primero, porque GCC 2.95 construye dobles con stw+stw+lfd y lee fctiwz con stfd+lwz.

Uso: ppc2cpp.py port/core/open port/tests/open/ppc2cpp-sigs.json ; luego make_open_json.py (pasos desc y json).
"""
import bisect, collections, json, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ppc_decode import decode, I

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../..'))
DATA_LO, DATA_HI = 0x8035f3e0, 0x804b3280
TEXT_LO, TEXT_HI = 0x80003100, 0x8035f3e0
LOW_LO, LOW_HI = 0x80000000, 0x80003100
R13 = 0x804b2540; R2 = 0x804c2540
SAVEGPR = (0x803412b0, 0x80341348)
# Tablas de bytes que la disposición inferida trata como palabras: al cargar quedan con el orden invertido en cada palabra.
# Si el cargador añade una excepción para ellas, hay que vaciar esta lista y regenerar.
SWAPPED_BYTE_TABLES = [(0x803db448, 264)]
INTS = ['r%d' % x for x in range(3, 11)]
FLTS = ['f%d' % x for x in range(1, 9)]
VOLATILE = ['r0'] + ['r%d' % x for x in range(3, 13)] + ['f%d' % x for x in range(0, 14)]
# Sin retorno en el original.
NORETURN = {0x802ed984, 0x802fb82c, 0x802fc330}

dol = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
BYVALUE_CALLEE = {'A8003591c': 'r29', 'A800fbd48': 'r23', 'A80206058': 'r27', 'A802622fc': 'r28', 'A8028496c': 'r30'}
def word(a): return struct.unpack_from('>I', dol, a - 0x80003100 + 0x100)[0]


class W(Exception): pass


class Fn:
    def __init__(self, entry, name='', cat=''):
        self.entry = entry; self.name = name; self.cat = cat
        self.ins = {}; self.labels = set(); self.warn = []; self.notes = []
        self.ret = 'I'; self.pi = 0; self.pf = 0; self.stack_params = 0; self.frame = 0
        self.tails = set(); self.calls = set(); self.dead = 0; self.fallin = {}; self.trapafter = set()
        self.state = {}; self.elide = set(); self.ret_ev = set(); self.dbl_slots = set(); self.addr_slots = set(); self.param_uses = set()
        self.ppf = 0; self.live_after = {}; self.precise_after = {}; self.dbl = False; self.split = set()


def build(fn, starts):
    work = [fn.entry]
    while work:
        a = work.pop()
        if a in fn.ins: continue
        if not (TEXT_LO <= a < TEXT_HI): fn.warn.append('flujo fuera del texto %x' % a); continue
        i = decode(a, word(a))
        fn.ins[a] = i
        nxt = a + 4
        def fall():
            if nxt in starts and nxt != fn.entry and nxt not in fn.ins:
                if (i.op == 'b' and i.lk) or (i.op in ('bclr', 'bcctr') and i.lk):
                    fn.trapafter.add(a); fn.notes.append('sin retorno tras la llamada de %x' % a)
                else:
                    fn.fallin[a] = nxt; fn.warn.append('cae en la funcion %x desde %x' % (nxt, a)); fn.tails.add(nxt)
            else:
                work.append(nxt)
        if i.op == 'b':
            if i.lk:
                fn.calls.add(i.target)
                fall()
            else:
                if i.target in starts and i.target != fn.entry: fn.tails.add(i.target)
                else: fn.labels.add(i.target); work.append(i.target)
        elif i.op == 'bc':
            if i.lk: raise W('bcl')
            if i.target in starts and i.target != fn.entry: fn.tails.add(i.target)
            else: fn.labels.add(i.target); work.append(i.target)
            if (i.bo & 20) != 20: fall()
        elif i.op == 'bclr':
            if i.lk: fall()
            elif (i.bo & 20) != 20: fall()
        elif i.op == 'bcctr':
            if i.lk: fall()
            else: raise W('bctr en %x' % a)
        elif i.op == 'rfi': pass
        else: fall()


# --- Propagación de constantes, pila y valores iniciales ---
def transfer(i, s, fn):
    """s: registro -> ('c',K) constante, ('s',k) pila relativa a r1 de entrada, ('i',reg) valor inicial no volátil, ('L',) LR."""
    s = dict(s); op = i.op; g = s.get
    def setr(n, v):
        if v is None: s.pop(n, None)
        else: s[n] = v
    if op in ('addi', 'addis'):
        imm = i.imm << 16 if op == 'addis' else i.imm
        if i.ra == 0: setr('r%d' % i.d, ('c', imm & 0xffffffff))
        else:
            v = g('r%d' % i.ra)
            if v and v[0] == 'c': setr('r%d' % i.d, ('c', (v[1] + imm) & 0xffffffff))
            elif v and v[0] == 's': setr('r%d' % i.d, ('s', v[1] + imm))
            else: setr('r%d' % i.d, None)
    elif op in ('ori', 'oris', 'xori', 'xoris'):
        v = g('r%d' % i.d); imm = i.imm << 16 if op.endswith('s') else i.imm
        if v and v[0] == 'c': setr('r%d' % i.ra, ('c', (v[1] | imm) if op[0] == 'o' else (v[1] ^ imm)))
        elif imm == 0 and v: setr('r%d' % i.ra, v)
        else: setr('r%d' % i.ra, None)
    elif op == 'or' and i.d == i.rb:  # mr
        v = g('r%d' % i.d); setr('r%d' % i.ra, v)
        if i.rc: pass
    elif op == 'fmr' :
        v = g('f%d' % i.rb); setr('f%d' % i.d, v)
    elif op == 'add':
        a, b = g('r%d' % i.ra), g('r%d' % i.rb)
        if a and b and a[0] == 'c' and b[0] == 'c': setr('r%d' % i.d, ('c', (a[1] + b[1]) & 0xffffffff))
        elif a and b and a[0] == 's' and b[0] == 'c': setr('r%d' % i.d, ('s', a[1] + (b[1] if b[1] < 0x80000000 else b[1] - 0x100000000)))
        elif a and b and a[0] == 'c' and b[0] == 's': setr('r%d' % i.d, ('s', b[1] + (a[1] if a[1] < 0x80000000 else a[1] - 0x100000000)))
        else: setr('r%d' % i.d, None)
    elif op == 'mfspr' and i.imm == 8: setr('r%d' % i.d, g('lr'))
    elif op == 'mtspr' and i.imm == 8: setr('lr', g('r%d' % i.d))
    elif op == 'mem' and i.upd:
        v = g('r%d' % i.ra)
        if i.load: setr(('f%d' if i.fp else 'r%d') % i.d, None)
        if v and v[0] == 's': setr('r%d' % i.ra, ('s', v[1] + i.imm))
        elif v and v[0] == 'c': setr('r%d' % i.ra, ('c', (v[1] + i.imm) & 0xffffffff))
        else: setr('r%d' % i.ra, None)
    elif op == 'mem' and i.load:
        v = g('r%d' % i.ra)
        n = ('f%d' if i.fp else 'r%d') % i.d
        if v and v[0] == 's' and v[1] + i.imm == 4 and not i.fp and i.sz == 4: setr(n, ('L',))
        else: setr(n, None)
    elif op == 'lmw':
        for x in range(i.d, 32): s.pop('r%d' % x, None)
    elif op == 'b' and i.lk or op == 'bclr' and i.lk or op == 'bcctr' and i.lk:
        for x in VOLATILE: s.pop(x, None)
        s.pop('lr', None)
    else:
        for d in i.defs:
            if d[0] in 'rf' and d != 'r1': s.pop(d, None)
            elif d == 'r1': s.pop(d, None)
    return s


def merge(a, b):
    return {k: v for k, v in a.items() if b.get(k) == v}


def succs(fn, a):
    i = fn.ins[a]; out = []
    n = a + 4
    def fl():
        if a in fn.fallin or a in fn.trapafter: return
        if n in fn.ins: out.append(n)
    if i.op == 'b':
        if i.lk: fl()
        elif i.target in fn.ins: out.append(i.target)
    elif i.op == 'bc':
        if i.target in fn.ins: out.append(i.target)
        if (i.bo & 20) != 20: fl()
    elif i.op == 'bclr':
        if i.lk: fl()
        elif (i.bo & 20) != 20: fl()
    elif i.op == 'bcctr':
        if i.lk: fl()
    elif i.op == 'rfi': pass
    else: fl()
    return out


def constprop(fn):
    init = {'r13': ('c', R13), 'r2': ('c', R2), 'r1': ('s', 0), 'lr': ('L',)}
    for x in range(14, 32): init['r%d' % x] = ('i', 'r%d' % x); init['f%d' % x] = ('i', 'f%d' % x)
    st = {fn.entry: init}
    work = [fn.entry]
    while work:
        a = work.pop()
        out = transfer(fn.ins[a], st[a], fn)
        for b in succs(fn, a):
            if b not in st: st[b] = dict(out); work.append(b)
            else:
                m = merge(st[b], out)
                if m != st[b]: st[b] = m; work.append(b)
    fn.state = st
    # Código inalcanzable por flujo: se descarta y se anota.
    for a in list(fn.ins):
        if a not in st: del fn.ins[a]; fn.labels.discard(a)


def ea_info(i, s):
    """Dirección efectiva si se conoce: ('c',K), ('s',k) o None."""
    if i.op == 'mem' or i.op in ('lmw', 'stmw', 'psq_l', 'psq_st'):
        if i.ra == 0: return ('c', i.imm & 0xffffffff)
        v = s.get('r%d' % i.ra)
        if v and v[0] == 'c': return ('c', (v[1] + i.imm) & 0xffffffff)
        if v and v[0] == 's': return ('s', v[1] + i.imm)
        return None
    if i.op == 'memx':
        a = s.get('r%d' % i.ra) if i.ra else ('c', 0); b = s.get('r%d' % i.rb)
        if a and b and a[0] == 'c' and b[0] == 'c': return ('c', (a[1] + b[1]) & 0xffffffff)
        if a and b and a[0] == 's' and b[0] == 'c': return ('s', a[1] + b[1])
        if a and b and a[0] == 'c' and b[0] == 's': return ('s', a[1] + b[1])
    return None


def analyze_frame(fn):
    spills = set(); int_words = set()
    for a, i in fn.ins.items():
        e = ea_info(i, fn.state[a])
        if i.op in ('mem', 'memx') and not i.fp and i.sz == 4 and e and e[0] == 's': int_words.add(e[1])
    for a, i in sorted(fn.ins.items()):
        s = fn.state[a]
        if i.op in ('stmw', 'lmw'):
            fn.elide.add(a)  # Los registros son locales: salvarlos y restaurarlos no tiene efecto.
            if not (s.get('r%d' % i.ra) or ('', ))[0] == 's': fn.notes.append('lmw/stmw con base no conocida en %x' % a)
            continue
        if i.op == 'mem' and i.upd and i.ra == 1 and not i.load and i.imm < 0 and not i.fp and s.get('r1') == ('s', 0):
            fn.frame = max(fn.frame, -i.imm)
        if i.op in ('psq_l', 'psq_st'):
            v = s.get('r%d' % i.ra)
            if v and v[0] == 's' and i.d >= 14 and i.sz == 0 and i.mb == 0: fn.elide.add(a)
            continue
        e = ea_info(i, s)
        if i.op in ('mem', 'memx') and e and e[0] == 's':
            k = e[1]
            if k == 4 and i.sz == 4 and not i.fp:
                if i.load or s.get('r%d' % i.d) == ('L',):
                    fn.elide.add(a); continue
            if i.fp and i.sz == 8: fn.dbl_slots.add(k)
            if k >= 8: fn.stack_params = max(fn.stack_params, (k - 8) // 4 + 1)
            reg = ('f%d' if i.fp else 'r%d') % i.d
            if not i.load and s.get(reg) == ('i', reg):
                spills.add((reg, k)); fn.elide.add(a)
        if i.op == 'addi':
            v = s.get('r%d' % i.ra) if i.ra else None
            if v and v[0] == 's' and i.ra != 1 or (v and v[0] == 's' and i.d != 1): fn.addr_slots.add(v[1] + i.imm)
    for a, i in fn.ins.items():
        s = fn.state[a]
        e = ea_info(i, s)
        if i.op in ('mem', 'memx') and i.load and e and e[0] == 's':
            reg = ('f%d' if i.fp else 'r%d') % i.d
            if (reg, e[1]) in spills: fn.elide.add(a)
        if i.op == 'mfspr' and i.imm == 8 and s.get('lr') == ('L',): fn.elide.add(a)
        if i.op == 'mtspr' and i.imm == 8 and s.get('r%d' % i.d) == ('L',): fn.elide.add(a)
    if fn.stack_params: fn.notes.append('lee %d palabras de argumentos en pila' % fn.stack_params)
    # Un doble de pila solo se guarda con la palabra alta primero si además se toca por palabras (conversiones int<->float).
    fn.split = {k for k in fn.dbl_slots if k in int_words or k + 4 in int_words}
    for k in fn.split & fn.addr_slots:
        fn.warn.append('doble de pila partido y con dirección tomada en %d(r1 entrada)' % k)
    # Uso de LR guardado en algo que no sea su restauración.
    for a, i in fn.ins.items():
        if a in fn.elide: continue
        s = fn.state[a]
        for u in i.uses:
            if u == 'lr' or i.op == 'mtspr': continue
            if s.get(u) == ('L',) and not (i.op == 'or' and i.d == i.rb): fn.warn.append('LR usado en %x' % a)


# --- Firmas ---
# Formas fijadas a mano: funciones variádicas sin definición ni usos en las unidades.
# memcpy y memset: las llamadas sin prototipo de la fuente salen como '...' en el censo, pero no son variádicas,
# y en arm64 de Darwin una llamada variádica pasa los argumentos por la pila.
MANUAL_FORMS = {0x802ec334: ('I', ['L', 'L', '...']), 0x802eee50: ('I', ['L', 'L', 'I']), 0x802eefe0: ('I', ['L', 'I', 'I'])}


class Sigs:
    def __init__(self, data):
        self.defs = {int(k, 16): v for k, v in data['defs'].items()}
        self.uses = {int(k, 16): v for k, v in data['uses'].items()}
        self.stubs = {int(x, 16) for x in data['sdk_stubs']}
        # Argumentos heredados: el original lee registros que la unidad no declara. Sin esto el llamador no los pasa y en arm64 llega basura.
        census = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../docs-data/inherit-census.json')))
        self.inherit = {int(c['addr'], 16): (c['need_int'], c['need_fp']) for c in census}

    def form(self, a, lifted):
        """(ret, params) del destino, o None si no se conoce."""
        if a in lifted:
            f = lifted[a]
            return (f.ret, ['I'] * f.pi + ['F' if f.ret != 'X' else 'F'] * f.pf, f)
        if a in self.defs and a not in self.stubs:
            d = self.defs[a]; ps = list(d[1])
            if a in self.inherit and '...' not in ps and 'R' not in ps[:1]:
                ints = sum(1 for p in ps if p in 'ILP' or p.startswith('A:') or p == 'B')
                fps = sum(1 for p in ps if p in 'FD')
                ps += ['L'] * max(0, self.inherit[a][0] - ints) + ['F'] * max(0, self.inherit[a][1] - fps)
            return (d[0], ps, None)
        if a in MANUAL_FORMS: return (*MANUAL_FORMS[a], None)
        best = None
        for (ur, up), n in self.uses.get(a, []):
            if '...' in up or ur in ('F', 'D') or 'F' in up or 'D' in up:
                if best is None or n > best[1]: best = ((ur, up), n)
        if best: return (best[0][0], list(best[0][1]), None)
        return None


def call_uses(fn, target, sigs, lifted, a, precise=False):
    """Registros que lee una llamada. Destino desconocido: los ocho y ocho, salvo en modo preciso (solo lecturas explícitas)."""
    fm = sigs.form(target, lifted) if isinstance(target, int) else None
    if fm is None: return set() if precise else set(INTS) | set(FLTS)
    ret, ps, lf = fm
    if lf is not None and precise: ps = ['I'] * lf.pi + ['F'] * lf.ppf
    u = set(); ii = 0; ff = 0
    for p in ps:
        if p == '...':
            u |= set(INTS[ii:]); break
        if p in 'ILP':
            if ii < 8: u.add(INTS[ii])
            ii += 1
        elif p in 'FD':
            if ff < 8: u.add(FLTS[ff])
            ff += 1
        elif p == 'R':
            if ii < 8: u.add(INTS[ii])
            ii += 1
        elif p.startswith('A:') or p == 'B':
            if ii < 8: u.add(INTS[ii])
            ii += 1
    if ret.startswith('A:'):  # Retorno por puntero oculto en PPC: r3 es el destino y los argumentos corren uno.
        u = {(INTS[INTS.index(x) + 1] if x in INTS and INTS.index(x) < 7 else x) for x in u} | {'r3'}
    return u


def liveness(fn, sigs, lifted, precise=False):
    """Conjuntos vivos a la entrada de cada instrucción. Devuelve lo vivo a la entrada de la función."""
    store = fn.precise_after if precise else fn.live_after
    live = {a: set() for a in fn.ins}
    retu = {'I': {'r3'}, 'F': {'f1'}, 'D': {'f1'}}[fn.ret]
    def ins_use_def(a):
        i = fn.ins[a]
        if a in fn.elide: return set(), set()
        u = set(i.uses); d = set(i.defs)
        if i.op == 'b' and i.lk or (i.op in ('bclr', 'bcctr') and i.lk):
            t = i.target if i.op == 'b' else None
            if t is not None and SAVEGPR[0] <= t < SAVEGPR[1]: return set(), set()
            u = (u - {'lr'}) if t is not None else u
            u |= call_uses(fn, t, sigs, lifted, a, precise)
            d |= set(VOLATILE) - {'r3', 'f1'}
            d.add('r3'); d.add('f1')
            # r3/f1 se definen según el retorno; ver live_after.
            fm = sigs.form(t, lifted) if t is not None else None
            if t in NORETURN: d = set()
        elif i.op == 'bclr':
            u.discard('lr')
            u |= retu
        elif i.op == 'b':
            pass
        return u, d
    changed = True
    while changed:
        changed = False
        for a in sorted(fn.ins, reverse=True):
            i = fn.ins[a]
            out = set()
            for b in succs(fn, a): out |= live[b]
            if a in fn.fallin or (i.op == 'b' and not i.lk and i.target not in fn.ins) or (i.op == 'bc' and i.target not in fn.ins):
                out |= call_uses(fn, (fn.fallin.get(a) if a in fn.fallin else i.target), sigs, lifted, None, precise) | retu
            u, d = ins_use_def(a)
            new = (out - d) | u
            if i.op in ('b', 'bclr', 'bcctr') and i.lk: store[a] = out
            if new != live[a]: live[a] = new; changed = True
    return live[fn.entry]


# --- Emisión ---
def lit(K): return '0x%xu' % K


class Emit:
    def __init__(self, fn, sigs, lifted, starts):
        self.fn = fn; self.sigs = sigs; self.lifted = lifted; self.starts = starts; self.ext = set()

    def mat(self, K):
        """Valor de 32 bits de una constante: las direcciones de datos y funciones cambian en el anfitrión."""
        if DATA_LO <= K < DATA_HI: return 'D(%s)' % lit(K)
        if TEXT_LO <= K < TEXT_HI and K in self.starts and not K & 3:
            return 'FN(%s)' % lit(K)
        if TEXT_LO <= K < TEXT_HI and not K & 3 and K & 0xffff:
            self.fn.warn.append('constante %x en el rango de texto sin ser función' % K)
        return lit(K)

    def ea(self, a, i):
        s = self.fn.state[a]
        e = ea_info(i, s)
        if e and e[0] == 'c':
            K = e[1]
            if DATA_LO <= K < DATA_HI: return 'D(%s)' % lit(K)
            if LOW_LO <= K < LOW_HI: return 'LOW(%s)' % lit(K)
            if K == 0xcc008000: raise W('FIFO en acceso no reconocido %x' % a)
            self.fn.warn.append('acceso absoluto %x en %x' % (K, a)); return lit(K)
        if i.op == 'memx':
            if i.ra == 0: return 'r%d' % i.rb
            return 'r%d + r%d' % (i.ra, i.rb)
        if i.ra == 0: return lit(i.imm & 0xffffffff)
        if i.imm == 0: return 'r%d' % i.ra
        return 'r%d %s %d' % (i.ra, '+' if i.imm >= 0 else '-', abs(i.imm))

    def args_for(self, target, a):
        return None

    def call(self, a, target, kind='call'):
        """kind='call': sentencia; deja el retorno en r3/f1."""
        fn = self.fn
        live = fn.precise_after.get(a, set()) if kind == 'call' else ({'f1'} if fn.ret in 'FD' else {'r3'})
        if isinstance(target, int):
            self.ext.add(target)
            if SAVEGPR[0] <= target < SAVEGPR[1]: return '/* salvado de registros */'
            callee = 'A%08x' % target
            fm = self.sigs.form(target, self.lifted)
        else:
            callee = 'g2h(%s)' % target; fm = None
        if fm is None:
            # Forma genérica: en arm64 los argumentos de más no molestan y los bancos entero/float son independientes.
            a_ = ', '.join(INTS + FLTS)
            if 'f1' in live: return 'f1 = CUF(%s, %s);' % (callee, a_)  # f1 es volátil: si se lee después, es el retorno.
            return 'r3 = CU(%s, %s);' % (callee, a_)
        ret, ps, lf = fm
        if lf is not None:
            al = [p for p in INTS[:lf.pi]]
            for k in range(lf.stack_params): al.append('L32(r1 + %d)' % (8 + 4 * k))
            al += FLTS[:lf.pf]
            call = '%s(%s)' % (callee, ', '.join(al))
            if lf.ret in 'FD': return 'f1 = %s;' % call
            return 'r3 = %s;' % call
        special = SPECIAL_CALLS.get(target)
        if special: return special
        variadic = '...' in ps
        fixed = [p for p in ps if p != '...']
        tys = []; vals = []; ii = 0; ff = 0
        if fixed and fixed[0] == 'R':
            # El destino oculto va en x8 en arm64 y en r3 en PPC; el resto de registros corre uno.
            rest = fixed[1:]; ints = []
            ii = 1
            for p in rest:
                if p in 'ILP' or p.startswith('A:') and False: ints.append('W(%s)' % INTS[ii]); ii += 1
                elif p in 'F': ff += 1
                else: raise W('agregado tras sret %x: %s' % (target, ps))
            if ii > 7: raise W('demasiados argumentos con sret %x' % target)
            while len(ints) < 6: ints.append('0')
            return 'w3d_open_sret((void *)%s, W(r3), %s, %s);' % (callee, ', '.join(ints), ', '.join('(float)' + x for x in FLTS))
        if ret.startswith('A:'):
            return self.call_aggret(a, target, callee, ret, fixed)
        for p in fixed:
            if p in 'ILP':
                tys.append('w3d_u64')
                vals.append('W(%s)' % INTS[ii] if ii < 8 else 'W(L32(r1 + %d))' % (8 + 4 * (ii - 8))); ii += 1
            elif p == 'F': tys.append('float'); vals.append('(float)%s' % FLTS[ff]); ff += 1
            elif p == 'D': tys.append('double'); vals.append('%s' % FLTS[ff]); ff += 1
            elif p == '[2 x i64]' or p == 'A:[2 x i64]':
                tys.append('w3d_open_pair'); vals.append('w3d_open_pair_at(%s)' % INTS[ii]); ii += 1
            else: raise W('agregado %s en llamada a %x desde %x' % (p, target, a))
        if variadic:
            for k in range(ii, 8): vals.append('W(%s)' % INTS[k])
            # Ranuras de pila: hasta 6 palabras de desbordamiento visibles antes de la llamada.
            for k in range(self.overflow(a)): vals.append('W(L32(r1 + %d))' % (8 + 4 * k))
            tys.append('...')
        sig = ', '.join(tys)
        rett = {'I': 'w3d_u32', 'L': 'w3d_u64', 'P': 'w3d_u64', 'V': 'void', 'F': 'float', 'D': 'double'}.get(ret)
        if rett is None: raise W('retorno agregado %s en %x desde %x' % (ret, target, a))
        c = '((%s (*)(%s))%s)(%s)' % (rett, sig, callee, ', '.join(vals))
        if ret == 'V':
            # La firma dice void pero el PPC usa r3: en la mayoría el destino sí devuelve valor y lo deja en x0.
            # Excepción: un destino que es solo blr deja r3 intacto, y el PPC lo aprovecha.
            if kind == 'call' and self.reads_r3_after(a) and word(target) != 0x4e800020:
                fn.warn.append('lee r3 tras void %x en %x' % (target, a))
                return 'r3 = (w3d_u32)((w3d_u64 (*)(%s))%s)(%s);' % (sig, callee, ', '.join(vals))
            return c + ';'
        if ret in 'FD': return 'f1 = %s;' % c
        # Un entero de 64 bits vuelve en r3:r4 en PPC y entero en x0 aquí.
        if ret == 'L' and kind == 'call' and self.reads_reg_after(a, 'r4'):
            return '{ w3d_u64 v_ = %s; r3 = (w3d_u32)(v_ >> 32); r4 = (w3d_u32)v_; }' % c
        return 'r3 = (w3d_u32)%s;' % c

    def call_aggret(self, a, target, callee, ret, fixed):
        """Retorno por valor en registros de arm64: en PPC el destino llega en r3 y los argumentos en r4 en adelante."""
        vals = []; tys = []; ii = 1; ff = 0
        for p in fixed:
            if p in 'ILP': tys.append('w3d_u64'); vals.append('W(%s)' % INTS[ii]); ii += 1
            elif p == 'F': tys.append('float'); vals.append('(float)%s' % FLTS[ff]); ff += 1
            else: raise W('agregado %s con retorno agregado en %x' % (p, target))
        rt = {'A:[2 x i64]': 'w3d_open_pair', 'A:%struct.K2aVec3': 'w3d_open_vec3', 'A:%struct.W3dGPoint': 'w3d_open_pair'}.get(ret)
        if rt is None: raise W('retorno agregado %s en %x' % (ret, target))
        return '{ %s t_ = ((%s (*)(%s))%s)(%s); w3d_open_store(r3, t_); }' % (rt, rt, ', '.join(tys), callee, ', '.join(vals))

    def reads_r3_after(self, a): return self.reads_reg_after(a, 'r3')

    def reads_reg_after(self, a, reg):
        fn = self.fn; x = a + 4
        while x in fn.ins:
            i = fn.ins[x]
            if x in fn.elide: x += 4; continue
            # Llega al blr sin tocar r3: la función devuelve lo que dejó la llamada (reenviadores de asignadores, por ejemplo).
            if i.op == 'bclr' and reg == 'r3': return True
            if i.op in ('b', 'bc', 'bclr', 'bcctr'): return False
            if reg in i.uses: return True
            if reg in i.defs: return False
            x += 4
        return False

    def overflow(self, a):
        n = 0; seen = set(); x = a - 4
        fn = self.fn
        while x in fn.ins and x > a - 64:
            i = fn.ins[x]
            if i.op == 'mem' and not i.load and not i.fp and i.sz == 4:
                e = ea_info(i, fn.state[x])
                if e and e[0] == 's':
                    rel = e[1] + fn.frame
                    if rel >= 8 and (rel - 8) % 4 == 0: seen.add((rel - 8) // 4)
            elif i.op in ('b', 'bc', 'bclr'): break
            x -= 4
        while n in seen: n += 1
        return n

    def cond(self, i):
        c = []
        pre = ''
        if not i.bo & 4:
            pre = '--ctr'
            c.append(('ctr == 0' if i.bo & 2 else 'ctr != 0'))
        if not i.bo & 16:
            f = i.bi >> 2; bit = 8 >> (i.bi & 3)
            c.append('(cr%d & %d)' % (f, bit) if i.bo & 8 else '!(cr%d & %d)' % (f, bit))
        return pre, ' && '.join(c) if c else 'true'

    def rcz(self, i, reg):
        return (' cr0 = CMPS(%s, 0);' % reg) if i.rc else ''

    def stmt(self, a):
        fn = self.fn; i = fn.ins[a]; op = i.op; S = fn.state[a]
        if a in fn.elide: return None
        d, ra, rb = i.d, i.ra, i.rb
        rD = 'r%d' % d if isinstance(d, int) else ''; rA = 'r%d' % ra if isinstance(ra, int) else ''; rB = 'r%d' % rb if isinstance(rb, int) else ''
        fD = 'f%d' % d if isinstance(d, int) else ''; fA = 'f%d' % ra if isinstance(ra, int) else ''; fB = 'f%d' % rb if isinstance(rb, int) else ''
        fC = 'f%d' % i.sh
        def constof(n): v = S.get(n); return v[1] if v and v[0] == 'c' else None
        if op == 'word':
            if i.imm == 1: return 'w3d_open_break(%s);' % lit(a)
            return 'w3d_open_break(%s);' % lit(a)
        if op == 'nop': return None
        if op == 'addi' or op == 'addis':
            imm = i.imm << 16 if op == 'addis' else i.imm
            if ra == 0: return '%s = %s;' % (rD, self.mat(imm & 0xffffffff))
            k = constof(rA)
            if k is not None: return '%s = %s;' % (rD, self.mat((k + imm) & 0xffffffff))
            if rD == 'r1': return 'r1 = r1 %s %d;' % ('+' if imm >= 0 else '-', abs(imm))
            return '%s = %s %s %d;' % (rD, rA, '+' if imm >= 0 else '-', abs(imm)) if imm else '%s = %s;' % (rD, rA)
        if op in ('ori', 'oris', 'xori', 'xoris'):
            imm = i.imm << 16 if op.endswith('s') else i.imm
            k = constof(rD)
            if k is not None:
                return '%s = %s;' % (rA, self.mat((k | imm) if op[0] == 'o' else (k ^ imm)))
            return '%s = %s %s %s;' % (rA, rD, '|' if op[0] == 'o' else '^', lit(imm))
        if op in ('andi', 'andis'):
            imm = i.imm << 16 if op == 'andis' else i.imm
            return '%s = %s & %s; cr0 = CMPS(%s, 0);' % (rA, rD, lit(imm), rA)
        if op == 'mulli': return '%s = (w3d_s32)%s * %d;' % (rD, rA, i.imm)
        if op == 'subfic': return 'ca = (w3d_u32)%d >= %s; %s = (w3d_u32)%d - %s;' % (i.imm, rA, rD, i.imm, rA) if False else '{ w3d_u32 t_ = %s; %s = (w3d_u32)%d - t_; ca = ((w3d_u32)%d >= t_); }' % (rA, rD, i.imm, i.imm)
        if op == 'addic': return '{ w3d_u32 t_ = %s; %s = t_ + (w3d_u32)%d; ca = %s < t_;%s }' % (rA, rD, i.imm, rD, self.rcz(i, rD))
        if op == 'cmpi': return 'cr%d = CMPS(%s, %d);' % (d, rA, i.imm)
        if op == 'cmpli': return 'cr%d = CMPU(%s, %s);' % (d, rA, lit(i.imm))
        if op == 'cmp': return 'cr%d = CMPS(%s, %s);' % (d, rA, rB)
        if op == 'cmpl': return 'cr%d = CMPU(%s, %s);' % (d, rA, rB)
        if op == 'fcmp': return 'cr%d = CMPF(%s, %s);' % (d, fA, fB)
        if op == 'rlwinm':
            return '%s = %s;%s' % (rA, rlwexpr(rD, i.sh, i.mask), self.rcz(i, rA))
        if op == 'rlwnm':
            return '%s = ROTL(%s, %s & 31) & %s;%s' % (rA, rD, rB, lit(i.mask), self.rcz(i, rA))
        if op == 'rlwimi':
            return '%s = (ROTL(%s, %d) & %s) | (%s & %s);%s' % (rA, rD, i.sh, lit(i.mask), rA, lit((~i.mask) & 0xffffffff), self.rcz(i, rA))
        if op in ('add', 'subf', 'mullw'):
            e = {'add': '%s + %s' % (rA, rB), 'subf': '%s - %s' % (rB, rA), 'mullw': '(w3d_s32)%s * (w3d_s32)%s' % (rA, rB)}[op]
            k1, k2 = constof(rA), constof(rB)
            if op == 'add' and k1 is not None and k2 is not None: return '%s = %s;%s' % (rD, self.mat((k1 + k2) & 0xffffffff), self.rcz(i, rD))
            return '%s = %s;%s' % (rD, e, self.rcz(i, rD))
        if op == 'mulhw': return '%s = (w3d_u32)(((w3d_s64)(w3d_s32)%s * (w3d_s64)(w3d_s32)%s) >> 32);%s' % (rD, rA, rB, self.rcz(i, rD))
        if op == 'mulhwu': return '%s = (w3d_u32)(((w3d_u64)%s * (w3d_u64)%s) >> 32);%s' % (rD, rA, rB, self.rcz(i, rD))
        if op == 'divw': return '%s = DIVS(%s, %s);%s' % (rD, rA, rB, self.rcz(i, rD))
        if op == 'divwu': return '%s = DIVU(%s, %s);%s' % (rD, rA, rB, self.rcz(i, rD))
        if op == 'addc': return '{ w3d_u32 t_ = %s; %s = t_ + %s; ca = %s < t_;%s }' % (rA, rD, rB, rD, self.rcz(i, rD))
        if op == 'subfc': return '{ w3d_u32 a_ = %s, b_ = %s; %s = b_ - a_; ca = b_ >= a_;%s }' % (rA, rB, rD, self.rcz(i, rD))
        if op == 'adde': return '{ w3d_u64 t_ = (w3d_u64)%s + %s + ca; %s = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32);%s }' % (rA, rB, rD, self.rcz(i, rD))
        if op == 'subfe': return '{ w3d_u64 t_ = (w3d_u64)(w3d_u32)~%s + %s + ca; %s = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32);%s }' % (rA, rB, rD, self.rcz(i, rD))
        if op == 'neg': return '%s = 0u - %s;%s' % (rD, rA, self.rcz(i, rD))
        if op == 'addze': return '{ w3d_u64 t_ = (w3d_u64)%s + ca; %s = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32);%s }' % (rA, rD, self.rcz(i, rD))
        if op == 'subfze': return '{ w3d_u64 t_ = (w3d_u64)(w3d_u32)~%s + ca; %s = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32);%s }' % (rA, rD, self.rcz(i, rD))
        if op == 'addme': return '{ w3d_u64 t_ = (w3d_u64)%s + 0xffffffffu + ca; %s = (w3d_u32)t_; ca = (w3d_u32)(t_ >> 32);%s }' % (rA, rD, self.rcz(i, rD))
        if op == 'or' and d == rb:
            k = constof(rD)
            v = '%s' % rD if k is None else self.mat(k)
            return '%s = %s;%s' % (rA, v, self.rcz(i, rA))
        if op in ('and', 'or', 'xor', 'andc', 'orc', 'nor', 'eqv', 'nand'):
            e = {'and': '%s & %s', 'or': '%s | %s', 'xor': '%s ^ %s', 'andc': '%s & ~%s', 'orc': '%s | ~%s', 'nor': '~(%s | %s)', 'eqv': '~(%s ^ %s)', 'nand': '~(%s & %s)'}[op] % (rD, rB)
            return '%s = %s;%s' % (rA, e, self.rcz(i, rA))
        if op == 'slw': return '%s = SLW(%s, %s);%s' % (rA, rD, rB, self.rcz(i, rA))
        if op == 'srw': return '%s = SRW(%s, %s);%s' % (rA, rD, rB, self.rcz(i, rA))
        if op == 'sraw': return '{ w3d_u32 t_ = %s, n_ = %s; %s = SRAW(t_, n_); ca = SRAWCA(t_, n_);%s }' % (rD, rB, rA, self.rcz(i, rA))
        if op == 'srawi': return '{ w3d_u32 t_ = %s; %s = (w3d_u32)((w3d_s32)t_ >> %d); ca = SRAWCA(t_, %d);%s }' % (rD, rA, i.sh, i.sh, self.rcz(i, rA))
        if op == 'extsb': return '%s = (w3d_u32)(w3d_s32)(signed char)%s;%s' % (rA, rD, self.rcz(i, rA))
        if op == 'extsh': return '%s = (w3d_u32)(w3d_s32)(short)%s;%s' % (rA, rD, self.rcz(i, rA))
        if op == 'cntlzw': return '%s = %s ? __builtin_clz(%s) : 32;%s' % (rA, rD, rD, self.rcz(i, rA))
        if op == 'mfcr': return '%s = (cr0 << 28) | (cr1 << 24) | (cr2 << 20) | (cr3 << 16) | (cr4 << 12) | (cr5 << 8) | (cr6 << 4) | cr7;' % rD
        if op == 'mtcrf':
            out = []
            for x in range(8):
                if i.imm & (0x80 >> x): out.append('cr%d = (%s >> %d) & 15;' % (x, rD, 28 - 4 * x))
            return ' '.join(out)
        if op == 'mcrf': return 'cr%d = cr%d;' % (d >> 2, ra >> 2)
        if op == 'mfspr':
            if i.imm == 9: return '%s = ctr;' % rD
            if i.imm == 8: return '%s = lr;' % rD
            if i.imm == 1: return '%s = ca << 29;' % rD
            fn.warn.append('mfspr %d en %x' % (i.imm, a)); return '%s = 0;' % rD
        if op == 'mtspr':
            if i.imm == 8: return 'lr = %s;' % rD
            if i.imm == 9: return 'ctr = %s;' % rD
            if 912 <= i.imm <= 919: return '/* mtgqr %d: la cuantización no existe en el anfitrión */' % (i.imm - 912)
            fn.warn.append('mtspr %d en %x' % (i.imm, a)); return '/* mtspr %d */' % i.imm
        if op in ('crnor', 'crandc', 'crxor', 'crnand', 'crand', 'creqv', 'crorc', 'cror'):
            A = '((cr%d >> %d) & 1)' % (ra >> 2, 3 - (ra & 3)); B = '((cr%d >> %d) & 1)' % (rb >> 2, 3 - (rb & 3))
            if op == 'crxor' and d == ra == rb: e = '0'
            elif op == 'creqv' and d == ra == rb: e = '1'
            else: e = {'crnor': '~(%s | %s)', 'crandc': '%s & ~%s', 'crxor': '%s ^ %s', 'crnand': '~(%s & %s)', 'crand': '%s & %s', 'creqv': '~(%s ^ %s)', 'crorc': '%s | ~%s', 'cror': '%s | %s'}[op] % (A, B)
            f = d >> 2; b = 3 - (d & 3)
            return 'cr%d = (cr%d & ~%du) | (((%s) & 1) << %d);' % (f, f, 1 << b, e, b)
        if op == 'memx' and i.upd and ra == 1 and not i.load:
            # stwux r1: alloca de GCC. El bloque nuevo vive en la pila del anfitrión, con el enlace atrás en su primera palabra.
            return '{ char *p_ = (char *)__builtin_alloca((w3d_u32)(0u - r%d) + 16); w3d_u32 t_ = h2g(p_); S32(t_, %s); r1 = t_; }' % (rb, rD)
        if op == 'mem' and not i.load:
            e0 = ea_info(i, S)
            if e0 and e0 == ('c', 0xcc008000):
                # Puerto FIFO de GX: no es memoria; lo recibe la capa de GX.
                raise W('escritura directa a la FIFO de GX en %x: no soportada, esas funciones las da sdk_gx_xgx.cpp' % a)
        if op in ('mem', 'memx'):
            ea = self.ea(a, i)
            upd = ''
            if i.upd:
                upd = ' r%d = t_;' % ra
                if ra == 1: pass
            e = ea_info(i, S)
            onstack = e is not None and e[0] == 's' and e[1] in fn.split
            if i.fp:
                if i.load:
                    ld = ('LF(%s)' if i.sz == 4 else ('LDS(%s)' if onstack else 'LD(%s)'))
                else:
                    ld = None
                if i.load:
                    if i.upd: return '{ w3d_u32 t_ = %s; %s = %s;%s }' % (ea, fD, ld % 't_', upd)
                    return '%s = %s;' % (fD, ld % ea)
                st = 'SF' if i.sz == 4 else ('SDS' if onstack else 'SD')
                if i.upd: return '{ w3d_u32 t_ = %s; %s(t_, %s);%s }' % (ea, st, fD, upd)
                return '%s(%s, %s);' % (st, ea, fD)
            if i.load and i.sz == 1 and op == 'memx' and not i.upd:
                for b_ in (ra, rb):
                    v_ = S.get('r%d' % b_) if b_ else None
                    if v_ and v_[0] == 'c' and any(t0 <= v_[1] < t0 + n0 for t0, n0 in SWAPPED_BYTE_TABLES):
                        fn.notes.append('tabla de bytes %x leída con el orden de palabra invertido' % v_[1])
                        return '%s = L8((%s) ^ 3u);' % (rD, ea)
            if i.load:
                ld = {4: 'L32(%s)', 2: 'LS16(%s)' if i.sign else 'L16(%s)', 1: 'L8(%s)'}[i.sz]
                if i.upd: return '{ w3d_u32 t_ = %s; %s = %s;%s }' % (ea, rD, ld % 't_', upd)
                return '%s = %s;' % (rD, ld % ea)
            st = {4: 'S32', 2: 'S16', 1: 'S8'}[i.sz]
            if i.upd: return '{ w3d_u32 t_ = %s; %s(t_, %s);%s }' % (ea, st, rD, upd)
            return '%s(%s, %s);' % (st, ea, rD)
        if op == 'dcbz':
            return 'DCBZ(%s);' % (('r%d + r%d' % (ra, rb)) if ra else 'r%d' % rb)
        if op == 'stmw' or op == 'lmw':
            raise W('lmw sin elidir')
        if op in ('psq_l', 'psq_st'):
            if i.sz != 1 or i.mb not in (2, 3, 4, 5): raise W('psq no reconocido %x' % a)
            ea = self.ea(a, i)
            t = {2: 'U8', 3: 'U16', 4: 'S8', 5: 'S16'}[i.mb]
            if op == 'psq_l': return '%s = PSQL_%s(%s);' % (fD, t, ea)
            return 'PSQS_%s(%s, %s);' % (t, ea, fD)
        if op in ('fadd', 'fsub', 'fmul', 'fdiv'):
            sg = {'fadd': '+', 'fsub': '-', 'fmul': '*', 'fdiv': '/'}[op]; return '%s = %s %s %s;' % (fD, fA, sg, fB)
        if op in ('fadds', 'fsubs', 'fmuls', 'fdivs'):
            sg = {'fadds': '+', 'fsubs': '-', 'fmuls': '*', 'fdivs': '/'}[op]; return '%s = (float)(%s %s %s);' % (fD, fA, sg, fB)
        if op in ('fmadds', 'fmsubs', 'fnmadds', 'fnmsubs'):
            # fmaf: la multiplicación-suma del Gekko es fusionada de verdad.
            neg = '-' if op[1] == 'n' else ''
            sb = '-' if 'sub' in op else ''
            return '%s = %s__builtin_fmaf((float)%s, (float)%s, %s(float)%s);' % (fD, neg, fA, fC, sb, fB)
        if op in ('fmadd', 'fmsub', 'fnmadd', 'fnmsub'):
            neg = '-' if op[1] == 'n' else ''
            sb = '-' if 'sub' in op else ''
            return '%s = %s__builtin_fma(%s, %s, %s%s);' % (fD, neg, fA, fC, sb, fB)
        if op == 'frsp': return '%s = (float)%s;' % (fD, fB)
        if op == 'fneg': return '%s = -%s;' % (fD, fB)
        if op == 'fmr': return '%s = %s;' % (fD, fB)
        if op == 'fabs': return '%s = __builtin_fabs(%s);' % (fD, fB)
        if op == 'fnabs': return '%s = -__builtin_fabs(%s);' % (fD, fB)
        if op == 'fctiwz': return '%s = FCTIWZ(%s);' % (fD, fB)
        if op == 'fctiw': return '%s = FCTIW(%s);' % (fD, fB)
        if op == 'fsel': return '%s = (%s >= 0.0) ? %s : %s;' % (fD, fA, fC, fB)
        if op == 'fres': return '%s = (float)(1.0 / %s);' % (fD, fB)
        if op == 'frsqrte': return '%s = 1.0 / __builtin_sqrt(%s);' % (fD, fB)
        if op == 'msr' or op == 'rfi':
            raise W('privilegiada %s en %x' % (op, a))
        raise W('sin emisión: %s en %x' % (op, a))

    def ret_stmt(self):
        fn = self.fn
        if fn.ret == 'F': return 'return (float)f1;'
        if fn.ret == 'D': return 'return f1;'
        return 'return r3;'

    def body(self):
        fn = self.fn; out = []
        order = sorted(fn.ins)
        for idx, a in enumerate(order):
            i = fn.ins[a]
            if a in fn.labels: out.append('L_%08x:' % a)
            nxt = order[idx + 1] if idx + 1 < len(order) else None
            s = None
            stop = False
            if i.op == 'b':
                if i.lk:
                    s = self.call(a, i.target)
                    if a in fn.trapafter: s += ' __builtin_trap();'; stop = True
                elif i.target in fn.ins:
                    if i.target != nxt: s = 'goto L_%08x;' % i.target
                    stop = True
                else:
                    s = self.call(a, i.target, 'tail') + ' ' + self.ret_stmt(); stop = True
            elif i.op == 'bc':
                pre, c = self.cond(i)
                pfx = (pre + '; ') if pre else ''
                if i.target in fn.ins:
                    s = '%sif (%s) goto L_%08x;' % (pfx, c, i.target)
                else:
                    s = '%sif (%s) { %s %s }' % (pfx, c, self.call(a, i.target, 'tail'), self.ret_stmt())
                if (i.bo & 20) == 20: stop = True
            elif i.op == 'bclr':
                if i.lk:
                    s = self.call(a, 'lr')
                elif (i.bo & 20) == 20:
                    s = self.ret_stmt(); stop = True
                else:
                    pre, c = self.cond(i); s = '%sif (%s) %s' % ((pre + '; ') if pre else '', c, self.ret_stmt())
            elif i.op == 'bcctr':
                s = self.call(a, 'ctr')
            else:
                s = self.stmt(a)
            if a in fn.fallin:
                t = fn.fallin[a]
                if s: out.append('    ' + s)
                s = self.call(a, t, 'tail') + ' ' + self.ret_stmt(); stop = True
            if s: out.append('    ' + s)
            if not stop and a not in fn.trapafter:
                n = a + 4
                if n in fn.ins and n != nxt: out.append('    goto L_%08x;' % n); fn.labels.add(n)
        return out

    def header(self):
        return func_decl(self.fn)

    def text(self):
        fn = self.fn
        # Primera pasada para fijar etiquetas añadidas por caída.
        self.body()
        lines = self.body()
        used = set(re.findall(r'\b([rf]\d+|ctr|lr|ca|cr[0-7])\b', '\n'.join(lines)))
        params = set(INTS[:fn.pi]) | set(FLTS[:fn.pf])
        used |= params
        if fn.stack_params: used.add('r1')
        ints = sorted((u for u in used if re.fullmatch(r'r\d+', u) and u not in params and u != 'r1'), key=lambda x: int(x[1:]))
        flts = sorted((u for u in used if re.fullmatch(r'f\d+', u)), key=lambda x: int(x[1:]))
        crs = sorted(u for u in used if u.startswith('cr'))
        sp = []
        d = []
        if ints: d.append('w3d_u32 ' + ', '.join(x + ' = 0' for x in ints) + ';')
        fdecl = []
        for x in flts:
            if x in params: fdecl.append('%s = s%s' % (x, x[1:]))
            else: fdecl.append('%s = 0' % x)
        if fdecl: d.append('double ' + ', '.join(fdecl) + ';')
        oth = [x + ' = 0' for x in crs + [o for o in ('ctr', 'lr', 'ca') if o in used]]
        if oth: d.append('w3d_u32 ' + ', '.join(oth) + ';')
        if 'r1' in used:
            size = fn.frame + 8 + 4 * max(fn.stack_params, 0) + 8
            sp.append('alignas(16) char frame[%d];' % size)
            sp.append('w3d_u32 r1 = h2g(frame) + %d;' % fn.frame)
            for k in range(fn.stack_params): sp.append('S32(r1 + %d, sp%d);' % (8 + 4 * k, k))
        return [func_decl(fn) + ' {'] + ['    ' + x for x in sp + d] + lines + ['}']


def func_decl(fn):
    ps = ['w3d_u32 %s' % x for x in INTS[:fn.pi]]
    ps += ['w3d_u32 sp%d' % k for k in range(fn.stack_params)]
    ps += ['double s%d' % (k + 1) if fn.dbl else 'float s%d' % (k + 1) for k in range(fn.pf)]
    rt = {'I': 'w3d_u32', 'F': 'float', 'D': 'double'}[fn.ret]
    return '%s A%08x(%s)' % (rt, fn.entry, ', '.join(ps) if ps else 'void')


def rlwexpr(rs, sh, mask):
    if sh == 0: return '%s & %s' % (rs, lit(mask)) if mask != 0xffffffff else rs
    if mask == ((0xffffffff << sh) & 0xffffffff): return '%s << %d' % (rs, sh)
    if mask == (0xffffffff >> (32 - sh)): return '%s >> %d' % (rs, 32 - sh)
    return 'ROTL(%s, %d) & %s' % (rs, sh, lit(mask))


SPECIAL_CALLS = {}


# --- Programa ---
def load_starts():
    st = set()
    for l in open(f'{ROOT}/source/recovered/refined/functions.jsonl'):
        st.add(int(json.loads(l)['address'], 16))
    for f in json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))['functions']:
        st.add(int(f['address'], 16))
    return st


def ghidra_sigs():
    out = {}
    for l in open(f'{ROOT}/source/recovered/refined/functions.jsonl'):
        o = json.loads(l); out[int(o['address'], 16)] = o
    return out


REPLACED = {0x80003100: 'crt0 __start: lo sustituye main() de boot_main.cpp', 0x80003224: 'crt0: copia de secciones, la hace el cargador del DOL', 0x80003290: 'crt0: limpieza de BSS y registros, innecesaria en el anfitrión',
            0x800032d0: 'crt0 __init_registers: fija r1, r2 y r13, que no existen en el anfitrión',
            0x802e33c8: 'depurador SN: copia de memoria que solo llama la zona sn_debug', 0x802e3420: 'depurador SN: manejador sin llamadores en el juego'}
GROUP_LIMIT = 90000  # bytes de texto C++ por archivo, para compilar en paralelo.


def run(out_dir, inputs):
    inv = json.load(open(f'{ROOT}/analysis/inventario-no-recuperado.json'))['functions']
    cats = ('open_sn', 'stack_hole', 'held', 'stray_word', 'tiny', 'inline_asm')
    starts = load_starts(); gh = ghidra_sigs()
    global GH
    GH = gh
    data = json.load(open(inputs))
    sigs = Sigs(data)
    fns = {}; errors = {}
    skip = {}
    # Lo que ya define otra parte del port se deja en sus manos: dos definiciones no enlazarían.
    others = {}
    for d in ('core/sdk', 'core/overrides', 'core/boot', 'core/libc/src', 'platform/gx', 'platform/common'):
        pth = f'{ROOT}/port/{d}'
        for name in (os.listdir(pth) if os.path.isdir(pth) else []):
            if name.endswith(('.cpp', '.mm')) and name != 'sdk_stubs.cpp':
                for x in re.findall(r'\bA(80[0-9a-f]{6})\s*\([^;{]*\)\s*\{', open(f'{pth}/{name}', errors='replace').read()):
                    others[int(x, 16)] = f'port/{d}/{name}'
    for f in inv:
        if f['category'] not in cats: continue
        a = int(f['address'], 16)
        if a in REPLACED: skip[a] = (f, REPLACED[a]); continue
        if a in others: skip[a] = (f, 'definida en ' + others[a]); continue
        fns[a] = Fn(a, f['name'], f['category'])
    for x in (os.environ.get('W3D_OPEN_EXTRA_LIST') and json.load(open(os.environ['W3D_OPEN_EXTRA_LIST'])) or []):
        fns[int(x, 16)] = Fn(int(x, 16), 'extra', 'prueba')
    # Argumentos heredados: la fuente admitida no los nombra y en arm64 se pierden. Andamio: ver docs/GOAL.md.
    inherit = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'inherit-extra.json')
    for x in (json.load(open(inherit)) if os.path.exists(inherit) else []):
        if int(x, 16) not in others: fns[int(x, 16)] = Fn(int(x, 16), 'heredados', 'inherit')
    lifted = {}
    for a, fn in sorted(fns.items()):
        try:
            build(fn, starts); constprop(fn); analyze_frame(fn)
        except (W, ValueError, KeyError) as e:
            errors[a] = str(e); continue
        lifted[a] = fn
    # Evidencia de retorno flotante y de dobles.
    for a, fn in lifted.items():
        sig = gh.get(a, {}).get('signature', '')
        m = re.match(r'(\w+)\s+\**\w+\(', sig)
        rt = m.group(1) if m else ''
        fp_ret = rt in ('float', 'double', 'float10')
        for (ur, up), n in sigs.uses.get(a, []):
            if ur in ('F', 'D'): fp_ret = True
        if 0x802e5574 <= a < 0x802f4ef0: fn.dbl = True
        if fp_ret: fn.ret = 'D' if fn.dbl else 'F'
    # Punto fijo: parámetros y retorno de las traducidas, de menos a más.
    for it in range(30):
        ch = False
        for a, fn in lifted.items():
            lv = liveness(fn, sigs, lifted)
            pi = max([INTS.index(x) + 1 for x in lv if x in INTS], default=0)
            pf = max([FLTS.index(x) + 1 for x in lv if x in FLTS], default=0)
            if fn.stack_params: pi = 8
            if pi > fn.pi or pf > fn.pf: fn.pi = max(pi, fn.pi); fn.pf = max(pf, fn.pf); ch = True
            plv = liveness(fn, sigs, lifted, precise=True)
            ppf = max([FLTS.index(x) + 1 for x in plv if x in FLTS], default=0)
            if ppf > fn.ppf: fn.ppf = ppf; ch = True
            for b, i in fn.ins.items():
                if i.op == 'b' and i.lk and i.target in lifted:
                    la = fn.precise_after.get(b, set())
                    t = lifted[i.target]
                    if 'f1' in la and t.ret == 'I': t.ret = 'F'; ch = True
            for t in fn.tails:
                if t in lifted and fn.ret == 'F' and lifted[t].ret == 'I': lifted[t].ret = 'F'; ch = True
        if not ch: break
    for a, fn in lifted.items(): liveness(fn, sigs, lifted); liveness(fn, sigs, lifted, precise=True)
    # Emisión.
    meta = {}; bodies = {}; ext = collections.Counter()
    for a, fn in sorted(lifted.items()):
        e = Emit(fn, sigs, lifted, starts)
        try:
            bodies[a] = e.text()
        except W as x:
            errors[a] = str(x); continue
        for t in e.ext: ext[t] += 1
        fn.warn = sorted(set(fn.warn)); fn.notes = sorted(set(fn.notes))
        # Huecos dentro del cuerpo sin flujo que llegue: tras una trampa suelen ser manejadores de excepción de GCC.
        gw = (max(fn.ins) - min(fn.ins)) // 4 + 1 - len(fn.ins) if fn.ins else 0
        meta[a] = dict(warn=fn.warn, notes=fn.notes, ret=fn.ret, pi=fn.pi, pf=fn.pf, frame=fn.frame, callees=sorted(e.ext), tails=sorted(fn.tails), lines=len(bodies[a]), ninstr=len(fn.ins), stack_params=fn.stack_params, dead_words=gw)
    return lifted, bodies, meta, errors, skip, ext, sigs



def write_all(out_dir, lifted, bodies, meta, skip, desc, sigs):
    order = sorted(bodies)
    for old in os.listdir(out_dir):
        if re.fullmatch(r'open_8[0-9a-f]{7}\.cpp', old): os.remove(os.path.join(out_dir, old))
    groups = []; cur = []; size = 0
    for a in order:
        z = sum(len(x) + 1 for x in bodies[a])
        if cur and size + z > GROUP_LIMIT: groups.append(cur); cur = []; size = 0
        cur.append(a); size += z
    if cur: groups.append(cur)
    with open(f'{out_dir}/open_decls.h', 'w') as f:
        f.write('// Generado por port/tests/open/ppc2cpp.py: firmas de las funciones de core/open.\n#ifndef W3D_OPEN_DECLS_H\n#define W3D_OPEN_DECLS_H\nextern "C" {\n')
        for a in order: f.write(func_decl(lifted[a]) + ';\n')
        f.write('}\n#endif\n')
    files = {}
    for g in groups:
        name = 'open_%08x.cpp' % g[0]
        ext = set()
        for a in g: ext |= set(meta[a]['callees'])
        ext -= set(lifted)
        with open(f'{out_dir}/{name}', 'w') as f:
            f.write('// Funciones del juego sin fuente admitida: 0x%08x a 0x%08x. Generado por port/tests/open/ppc2cpp.py.\n' % (g[0], g[-1]))
            f.write('// Ninguna está verificada ni cuenta como recuperada.\n#include "open_rt.h"\n\nextern "C" {\n')
            for t in sorted(ext):
                if not SAVEGPR[0] <= t < SAVEGPR[1]: f.write('void A%08x();\n' % t)
            f.write('\n')
            for a in g:
                fn = lifted[a]; d = desc.get(a, '')
                f.write('// 0x%08x %s no verificada: desde bytes PPC\n' % (a, fn.name))
                if d: f.write('// %s\n' % d)
                for w in meta[a]['warn']: f.write('// aviso: %s\n' % w)
                f.write('\n'.join(bodies[a]) + '\n\n')
            f.write('}\n')
        for a in g: files[a] = name
    return files


if __name__ == '__main__':
    out_dir = sys.argv[1]; inputs = sys.argv[2]
    os.makedirs('/tmp/w3dp_open', exist_ok=True)
    lifted, bodies, meta, errors, skip, ext, sigs = run(out_dir, inputs)
    print('traducidas', len(bodies), 'errores', errors)
    dp = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'open-descriptions.json')
    desc = {int(k, 16): v for k, v in json.load(open(dp)).items()} if os.path.exists(dp) else {}
    files = write_all(out_dir, lifted, bodies, meta, skip, desc, sigs)
    # Débiles: una fuente admitida que empiece a compilar o una función reescrita a mano tiene preferencia sobre la traducción.
    for name in os.listdir(out_dir):
        if re.fullmatch(r'open_[0-9a-f]{8}\.cpp', name):
            path = os.path.join(out_dir, name)
            text = re.sub(r'^(?=(?:void|float|double|w3d_u32|w3d_u64|w3d_open_\w+) A[0-9a-f]{8}\()', '__attribute__((weak)) ', open(path).read(), flags=re.M)
            # Byte de flags de la etiqueta de objeto: en PPC es +7 desde la cabecera, el byte bajo de la palabra en +4.
            # Excepción: 0x801a7680 lee los flags de un descriptor de propiedad, que está en crudo en su sitio.
            keep = re.search(r'\bA801a7680\(w3d_u32 r3.*?^}\n', text, re.S | re.M)
            keep = keep[0] if keep else None
            text = re.sub(r'\bL8\((r(?!1\b)\d+) \+ 7\)', r'L8(\1 + 4)', text)
            text = re.sub(r'\bS8\((r(?!1\b)\d+) \+ 7,', r'S8(\1 + 4,', text)
            if keep: text = re.sub(r'\bA801a7680\(w3d_u32 r3.*?^}\n', lambda m: keep, text, flags=re.S | re.M)
            # GCC 2.95 destruye los argumentos por valor en la función llamada; clang lo hace en la que llama, y todos los
            # llamadores de estas son C++ del juego. Sin quitarlo aquí, la cadena se libera dos veces.
            for fname, reg in BYVALUE_CALLEE.items():
                m = re.search(r'\b%s\(w3d_u32 r3.*?^}\n' % fname, text, re.S | re.M)
                if m:
                    destroy = r'    r3 = %s;\n    \(\(void \(\*\)\(w3d_u64\)\)A8020c5c4\)\(W\(r3\)\);\n    r3 = %s;\n    \(\(void \(\*\)\(w3d_u64\)\)A80341588\)\(W\(r3\)\);\n' % (reg, reg)
                    body, n = re.subn(destroy, '', m[0])
                    assert n >= 1, fname
                    text = text[:m.start()] + body + text[m.end():]
            # Fichero .csh: en disco es little-endian y el PPC le da la vuelta; aquí ya está en orden.
            m = re.search(r'\bA800bc7c4\(w3d_u32 r3.*?^}\n', text, re.S | re.M)
            if m:
                body = m[0]
                for old in ('    r31 = r9 | r0;\n', '    S32(r8 + r29, r11);\n'):
                    assert body.count(old) == 1, old
                    body = body.replace(old, '')
                text = text[:m.start()] + body + text[m.end():]
            # Escritor de la tabla STRS: el formato en disco es little-endian y aquí la memoria ya lo es.
            m = re.search(r'\bA80205258\(w3d_u32 r3.*?^}\n', text, re.S | re.M)
            if m:
                body = m[0]
                for old, new, n in (('r0 = 0x53545253u;', 'r0 = 0x53525453u;', 1), ('S32(r1 + 60, r8);', 'S32(r1 + 60, __builtin_bswap32(r8));', 1),
                                    ('S32(r1 + 64, r11);', 'S32(r1 + 64, __builtin_bswap32(r11));', 1), ('    S32(r8 + r7, r0);\n', '', 2)):
                    assert body.count(old) == n, old
                    body = body.replace(old, new)
                text = text[:m.start()] + body + text[m.end():]
            # Propiedades de 32 bits del nodo de terreno leídas por su último byte en PPC (Visible, SmoothShading, EdgeCrinkle, EdgeFalloff).
            m = re.search(r'\bA800b2408\(w3d_u32 r3.*?^}\n', text, re.S | re.M)
            if m:
                body = m[0]
                for old, new in ((207, 204), (203, 200), (199, 196), (195, 192)):
                    assert body.count('L8(r15 + %d)' % old) == 1, old
                    body = body.replace('L8(r15 + %d)' % old, 'L8(r15 + %d)' % new)
                text = text[:m.start()] + body + text[m.end():]
            # Inicial del tema como cadena de un carácter: en PPC, sth de c<<8 deja c,0 en memoria.
            if ' A8006d854(w3d_u32 r3' in text:
                assert 'S16(r1 + 136, r0);' in text
                text = text.replace('S16(r1 + 136, r0);', 'S16(r1 + 136, r0 >> 8);')
            open(path, 'w').write(text)
    json.dump(dict(meta={hex(a): m for a, m in meta.items()}, errors={hex(a): e for a, e in errors.items()}, ext=sorted(ext), files={hex(a): n for a, n in files.items()}, skip={hex(a): v[1] for a, v in skip.items()}), open('/tmp/w3dp_open/gen-meta.json', 'w'), indent=0)
    allw = collections.Counter()
    for a, m in meta.items():
        for w in m['warn']: allw[re.sub(r'[0-9a-f]{6,}', 'X', w)] += 1
    print(allw, 'archivos', len(set(files.values())))
