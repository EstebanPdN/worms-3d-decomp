#!/usr/bin/env python3
"""Dirección exacta de cada tabla virtual: compila la unidad con ProDG y lee en el original los bytes de cada __vt_X@ha/@l.

La fuente admitida reproduce los bytes del juego, así que la instrucción n de la función compilada es la instrucción n del original.
Requiere Rosetta (tools/bin/wibo es x86_64). Salida: port/docs-data/vtables-prodg.json {fuente: {__vt_X: dirección}}.
"""
import concurrent.futures as cf, glob, json, os, re, struct, subprocess, tempfile
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
TOOL = f'{ROOT}/tools/compilers/ProDG-v3.7/ProDG-v3.7'; WIBO = f'{ROOT}/tools/bin/wibo'
dol = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
off = struct.unpack_from('>18I', dol, 0); adr = struct.unpack_from('>18I', dol, 0x48); siz = struct.unpack_from('>18I', dol, 0x90)
def word(a):
    for o, s, n in zip(off, adr, siz):
        if n and s <= a < s + n: return struct.unpack_from('>I', dol, o + a - s)[0]
manifests = {}
for p in glob.glob(f'{ROOT}/config/GWMP8P/game-units/*.json'):
    try: m = json.load(open(p))
    except Exception: continue
    if 'source' in m: manifests.setdefault(m['source'], m)
led = json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))['functions']
addr_of = {}
for f in led: addr_of.setdefault(f['source'], {})[f.get('name')] = int(f['address'], 16)
INSN = re.compile(r'^\s+([a-z][\w.+-]*)\b(.*)$')


def one(src):
    m = manifests.get(src, {}); lang = 'cpp'
    inc = [f'-I{ROOT}/{d}' for d in m.get('include_dirs', [])]
    with tempfile.TemporaryDirectory() as d:
        pre = [WIBO, f'{TOOL}/cpp.exe', '-nostdinc', f'-I{ROOT}/tools/reference-headers', f'-I{ROOT}/tools/reference-headers/lib', f'-I{ROOT}/source/matching', *inc, f'-I{ROOT}/{os.path.dirname(src)}',
               '-D__PPC__=1', '-D_CALL_SYSV=1', '-D__cplusplus=1', '-D__GNUG__=2', f'{ROOT}/{src}', f'{d}/m.i']
        cc = [WIBO, f'{TOOL}/cc1plus.exe', '-quiet', '-O2', '-msdata=eabi', '-G', '8', '-ffunction-sections', *m.get('extra_flags', []), f'{d}/m.i', '-o', f'{d}/m.s']
        for c in (pre, cc):
            r = subprocess.run(c, capture_output=True, text=True, cwd=d)
            if r.returncode: return src, None, (r.stderr or r.stdout)[-200:]
        lines = open(f'{d}/m.s', errors='replace').read().splitlines()
    funcs = {**addr_of.get(src, {}), **{k: int(v, 16) for k, v in m.get('functions', {}).items()}}
    out = {}; bad = []; cur = None; idx = 0; pend = {}
    for l in lines:
        if re.match(r'^[A-Za-z_.$][\w.$]*:', l):
            lab = l.split(':')[0]
            if not lab.startswith('.'): cur = lab; idx = 0; pend = {}
            continue
        g = INSN.match(l)
        if not g or g[1].startswith('.'): continue
        for sym, part in re.findall(r'((?:__vt_|_vt[.$])[\w.$]+)@(ha|l)\b', g[2]):
            sym = re.sub(r'^_vt[.$]', '__vt_', sym)
            a = funcs.get(cur)
            if a is None: bad.append(f'{sym} en {cur} sin dirección'); continue
            w = word(a + idx * 4)
            if part == 'ha': pend[sym] = (w & 0xffff) << 16
            elif sym in pend:
                lo = w & 0xffff; lo = lo - 0x10000 if lo & 0x8000 else lo
                out[sym] = hex(pend[sym] + lo)
        idx += 1
    return src, out, bad[:3]


if __name__ == '__main__':
    srcs = set()
    for r, _, fs in os.walk(f'{ROOT}/source/matching'):
        for f in fs:
            if f.endswith(('.cpp', '.h')):
                p = os.path.join(r, f)
    lifted = {}
    for f in led:
        s = f['source']
        if s in lifted: continue
        q = re.sub(r'^source/matching/game', 'port/core/game', s); q = re.sub(r'^source/matching', 'port/core/engine', q); q = re.sub(r'^source/vendor', 'port/core/vendor', q)
        q = os.path.join(ROOT, q.rsplit('.', 1)[0] + '.cpp')
        lifted[s] = q
    targets = []
    for s, q in lifted.items():
        if os.path.exists(q):
            t = open(q, errors='replace').read()
            hs = [os.path.join(os.path.dirname(q), i) for i in re.findall(r'#include "([^"]+)"', t)]
            if 'W3D_SET_VPTR' in t or any(os.path.exists(h) and 'W3D_SET_VPTR' in open(h, errors='replace').read() for h in hs): targets.append(s)
    res = {}; errs = {}
    with cf.ThreadPoolExecutor(6) as ex:
        for s, o, e in ex.map(one, sorted(targets)):
            if o is None: errs[s] = e
            else:
                res[s] = o
                if e: errs[s] = e
    json.dump(dict(resolved=res, errors=errs), open(f'{ROOT}/port/docs-data/vtables-prodg.json', 'w'), indent=0)
    print('unidades', len(targets), 'compiladas', len(res), 'tablas', sum(map(len, res.values())), 'errores', len(errs))
    for s, e in list(errs.items())[:8]: print(' ', os.path.basename(s), str(e)[:150])
