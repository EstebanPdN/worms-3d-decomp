#!/usr/bin/env python3
"""Descriptores de propiedades en los datos del DOL: {char *nombre; u16 desplazamiento; u8 tipo; u8 flags; tipo *destino; enlace *}.

Se localizan por los bytes y se añaden a port/core/data/layout_exceptions.json: el u16 y los dos u8 no pueden convertirse como palabra.
"""
import json, os, struct
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
d = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
off = struct.unpack('>18I', d[:72]); addr = struct.unpack('>18I', d[0x48:0x90]); size = struct.unpack('>18I', d[0x90:0xd8])
segs = [(o, a, s) for o, a, s in zip(off, addr, size) if s and a >= 0x8035f3e0]
def word(x):
    for o, a, s in segs:
        if a <= x and x + 4 <= a + s: return struct.unpack_from('>I', d, o + x - a)[0]
def is_text(x):
    for o, a, s in segs:
        if a <= x < a + s:
            i = o + x - a; j = d.find(b'\0', i, i + 64)
            if j <= i: return False
            t = d[i:j]
            return 1 <= len(t) < 64 and all(32 <= c < 127 for c in t) and (t[0:1].isalpha())
    return False
def cstr(x):
    for o, a, s in segs:
        if a <= x < a + s:
            i = o + x - a
            return d[i:d.find(b'\0', i, i + 64)]
    return b''
def in_data(x): return x is not None and 0x8035f3e0 <= x < 0x804b3280
found = []
# Lo que type_descriptors.py ya reconoce como descriptor de clase tiene otra forma.
classes = {int(x['addr'], 16) for x in json.load(open(f'{ROOT}/port/docs-data/type-descriptors.json'))}
for o, a, s in segs:
    for x in range(a, a + s - 16, 4):
        if x in classes: continue
        n, w1, tgt, link = word(x), word(x + 4), word(x + 8), word(x + 12)
        if not (in_data(n) and is_text(n) and in_data(tgt)): continue
        if not (link == 0 or in_data(link)): continue
        # Tabla de temas (0x803f477c): el entero tras la ruta del tema es una palabra normal y se usa como índice.
        if 0x803f477c <= x < 0x803f4854: continue
        # Tablas de FMV (PAL y NTSC): {nombre, id, ruta}; el id es una palabra normal.
        if 0x803f5724 <= x < 0x803f5a80: continue
        off16 = w1 >> 16; kind = (w1 >> 8) & 255; flags = w1 & 255
        if off16 >= 0x8000 or flags >= 64: continue
        found.append(dict(addr=hex(x), name=d[off[0]:0] and '' or '', offset=off16, kind=kind, flags=flags))
ex = json.load(open(f'{ROOT}/port/core/data/layout_exceptions.json'))
ex = [e for e in ex if not e.get('why', '').startswith('propiedad')]
for f in found:
    a = int(f['addr'], 16)
    ex.append(dict(addr=hex(a + 4), size=2, kind='half', why='propiedad: u16 desplazamiento'))
    ex.append(dict(addr=hex(a + 6), size=2, kind='raw', why='propiedad: tipo y flags'))
json.dump(ex, open(f'{ROOT}/port/core/data/layout_exceptions.json', 'w'), indent=1)
json.dump(found, open(f'{ROOT}/port/docs-data/prop-descriptors.json', 'w'), indent=0)
print(len(found), found[:4])
