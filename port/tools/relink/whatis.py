#!/usr/bin/env python3
"""Qué es una dirección: unidad, nombres, error de compilación y pseudocódigo. Uso: whatis.py 0x80209a70 [líneas]"""
import json, os, sys
sys.path.insert(0, os.path.dirname(__file__))
import symbols as S
R = S.ROOT
a = int(sys.argv[1], 16); nl = int(sys.argv[2]) if len(sys.argv) > 2 else 0
led = {int(f['address'], 16): f for f in json.load(open(f'{R}/analysis/recovery-ledger.json'))['functions']}
inv = {int(f['address'], 16): f for f in json.load(open(f'{R}/analysis/inventario-no-recuperado.json'))['functions']}
g = S.load_global(); names = sorted(n for n, ads in g.items() if a in ads)
print(hex(a), S.where(a), 'nombres', names[:6])
f = led.get(a)
if f:
    print('admitida', f.get('name'), f['bytes'], f['source'])
    e = json.load(open('/tmp/w3dp/lift-errors.json')).get(f['source'])
    if e: print('error', e[:3])
elif a in inv: print('sin recuperar', inv[a])
p = f'{R}/source/recovered/refined/functions/{a >> 16:04x}/{a:08x}.c'
if nl and os.path.exists(p): print(''.join(open(p).readlines()[:nl]))
