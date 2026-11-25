#!/usr/bin/env python3
"""Tablas de bytes y de medias palabras en los datos del DOL, según el código que las indexa con lbzx/lhzx/lhax.

Una tabla de bytes convertida como palabras queda con cada grupo de cuatro al revés (índices de malla, por ejemplo).
El código PPC dice cuál es: carga la dirección con lis/addi y luego la indexa. El tamaño llega hasta la siguiente
dirección que algún código cargue. Se añaden a port/core/data/layout_exceptions.json.
"""
import bisect, glob, json, os, re
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
LO, HI = 0x8035f3e0, 0x804b3280
FN = f'{ROOT}/source/recovered/refined/functions'
lis = re.compile(r' lis (r\d+),(-?0x[0-9a-f]+)$'); addi = re.compile(r' addi (r\d+),(r\d+),(-?0x[0-9a-f]+)$'); subi = re.compile(r' subi (r\d+),(r\d+),(0x[0-9a-f]+)$')
idx = re.compile(r' (lbzx|lhzx|lhax) (r\d+),(r\d+),(r\d+)$')
loaded = set(); tables = {}
for f in glob.glob(FN + '/*/*.asm'):
    high = {}; addr = {}
    for line in open(f, errors='replace'):
        line = line.rstrip()
        m = lis.search(line)
        if m:
            high[m[1]] = (int(m[2], 16) & 0xffff) << 16; addr.pop(m[1], None); continue
        m = addi.search(line); s = 1
        if not m: m = subi.search(line); s = -1
        if m and m[2] in high:
            a = (high[m[2]] + s * int(m[3], 16)) & 0xffffffff
            if LO <= a < HI: addr[m[1]] = a; loaded.add(a)
            continue
        m = idx.search(line)
        if m:
            for r in (m[3], m[4]):
                if r in addr: tables.setdefault(addr[r], set()).add('raw' if m[1] == 'lbzx' else 'half')
            continue
        m = re.search(r' (?:or|mr) (r\d+),(r\d+),\2$', line)
        if m and m[2] in addr: addr[m[1]] = addr[m[2]]
order = sorted(loaded)
import struct
_d = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
_off = struct.unpack('>18I', _d[:72]); _adr = struct.unpack('>18I', _d[0x48:0x90]); _siz = struct.unpack('>18I', _d[0x90:0xd8])
def initialized(a):
    for o, x, z in zip(_off, _adr, _siz):
        if z and x <= a < x + z: return o + a - x
    return None
def inside_text(o):
    # Un registro reutilizado puede señalar el interior de una cadena; partirla deja su texto girado por palabras.
    lo = o
    while lo > 0 and 32 <= _d[lo - 1] < 127: lo -= 1
    hi = o
    while hi < len(_d) and 32 <= _d[hi] < 127: hi += 1
    return lo < o and hi > o and _d[hi] == 0 and hi - lo >= 6 and (chr(_d[lo]).isalpha() or _d[lo] == 95)
def plausible(a, end):
    # Solo datos iniciados, sin punteros dentro: una estructura indexada por bytes no es una tabla.
    if a & 1 or end - a > 1024: return False
    o = initialized(a)
    if o is None or inside_text(o): return False
    for q in range((a + 3) & ~3, end - 3, 4):
        v = struct.unpack_from('>I', _d, o + q - a)[0]
        if 0x80000000 <= v < 0x80500000: return False
    return True
ex = json.load(open(f'{ROOT}/port/core/data/layout_exceptions.json'))
ex = [e for e in ex if e.get('why') != 'tabla indexada: bytes o medias palabras']
# Registros reutilizados dan indicios falsos: estas son tablas de int que se leen con lwzx.
WORD_TABLES = {0x80399ed8, 0x803dffd0, 0x803e0014, 0x803e0030, 0x804090f0}
for a_ in WORD_TABLES: tables.pop(a_, None)
taken = {int(e['addr'], 16) for e in ex}
n = 0
for a, kinds in sorted(tables.items()):
    if len(kinds) != 1: continue
    i = bisect.bisect_right(order, a)
    end = min(order[i] if i < len(order) else HI, a + 4096)
    # Sin etiqueta cercana detrás: la tabla acaba en la primera palabra alineada a cero, que es el relleno.
    o_ = initialized(a)
    if o_ is not None and (end - a > 256 or not plausible(a, end)):
        for q in range((a + 7) & ~3, end - 3, 4):
            if struct.unpack_from('>I', _d, o_ + q - a)[0] == 0:
                end = q; break
    if not plausible(a, end): continue
    ex.append(dict(addr=hex(a), size=end - a, kind=kinds.pop(), why='tabla indexada: bytes o medias palabras')); n += 1
# Tablas de métodos de Vmalloc: el campo meth es un u16 en +0x1c (se lee con lhz). Como palabra, todos los heaps quedan con modo 0.
ex = [e for e in ex if e.get('why') != 'método de Vmalloc: u16']
for m in (0x8040066c, 0x804006e4, 0x80400728, 0x80400748):
    ex.append(dict(addr=hex(m + 0x1c), size=4, kind='half', why='método de Vmalloc: u16'))
# Tablas que el código indexa desde una dirección impar: plausible() las descarta o se quedan en su primera fila.
FIXED = [(0x803db448, 0x104, 'raw', 'tabla de clases de carácter: bytes'),  # indexada desde 0x803db449 (índice -1 de EOF)
         (0x803aa2b0, 0x12c, 'raw', 'formatos de imagen de respaldo: 11 filas de 27 bytes'),  # 0x801ab614
         (0x803a6648, 20, 'word', 'lista de 5 formatos de imagen: int')]  # argumento de 0x801ab614 en 0x801712c4
names = {w for _, _, _, w in FIXED}
ex = [e for e in ex if e.get('why') not in names and not (e['addr'] == hex(0x803aa2b0))]
ex += [dict(addr=hex(a_), size=z_, kind=k_, why=w_) for a_, z_, k_, w_ in FIXED]
json.dump(ex, open(f'{ROOT}/port/core/data/layout_exceptions.json', 'w'), indent=1)
print('tablas', n, 'direcciones cargadas', len(order))
print(0x80403c0c in tables, [hex(a) for a in sorted(tables)[:12]])
