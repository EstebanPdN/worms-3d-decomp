#!/usr/bin/env python3
"""Stubs con rastro para las funciones del SDK aún sin implementar. No simulan nada: devuelven 0 y lo registran."""
import json, os, re, sys
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
d = json.load(open(f'{ROOT}/port/docs-data/sdk-boundary.json'))
done = set()
for f in os.listdir(f'{ROOT}/port/core/sdk'):
    if f.endswith('.cpp') and f != 'sdk_stubs.cpp':
        done |= {int(x, 16) for x in re.findall(r'\bA(80[0-9a-f]{6})\(', open(f'{ROOT}/port/core/sdk/{f}').read())}
out = ['// Generado por tools/relink/gen_sdk_stubs.py. Pendientes del SDK: devuelven 0 y dejan rastro con W3D_TRACE_SDK.',
       '#include <stdio.h>', '#include <stdlib.h>',
       'static int trace = -1;', 'static void note(const char *n, unsigned a) { if (trace < 0) trace = getenv("W3D_TRACE_SDK") != nullptr; if (trace) fprintf(stderr, "[sdk] %s (0x%08x)\\n", n, a); }', 'extern "C" {']
n = 0
for f in sorted(d['functions'], key=lambda x: x['address']):
    a = int(f['address'], 16)
    if a in done: continue
    if f['library'] == 'SN' or f['zone'] == 'sn_debug':
        pass
    name = re.sub(r'[^\w ]', '', f['name'])[:40]
    out.append(f'unsigned long A{a:08x}(void) {{ note("{name}", 0x{a:08x}u); return 0; }}'); n += 1
out.append('}')
open(f'{ROOT}/port/core/sdk/sdk_stubs.cpp', 'w').write('\n'.join(out) + '\n')
print('stubs de SDK', n, 'implementadas', len(done))
