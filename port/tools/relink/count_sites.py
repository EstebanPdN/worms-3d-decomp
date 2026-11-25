#!/usr/bin/env python3
"""Funciones que incrementan o leen el contador de 16 bits en +0x22 de un registro de clase del DOL, y si su unidad ya lo corrige."""
import bisect, collections, json, os, re, struct
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
d = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
off = struct.unpack('>18I', d[:72]); addr = struct.unpack('>18I', d[0x48:0x90]); size = struct.unpack('>18I', d[0x90:0xd8])
led = json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))['functions']
fs = sorted((int(f['address'], 16), f) for f in led); ks = [a for a, _ in fs]
inv = sorted(int(f['address'], 16) for f in json.load(open(f'{ROOT}/analysis/inventario-no-recuperado.json'))['functions'])
units = collections.defaultdict(list); open_sites = []
for n in range(7):
    if not size[n]: continue
    regs = {}
    for k in range(0, size[n], 4):
        w = struct.unpack_from('>I', d, off[n] + k)[0]; op = w >> 26; rd = (w >> 21) & 31; ra = (w >> 16) & 31; imm = w & 0xffff; s = imm - 65536 if imm & 0x8000 else imm
        a = addr[n] + k
        if op == 15 and ra == 0: regs[rd] = (imm << 16) & 0xffffffff
        elif op == 14 and ra in regs: regs[rd] = (regs[ra] + s) & 0xffffffff
        elif op == 31 and ((w >> 1) & 0x3ff) == 444 and ((w >> 11) & 31) == rd and rd in regs: regs[ra] = regs[rd]   # mr
        elif op in (40, 44) and ra in regs and 0x80360000 <= (regs[ra] + s) & 0xffffffff < 0x8041cb80 and (regs[ra] + s) % 4 == 2 and s % 0x10000 == 0x22 or (op in (40, 44) and imm == 0x22 and ra in regs and 0x80360000 <= regs[ra] < 0x8041cb80):
            i = bisect.bisect_right(ks, a) - 1
            j = bisect.bisect_right(inv, a) - 1
            if j >= 0 and (i < 0 or inv[j] > ks[i]): open_sites.append(hex(inv[j]))
            else: units[fs[i][1]['source']].append(hex(ks[i]))
        elif op in (18, 19): regs = {} if op == 19 else regs
bad = []
for s, ads in units.items():
    q = re.sub(r'^source/matching/game', 'port/core/game', s); q = re.sub(r'^source/matching', 'port/core/engine', q); q = os.path.join(ROOT, q.rsplit('.', 1)[0] + '.cpp')
    t = open(q, errors='replace').read() if os.path.exists(q) else ''
    for inc in re.findall(r'#include "([^"]+)"', t):
        p = os.path.join(os.path.dirname(q), inc)
        if os.path.exists(p): t += open(p, errors='replace').read()
    if 'w3d_flags_high' not in t: bad.append((s, ads[:3]))
print('unidades', len(units), 'sin corregir', len(bad), 'abiertas', len(set(open_sites)))
json.dump(dict(bad=bad, open=sorted(set(open_sites))), open(f'{ROOT}/port/docs-data/count-sites.json', 'w'), indent=0)
for s, a in bad[:20]: print(' ', s.split('/')[-1], a)
print(sorted(set(open_sites))[:20])
