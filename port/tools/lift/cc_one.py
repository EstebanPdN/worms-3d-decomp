#!/usr/bin/env python3
"""Compila una fuente convertida y muestra los errores completos. Uso: cc_one.py source/matching/... [n_lineas]"""
import json, os, subprocess, sys
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
MAP = [('source/matching/game', 'port/core/game'), ('source/matching', 'port/core/engine'), ('source/vendor', 'port/core/vendor')]
def conv(p):
    for a, b in MAP:
        if p == a or p.startswith(a + '/'): return b + p[len(a):]
    return p
s = sys.argv[1]; n = int(sys.argv[2]) if len(sys.argv) > 2 else 40
out = conv(s); out = out[:-2] + '.cpp' if out.endswith('.c') else out
inc = []
mf = os.path.join(ROOT, 'config/GWMP8P/game-units', os.path.basename(s).rsplit('.', 1)[0] + '.json')
if os.path.exists(mf):
    inc = json.load(open(mf)).get('include_dirs', [])
fl = []
for d in inc + ['source/matching', os.path.dirname(s)]:
    fl += ['-I', os.path.join(ROOT, conv(d))]
r = subprocess.run([f'{ROOT}/port/tools/lift/cc_core.sh', 'arm64-apple-macos14', os.environ.get('W3D_TMP', '/tmp/w3dp') + '/one.o', os.path.join(ROOT, out), '-ferror-limit=0'] + fl + [f'-I{ROOT}/port/core/runtime', f'-I{ROOT}/port/core', f'-I{ROOT}/port/core/lua/include'], capture_output=True, text=True, errors='replace')
print('\n'.join(l.replace(ROOT + '/', '') for l in r.stderr.splitlines()[:n]))
print('rc', r.returncode)
