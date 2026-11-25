#!/usr/bin/env python3
"""Descriptores estáticos de clase que reciben los constructores de tipos (r4 de 0x8020fbd0 y similares).

Forma: {char *nombre; u16 bits; u16 tamaño; ...}. Se accede con lhz a palabras que la conversión trataría como una sola.
Salida: port/docs-data/type-descriptors.json y excepciones en port/core/data/layout_exceptions.json.
"""
import collections, json, os, struct, sys
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
d = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
off = struct.unpack('>18I', d[:72]); addr = struct.unpack('>18I', d[0x48:0x90]); size = struct.unpack('>18I', d[0x90:0xd8])
def word(x):
    for o, a, s in zip(off, addr, size):
        if s and a <= x and x + 4 <= a + s: return struct.unpack_from('>I', d, o + x - a)[0]
def text(x):
    for o, a, s in zip(off, addr, size):
        if s and a <= x < a + s:
            i = o + x - a; return d[i:d.find(b'\0', i, i + 64)]
    return b''
segs = [(o, a, n) for o, a, n in zip(off, addr, size) if n and a >= 0x8035f3e0]
hits = collections.Counter()
for o, a, n in segs:
    for x in range(a, a + n - 24, 4):
        nm, w1, w2, w3, w4 = word(x), word(x + 4), word(x + 8), word(x + 12), word(x + 16)
        if nm is None or not 0x8035f3e0 <= nm < 0x804b3280: continue
        t = text(nm)
        if not (2 <= len(t) < 64 and t[:1].isalpha() and all(32 <= c < 127 for c in t)): continue
        if not (w3 and 0x8035f3e0 <= w3 < 0x804b3280): continue
        if not (w2 == 0 or 0x8035f3e0 <= w2 < 0x804b3280): continue
        if not (0 < (w1 & 0xffff) < 0x8000): continue
        if w4 is None or w4 >= 0x20000000 or w4 & 0xffff: continue   # bytes de tipo y flags
        if 0x80000000 <= w1 < 0x80500000: continue                   # puntero: es una tabla de otra cosa
        if word(x + 20) == 0xffff: continue                          # descriptor de propiedad con enlace
        hits[x] += 1
print(len(hits))
found = []
for a in sorted(hits):
    nm = word(a); w1 = word(a + 4)
    t = text(nm) if nm else b''
    found.append(dict(addr=hex(a), name=t.decode('latin-1'), w1=hex(w1 or 0), w2=hex(word(a + 8) or 0), w3=hex(word(a + 12) or 0), w4=hex(word(a + 16) or 0), w5=hex(word(a + 20) or 0)))
print(found[:6]); print(found[-3:])
json.dump(found, open(f'{ROOT}/port/docs-data/type-descriptors.json', 'w'), indent=0)
if '--apply' in sys.argv:
    ex = json.load(open(f'{ROOT}/port/core/data/layout_exceptions.json'))
    ex = [e for e in ex if not e.get('why', '').startswith('descriptor de clase')]
    for f in found:
        a = int(f['addr'], 16)
        ex.append(dict(addr=hex(a + 4), size=4, kind='half', why='descriptor de clase: u16 bits y u16 tamaño'))
        ex.append(dict(addr=hex(a + 16), size=8, kind='raw', why='descriptor de clase: bytes de versión y flags'))
        # Campos: {identificador; u16; u16 desplazamiento; manejador}, doce bytes. El número está en el byte +17.
        fields = word(a + 28)
        count = ((word(a + 16) or 0) >> 16) & 255
        if fields and 0x8035f3e0 <= fields < 0x804b3280:
            for k in range(count):
                ex.append(dict(addr=hex(fields + 12 * k + 4), size=4, kind='half', why='descriptor de clase: campo con desplazamiento u16'))
    json.dump(ex, open(f'{ROOT}/port/core/data/layout_exceptions.json', 'w'), indent=1)
