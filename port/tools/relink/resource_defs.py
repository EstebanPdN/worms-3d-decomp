#!/usr/bin/env python3
"""Tablas de definiciones de recursos de 0x8017c788: registros de 20 B {char *nombre; u8 bundle; u8 sub; relleno; valor; u16; u16; u16 flags; relleno}.

Se localizan por los argumentos r4 y r5 de cada llamada en PPC y se añaden a port/core/data/layout_exceptions.json.
"""
import json, os, struct
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
def is_row(x):
    n, w1, w2, w3, w4 = word(x), word(x + 4), word(x + 8), word(x + 12), word(x + 16)
    if None in (n, w1, w2, w3, w4) or not 0x8035f3e0 <= n < 0x804b3280: return False
    t = text(n)
    if not (2 <= len(t) < 64 and t[:1].isalpha() and all(32 <= c < 127 for c in t)): return False
    return w1 & 0xffff == 0 and (w1 >> 24) <= 88 and ((w4 & 0xffff == 0 and (w4 >> 16) < 0x1000) or 0x80003100 <= w4 < 0x8035f3e0) and not 0x80000000 <= w3 < 0x80500000
tables = {}
for o, a, n in segs:
    x = a
    while x < a + n - 20:
        c = 0
        while is_row(x + 20 * c): c += 1
        if c >= 4: tables[x] = c; x += 20 * c
        else: x += 4
print({hex(a): c for a, c in tables.items()})
ex = json.load(open(f'{ROOT}/port/core/data/layout_exceptions.json'))
ex = [e for e in ex if not e.get('why', '').startswith('definición de recurso')]
total = 0
for a, c in tables.items():
    x = a
    while True:
        n = word(x)
        if n is None or not 0x8035f3e0 <= n < 0x804b3280 or not text(n): break
        ex.append(dict(addr=hex(x + 4), size=4, kind='raw', why='definición de recurso: bytes'))
        ex.append(dict(addr=hex(x + 12), size=4, kind='half', why='definición de recurso: u16'))
        if not 0x80000000 <= (word(x + 16) or 0) < 0x80500000: ex.append(dict(addr=hex(x + 16), size=4, kind='half', why='definición de recurso: u16'))
        total += 1; x += 20
        if c and c < 0x10000 and (x - a) // 20 >= c: break
print('registros', total)
# Otras dos formas importadas por 0x8017cafc/0x8017c9f4 (24 B: nombre, bytes, valor, u16, u16, flags o dos floats) y 0x8017cbec (8 B: nombre, bytes).
def named(x):
    n = word(x)
    if n is None or not 0x8035f3e0 <= n < 0x804b3280: return False
    t = text(n)
    return 2 <= len(t) < 64 and t[:1].isalpha() and all(32 <= c < 127 for c in t)
def kind_word(x):
    w = word(x)
    return w is not None and w & 0xffff == 0 and (w >> 24) <= 88
seen = {int(e['addr'], 16) for e in ex}
for stride in (24, 8):
    n_rows = 0
    for o, a, n in segs:
        x = a
        while x < a + n - stride:
            c = 0
            while named(x + stride * c) and kind_word(x + stride * c + 4) and x + stride * c + 4 not in seen: c += 1
            if c < 2: x += 4; continue
            # Filtra descriptores de propiedad y de tipo, que tienen esa forma con palabra +4 a cero.
            if not any(word(x + stride * k + 4) for k in range(c)): x += stride * c; continue
            for k in range(c):
                r = x + stride * k
                ex.append(dict(addr=hex(r + 4), size=4, kind='raw', why='definición de recurso: bytes')); seen.add(r + 4)
                if stride == 24:
                    for f, top in ((12, 0x100), (16, 0x1000), (20, 0x400)):
                        w = word(r + f)
                        if w and w & 0xffff == 0 and (w >> 16) < top: ex.append(dict(addr=hex(r + f), size=4, kind='half', why='definición de recurso: u16'))
            print('tabla', stride, hex(x), c, text(word(x))[:24]); n_rows += c
            x += stride * c
    print('filas', stride, n_rows)
# Filas sueltas junto a una tabla (como NULL, sola tras las de 24 B): {nombre, bytes} con tipo distinto de cero.
near = sorted(int(e['addr'], 16) for e in ex if e.get('why', '').startswith('definición de recurso: bytes'))
for a in near:
    for x in range(a, a + 0x48, 4):
        if x + 4 not in seen and named(x) and kind_word(x + 4) and word(x + 4) >> 24:
            ex.append(dict(addr=hex(x + 4), size=4, kind='raw', why='definición de recurso: bytes')); seen.add(x + 4)
            print('suelta', hex(x), text(word(x))[:24], hex(word(x + 4)))
json.dump(ex, open(f'{ROOT}/port/core/data/layout_exceptions.json', 'w'), indent=1)
