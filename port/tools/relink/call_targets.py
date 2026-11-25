#!/usr/bin/env python3
"""Dirección de lo que una unidad llama y el enlace no sabe nombrar: compila con ProDG y lee el destino del bl en el original.

Entrada: /tmp/w3dp/link/unresolved-by-src.json (lo escribe link_all.py). Salida: port/docs-data/call-targets.json {fuente: {símbolo: dirección}}.
"""
import concurrent.futures as cf, json, os, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(__file__))
import vtable_prodg as V
ROOT = V.ROOT
OPS = {'operator=': 'as', 'operator<<': 'ls', 'operator>>': 'rs', 'operator==': 'eq', 'operator!=': 'ne', 'operator<': 'lt', 'operator[]': 'vc', 'operator+': 'pl', 'operator+=': 'apl', 'operator new': 'nw', 'operator delete': 'dl'}
def key_of(sym, demangled):
    """Prefijo del nombre GCC 2.95 que corresponde al símbolo de clang."""
    if sym.startswith('__._'): return sym[1:]                                        # destructor explícito: mismo nombre
    if demangled.startswith('void '): demangled = demangled[5:]
    head = re.sub(r'\(.*$', '', demangled); head = re.sub(r'<.*', lambda m: '', head) if '::' not in head else head
    parts = re.sub(r'<[^<>]*(?:<[^<>]*(?:<[^<>]*>[^<>]*)*>[^<>]*)*>', '', head).split('::')
    last = parts[-1].strip(); cls = parts[-2].strip() if len(parts) > 1 else None
    if last in OPS: return f'__{OPS[last]}__'
    if cls and last == cls: return f'__{len(cls)}{cls}'                              # constructor
    return last + '__'


def args_code(demangled):
    """Final del nombre GCC 2.95 para los argumentos de clang: solo los casos con un argumento simple."""
    m = re.search(r'\(([^()]*)\)(?: const)?$', demangled)
    if not m: return None
    a = m[1].strip()
    table = {'char const*': 'PCc', 'unsigned int': 'Ui', 'int': 'i', 'float': 'f', 'bool': 'b', 'char': 'c'}
    if a in table: return table[a]
    r = re.fullmatch(r'(\w+) const&', a)
    if r: return f'RC{len(r[1])}{r[1]}'
    return None


def one(item):
    src, syms = item; m = V.manifests.get(src, {})
    dem = subprocess.run(['c++filt'], input='\n'.join(syms), text=True, capture_output=True).stdout.split('\n')
    inc = [f'-I{ROOT}/{d}' for d in m.get('include_dirs', [])]
    with tempfile.TemporaryDirectory() as d:
        for c in ([V.WIBO, f'{V.TOOL}/cpp.exe', '-nostdinc', f'-I{ROOT}/tools/reference-headers', f'-I{ROOT}/tools/reference-headers/lib', f'-I{ROOT}/source/matching', *inc, f'-I{ROOT}/{os.path.dirname(src)}', '-D__PPC__=1', '-D_CALL_SYSV=1', '-D__cplusplus=1', '-D__GNUG__=2', f'{ROOT}/{src}', f'{d}/m.i'],
                  [V.WIBO, f'{V.TOOL}/cc1plus.exe', '-quiet', '-O2', '-msdata=eabi', '-G', '8', '-ffunction-sections', *m.get('extra_flags', []), f'{d}/m.i', '-o', f'{d}/m.s']):
            r = subprocess.run(c, capture_output=True, text=True, cwd=d)
            if r.returncode: return src, {}, ['no compila: ' + (r.stderr or '')[-120:]]
        lines = open(f'{d}/m.s', errors='replace').read().splitlines()
    funcs = {**V.addr_of.get(src, {}), **{k: int(v, 16) for k, v in m.get('functions', {}).items()}}
    calls = []; cur = None; idx = 0
    for l in lines:
        if re.match(r'^[A-Za-z_.$][\w.$]*:', l):
            lab = l.split(':')[0]
            if not lab.startswith('.'): cur = lab; idx = 0
            continue
        g = V.INSN.match(l)
        if not g or g[1].startswith('.'): continue
        if g[1] in ('bl', 'b') and cur in funcs:
            name = g[2].strip()
            if not name.startswith('.'):
                site = funcs[cur] + idx * 4; w = V.word(site)
                if w is not None and w >> 26 == 18:
                    li = w & 0x3fffffc; li = li - 0x4000000 if li & 0x2000000 else li
                    calls.append((name, (site + li) & 0xffffffff))
        idx += 1
    out = {}; miss = []
    for s, x in zip(syms, dem):
        k = key_of(s, x)
        targets = {t for n, t in calls if n.startswith(k)}
        if len(targets) > 1:
            code = args_code(x)
            if code is not None: targets = {t for n, t in calls if n.startswith(k) and n.endswith(code)}
            v = re.search(r'vector<([\w ]+?)(?:,|>)', x)
            if v:
                e = {'unsigned char': 'Uc', 'float': 'f', 'int': 'i', 'unsigned int': 'Ui', 'char': 'c', 'short': 's', 'unsigned short': 'Us'}.get(v[1].strip(), f'{len(v[1].strip())}{v[1].strip()}')
                targets = {t for n, t in calls if n.startswith(k) and f't6vector2Z{e}Z' in n}
        if len(targets) == 1: out[s] = hex(targets.pop())
        else: miss.append(f'{s} [{k}] {len(targets)}')
    return src, out, miss


if __name__ == '__main__':
    data = json.load(open('/tmp/w3dp/link/unresolved-by-src.json'))
    old = json.load(open(f'{ROOT}/port/docs-data/call-targets.json')) if os.path.exists(f'{ROOT}/port/docs-data/call-targets.json') else {}
    miss_all = {}
    with cf.ThreadPoolExecutor(6) as ex:
        for s, o, miss in ex.map(one, sorted(data.items())):
            if o: old.setdefault(s, {}).update(o)
            if miss: miss_all[s] = miss
    json.dump(old, open(f'{ROOT}/port/docs-data/call-targets.json', 'w'), indent=0)
    print('unidades', len(data), 'resueltos', sum(map(len, old.values())), 'sin resolver', sum(map(len, miss_all.values())))
    for s, m in list(miss_all.items())[:30]: print(' ', os.path.basename(s), m[:3])
