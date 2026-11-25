#!/usr/bin/env python3
"""Punteros a método de GCC 2.95 en los datos del DOL: {s16 delta; s16 índice; función o (s16 vtoff; s16 relleno)}.

El índice -1 marca función directa y el siguiente word es una dirección de código. Con índice positivo el word siguiente lleva vtoff en la mitad alta.
Las mitades se leen con lha, así que no pueden convertirse como palabra. Se añaden a port/core/data/layout_exceptions.json.
"""
import json, os, struct
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
d = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
off = struct.unpack('>18I', d[:72]); addr = struct.unpack('>18I', d[0x48:0x90]); size = struct.unpack('>18I', d[0x90:0xd8])
segs = [(o, a, s) for o, a, s in zip(off, addr, size) if s and a >= 0x8035f3e0]
TEXT = (0x80003100, 0x8035f3e0)
direct = []; virtual_ = []
for o, a, s in segs:
    for k in range(0, s - 8, 4):
        w, n = struct.unpack_from('>II', d, o + k)
        hi, lo = w >> 16, w & 0xffff
        if lo == 0xffff and (hi < 0x4000 or hi >= 0xc000) and TEXT[0] <= n < TEXT[1]: direct.append(a + k)
        elif hi == 0 and 1 <= lo < 0x400 and n & 0xffff == 0 and (n >> 16) < 0x1000:
            # Índice virtual: solo si el word anterior o el posterior forma parte de una pareja de punteros a método.
            nx = struct.unpack_from('>I', d, o + k + 8)[0] if k + 12 <= s else 0
            pv = struct.unpack_from('>I', d, o + k - 4)[0] if k >= 4 else 0
            nx2 = struct.unpack_from('>I', d, o + k + 12)[0] if k + 16 <= s else 0
            # Filas de manejadores {tipo *, función, modo, 0} (p. ej. 0x803a9c40): el modo es una palabra normal, no un índice.
            pv2 = struct.unpack_from('>I', d, o + k - 8)[0] if k >= 8 else 0
            if 0x80360000 <= pv2 < 0x804c0000 and TEXT[0] <= pv < TEXT[1] and 1 <= lo <= 3 and n == 0: continue
            if (nx & 0xffff == 0xffff and TEXT[0] <= nx2 < TEXT[1]) or pv >> 24 == 0x80 and TEXT[0] <= pv < TEXT[1]: virtual_.append(a + k)
ex = json.load(open(f'{ROOT}/port/core/data/layout_exceptions.json'))
ex = [e for e in ex if not e.get('why', '').startswith('puntero a método')]
for x in direct: ex.append(dict(addr=hex(x), size=4, kind='half', why='puntero a método: delta e índice'))
for x in virtual_:
    ex.append(dict(addr=hex(x), size=4, kind='half', why='puntero a método virtual: delta e índice'))
    ex.append(dict(addr=hex(x + 4), size=4, kind='half', why='puntero a método virtual: vtoff'))
json.dump(ex, open(f'{ROOT}/port/core/data/layout_exceptions.json', 'w'), indent=1)
json.dump(dict(direct=[hex(x) for x in direct], virtual=[hex(x) for x in virtual_]), open(f'{ROOT}/port/docs-data/pmf-descriptors.json', 'w'), indent=0)
print('directos', len(direct), 'virtuales', len(virtual_), [hex(x) for x in direct[:3]], [hex(x) for x in virtual_[:3]])
