#!/usr/bin/env python3
"""Descripciones y port/docs-data/open-functions.json de las funciones de core/open.

Las descripciones son deducidas de lo que se ve en los bytes: cadenas, destinos con nombre y clase de operaciones.
Las de open-descriptions-a-mano.json se leyeron una a una. Uso: make_open_json.py <gen-meta.json> <sigs.json> <paso>
  paso=desc: escribe open-descriptions.json    paso=json: escribe open-functions.json
"""
import collections, json, os, re, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '../../..'))
sys.path.insert(0, f'{ROOT}/port/tools/relink')
sys.path.insert(0, HERE)
import symbols as S
from ppc_decode import decode

meta_all = json.load(open(sys.argv[1])); sigs = json.load(open(sys.argv[2])); step = sys.argv[3]
meta = {int(k, 16): v for k, v in meta_all['meta'].items()}
files = {int(k, 16): v for k, v in meta_all['files'].items()}
skip = {int(k, 16): v for k, v in meta_all['skip'].items()}
inv = {int(f['address'], 16): f for f in json.load(open(f'{ROOT}/analysis/inventario-no-recuperado.json'))['functions']}
g = S.load_global(); names = collections.defaultdict(list)
for n, ads in g.items():
    for a in ads: names[a].append(n)
dol = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
TEXT0 = 0x80003100
def word(a): return struct.unpack_from('>I', dol, a - TEXT0 + 0x100)[0]


def nice(a):
    ns = [n for n in names.get(a, []) if not re.match(r'(FUN_|fn_|w3d_fn_|w3d_auto|autof|auto|A80)', n)]
    if not ns: return None
    ns.sort(key=lambda n: (n.startswith('_'), -len(n)))
    n = re.sub(r'^(w3d_)?([a-z]{1,4}\d+[a-z]*_)', '', ns[0]); n = re.sub(r'_?80[0-9a-f]{6}$', '', n)
    return n[:34]


def cstr(k):
    if k & 0xffff == 0: return None  # Parte alta de un lis: no apunta a la cadena.
    for sa, so, sz in ((0x80368ca0, 0x365ca0, 0x82980), (0x803eb620, 0x3e8620, 0x31560), (0x804aa540, 0x419b80, 0x22e0), (0x804b1920, 0x41be60, 0x1940)):
        if sa <= k < sa + sz:
            o = so + k - sa; e = dol.find(b'\0', o, o + 64)
            if e > o and e - o >= 3 and all(32 <= c < 127 for c in dol[o:e]): return dol[o:e].decode()
    return None


def body_of(a):
    fp = open(f'{ROOT}/port/core/open/{files[a]}').read()
    i = fp.index(' A%08x(' % a); j = fp.index('\n}\n', i)
    return fp[i:j]


def describe(a, m):
    b = body_of(a)
    if m['ninstr'] <= 4 and '.long' not in b and 'w3d_open_break' in b:
        ret = re.findall(r'r3 = (0x[0-9a-f]+)u;', b)
        v = ('devuelve ' + ret[-1]) if ret else 'no devuelve valor'
        if ret and ret[-1] in ('0x80004001', '0x80004002', '0x80004005'): v = 'devuelve ' + ret[-1] + ' (código de error estilo COM)'
        return 'Método sin implementar: la palabra 0x00000001 inicial es una trampa al depurador; aquí avisa y ' + v + '.'
    strs = []
    for x in re.findall(r'D\((0x[0-9a-f]+)u\)', b):
        s = cstr(int(x, 16))
        if s and s not in strs: strs.append(s)
    calls = []
    for x in re.findall(r'\bA(80[0-9a-f]{6})\b', b):
        n = nice(int(x, 16))
        if int(x, 16) != a and n and n not in calls: calls.append(n)
    vc = len(re.findall(r'C[UF]+\(g2h\(lr\)', b))
    fl = len(re.findall(r'\bf\d+ = (?:\(float\)|LF|-?__builtin_fma|PSQL)', b))
    parts = []
    nm = nice(a)
    if nm: parts.append('Nombre deducido por sus llamadores: %s.' % nm)
    if calls: parts.append('Llama a ' + ', '.join(calls[:5]) + '.')
    if vc: parts.append('Hace %d llamada%s virtual%s.' % (vc, 's' if vc > 1 else '', 'es' if vc > 1 else ''))
    if strs: parts.append('Usa las cadenas ' + ', '.join('"%s"' % s[:28] for s in strs[:3]) + '.')
    if fl >= 40: parts.append('Mucho cálculo en coma flotante.')
    elif fl >= 8: parts.append('Algo de cálculo en coma flotante.')
    if not parts: parts.append('Función de %d instrucciones sin destinos con nombre ni cadenas.' % m['ninstr'])
    return ' '.join(parts)


if step == 'desc':
    hand = json.load(open(f'{HERE}/open-descriptions-a-mano.json'))
    d = {hex(a): describe(a, m) if hex(a) not in hand else hand[hex(a)] for a, m in meta.items()}
    json.dump(d, open(f'{HERE}/open-descriptions.json', 'w'), ensure_ascii=False, indent=0, sort_keys=True)
    print('descripciones', len(d), 'a mano', len([k for k in d if k in hand]))
    sys.exit(0)

desc = json.load(open(f'{HERE}/open-descriptions.json'))
led = {int(f['address'], 16): f for f in json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))['functions']}
ghidra = {}
for l in open(f'{ROOT}/source/recovered/refined/functions.jsonl'):
    o = json.loads(l); ghidra[int(o['address'], 16)] = o
# Grafo de llamadas directas por bytes y referencias desde datos.
callers = collections.defaultdict(list); edges = collections.defaultdict(set)
text_end = 0x8035f3e0
starts = sorted(ghidra)
import bisect
def fn_of(a):
    i = bisect.bisect_right(starts, a) - 1
    return starts[i] if i >= 0 else 0
for a in range(TEXT0, text_end, 4):
    w = word(a)
    if w >> 26 == 18:
        li = w & 0x03fffffc
        if li & 0x02000000: li -= 0x04000000
        t = (a + li) & 0xffffffff
        if t in ghidra and fn_of(a) != t:
            callers[t].append(a); edges[fn_of(a)].add(t)
datar = collections.Counter()
for off, sz in ((0x35c3e0, 0x98c0), (0x365ca0, 0x82980), (0x3e8620, 0x31560), (0x419b80, 0x22e0), (0x41be60, 0x1940)):
    for o in range(off, off + sz, 4): datar[struct.unpack_from('>I', dol, o)[0]] += 1
# Alcanzables por llamadas directas desde el arranque, para el orden de prioridad.
roots = [0x8015ad40, 0x801267f8, 0x80126bfc, 0x8015ba70, 0x801fcb90, 0x801fcd74, 0x801fcc48]
order = {}
work = list(roots); dist = {r: 0 for r in roots}
while work:
    x = work.pop(0)
    for t in edges.get(x, ()):
        if t not in dist: dist[t] = dist[x] + 1; work.append(t)
uses = sigs['uses']
rows = []
for a in sorted(inv):
    f = inv[a]
    if f['category'] not in ('open_sn', 'stack_hole', 'held', 'stray_word', 'tiny', 'inline_asm'): continue
    r = dict(address='0x%08x' % a, name=f['name'], category=f['category'], ghidra_bytes=f['bytes'])
    if a in skip:
        r.update(status='replaced', reason=skip[a], file=None, description=skip[a], confidence='n/a', callers_checked=dict(direct=len(callers[a]), data_refs=datar[a]))
        rows.append(r); continue
    m = meta[a]
    forms = uses.get(hex(a), [])
    bad = []
    for (ur, up), n in forms:
        if (ur in ('I', 'L', 'P') and m['ret'] in ('F', 'D')) or (ur in ('F', 'D') and m['ret'] == 'I'): bad.append(['retorno', ur, n])
        if any(x.startswith('A:') or x == 'B' for x in up) or ur.startswith('A:'): bad.append(['agregado', ur, n])
    gr = ghidra.get(a, {}).get('ranges_inclusive', [])
    gwords = set()
    for s_, e_ in gr:
        gwords |= set(range(int(s_, 16), int(e_, 16) + 1, 4))
    dead = len(gwords - set(range(a, a + 4 * 100000, 4)) if False else [x for x in gwords if x not in set(m.get('addrs', []))]) if m.get('addrs') else None
    b = body_of(a)
    notes = list(m['notes'])
    risk = []
    if m['warn']: risk.append('avisos de traducción')
    if 'PSQ' in b: risk.append('conversión psq: saturación y truncamiento según Dolphin, no comprobados en consola')
    if 'w3d_open_sret' in b or 'w3d_open_store' in b: risk.append('retorno de agregado adaptado a arm64')
    if 'LDS(' in b or 'SDS(' in b: risk.append('dobles de pila partidos por palabras')
    if bad: risk.append('forma de llamador incompatible')
    if m['frame'] > 1024: risk.append('marco grande')
    if m.get('dead_words'): risk.append('%d palabras inalcanzables descartadas (posibles manejadores de excepción)' % m['dead_words'])
    if m['ninstr'] <= 4: conf = 'alta'
    elif bad or len(risk) >= 2: conf = 'baja'
    else: conf = 'media'
    r.update(status='ported', file='port/core/open/' + files[a], description=desc.get(hex(a), ''), confidence=conf, risks=risk, notes=notes,
             signature=dict(ret=m['ret'], int_params=m['pi'], float_params=m['pf'], stack_params=m.get('stack_params', 0)),
             instructions=m['ninstr'], boot_distance=dist.get(a),
             callers_checked=dict(direct=len(callers[a]), sample=[hex(x) for x in callers[a][:6]], data_refs=datar[a], admitted_forms=[[x[0], n] for x, n in forms][:6], incompatible=bad))
    rows.append(r)
ported = [r for r in rows if r['status'] == 'ported']
out = dict(
    date='2026-11-01', method='Traducción mecánica de los bytes PPC del DOL (port/tests/open/ppc2cpp.py), con el pseudocódigo solo como contraste. Nada de esto está verificado ni cuenta como recuperado.',
    summary=dict(total=len(rows), ported=len(ported), replaced=len(rows) - len(ported), by_category=collections.Counter(r['category'] for r in ported), by_confidence=collections.Counter(r['confidence'] for r in ported)),
    tiny_words='Las entradas de 1 B son funciones: su primera palabra 0x00000001 es una trampa al depurador SN y el cuerpo sigue detrás. Están en tablas virtuales y sin llamadas directas en casi todos los casos.',
    stray_words='0x00000001 tras OSFatal o en ramas de error es la misma trampa; el código siguiente se traduce si tiene flujo y se descarta si no.',
    link_fallbacks=dict(weak_definitions=['0x8004c378', '0x80342bac', '0x80342ddc', '0x80346ef0', '0x802ec334', '0x802ed984'], reason='Solo las llaman funciones de core/open; link_all.py no crea stub si ninguna unidad admitida las referencia. Las cuatro primeras son unidades que aún no compilan: al arreglarlas hay que quitar su línea de open_support.cpp, o link_all.py dará por buena la débil.'),
    data_layout_exceptions=[dict(address='0x803db448', bytes=264, note='tabla ctype de bytes, cargada como palabras'), dict(address='0x803f4c58', bytes=8, note='tabla de bytes, cargada como flotantes')],
    functions=rows)
json.dump(out, open(f'{ROOT}/port/docs-data/open-functions.json', 'w'), ensure_ascii=False, indent=1, default=str)
print(out['summary'])
