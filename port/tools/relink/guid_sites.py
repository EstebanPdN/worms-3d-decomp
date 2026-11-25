#!/usr/bin/env python3
"""GUID del DOL que se comparan con memcmp contra los leídos de los XOM: {u32; u16; u16; 8 bytes} en orden del anfitrión.

Candidatos: toda ventana alineada de 16 B del DOL cuya forma little-endian aparezca en algún XOM. Se añade cada sitio a port/core/data/layout_exceptions.json.
"""
import json, mmap, os, struct, re
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
d = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
off = struct.unpack('>18I', d[:72]); addr = struct.unpack('>18I', d[0x48:0x90]); size = struct.unpack('>18I', d[0x90:0xd8])
# Índice de los XOM por los cuatro primeros bytes de cada posición alineada a nada: se guarda solo lo que empieza como un candidato.
cands = {}
for o, a, s in zip(off, addr, size):
    if not s or a < 0x8035f3e0: continue
    for k in range(0, s - 15, 4):
        b = d[o + k:o + k + 16]
        x, y, z = struct.unpack_from('>IHH', b)
        if 0x80000000 <= x < 0x80500000 or x < 0x10000 or b[8:] == b'\0' * 8 or b[8:12] == b[12:] or len(set(b)) < 8: continue  # sin variedad: tablas, floats o espacios, no una GUID
        le = struct.pack('<IHH', x, y, z) + b[8:]
        cands.setdefault(le[:6], []).append((le, a + k))
print('candidatos', sum(map(len, cands.values())))
found = {}
rx = re.compile(b'(?=(' + b'|'.join(re.escape(k) for k in list(cands)[:0]) + b'))') if False else None
keys = set(cands)
for r, _, fs in os.walk(f'{ROOT}/gamedata/GWMP8P/files'):
    for f in fs:
        if not f.lower().endswith('.xom'): continue
        b = open(os.path.join(r, f), 'rb').read()
        if b[:4] != b'MOIK': continue
        # Las GUID de un XOM están en la cabecera de tipos y en los descriptores del principio.
        for i in range(0, min(len(b), 1 << 20) - 16):
            k = b[i:i + 6]
            if k in keys:
                g = b[i:i + 16]
                for le, a in cands[k]:
                    if le == g: found[a] = g.hex()
print('sitios', len(found))
ex = json.load(open(f'{ROOT}/port/core/data/layout_exceptions.json'))
ex = [e for e in ex if not e.get('why', '').startswith('GUID')]
for a in sorted(found):
    ex.append(dict(addr=hex(a), size=4, kind='float', why='GUID: u32 sin traducir como puntero'))
    ex.append(dict(addr=hex(a + 4), size=4, kind='half', why='GUID: dos u16'))
    ex.append(dict(addr=hex(a + 8), size=8, kind='raw', why='GUID: bytes'))
json.dump(ex, open(f'{ROOT}/port/core/data/layout_exceptions.json', 'w'), indent=1)
json.dump({hex(a): g for a, g in sorted(found.items())}, open(f'{ROOT}/port/docs-data/guid-sites.json', 'w'), indent=0)
print(0x8040e078 in found)
