#!/usr/bin/env python3
"""Tipos de los datos fijos del DOL según lo que declaran las unidades admitidas.

Para cada variable global con dirección en su mapa de enlazado se calcula la disposición PPC de su tipo y se
vota, byte a byte, cómo convertir esos datos al cargar. Los campos de relleno (pad, unknown, u12...) no votan.
Salida: port/core/data/layout_types.json. No contiene datos del juego, solo tipos.
"""
import collections, concurrent.futures as cf, glob, json, os, re, subprocess, sys

sys.path.insert(0, os.path.dirname(__file__))
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '../lift'))
import symbols as S
from lift import AST_C, AST_CXX, AST_TARGET, CLANG

ROOT = S.ROOT
led = json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))
srcs = sorted({f['source'] for f in led['functions'] if f['source'].startswith('source/')})
inc = {}
for mf in glob.glob(f'{ROOT}/config/GWMP8P/game-units/*.json'):
    try: m = json.load(open(mf))
    except Exception: continue
    if 'source' in m: inc[m['source']] = m.get('include_dirs', [])
maps = S.load_unit_maps()
DATA_LO, DATA_HI = 0x8035f3e0, 0x804b3280
PAD = re.compile(r'^(?:_*(?:pad|unknown|unk|gap|rest|tail|reserved|filler|opaque|bytes|data|raw|storage|mem|buf|buffer|u|p|q|r|x|y)_?\d*|.*(?:pad|unknown|gap).*)$', re.I)
BUILTIN = {'char': (1, 'raw'), 'signed char': (1, 'raw'), 'unsigned char': (1, 'raw'), 'bool': (1, 'raw'), 'short': (2, 'half'), 'unsigned short': (2, 'half'),
           'short int': (2, 'half'), 'int': (4, 'word'), 'unsigned int': (4, 'word'), 'unsigned': (4, 'word'), 'long': (4, 'word'), 'unsigned long': (4, 'word'),
           'float': (4, 'float'), 'double': (8, 'double'), 'long long': (8, 'skip'), 'unsigned long long': (8, 'skip')}


def unit_map(s):
    u = os.path.basename(s).rsplit('.', 1)[0]
    for k in ('game-game_' + u, 'game-' + u, u):
        if k in maps: return maps[k]
    return {}


class Types:
    def __init__(self):
        self.records = {}; self.typedefs = {}

    def walk(self, n):
        k = n.get('kind')
        if k in ('RecordDecl', 'CXXRecordDecl') and n.get('completeDefinition') and n.get('name'):
            self.records[n['name']] = n
        elif k == 'TypedefDecl' and n.get('name'):
            self.typedefs[n['name']] = n.get('type', {}).get('qualType', '')
        for c in n.get('inner', []): self.walk(c)

    def layout(self, ty, out, base, depth=0):
        """Añade (desplazamiento, tamaño, clase) y devuelve (tamaño, alineación). None si no se entiende."""
        if depth > 12: return None
        ty = re.sub(r'\b(?:const|volatile|struct|union|class|enum)\b', ' ', ty).strip()
        ty = re.sub(r'\s+', ' ', ty)
        m = re.fullmatch(r'(.+?) ?\[(\d+)\]', ty)
        if m:
            n = int(m.group(2))
            first = len(out)
            sub = self.layout(m.group(1), out, base, depth + 1)
            if not sub: return None
            one = out[first:]
            for i in range(1, n):
                out.extend((o + i * sub[0], z, c) for o, z, c in one)
            return sub[0] * n, sub[1]
        if ty.endswith('*') or '(*)' in ty or '&' in ty:
            out.append((base, 4, 'word')); return 4, 4
        if ty in BUILTIN:
            z, c = BUILTIN[ty]
            if c != 'skip': out.append((base, z, c))
            return z, z
        if ty in self.typedefs and self.typedefs[ty] != ty:
            return self.layout(self.typedefs[ty], out, base, depth + 1)
        r = self.records.get(ty)
        if r is None:
            if re.fullmatch(r'\w+', ty): out.append((base, 4, 'word')); return 4, 4  # enum o desconocido
            return None
        off = 0; align = 1; size = 0
        is_union = r.get('tagUsed') == 'union'
        bases = [c for c in r.get('bases', [])]
        if bases: return None
        for f in r.get('inner', []):
            if f.get('kind') != 'FieldDecl': continue
            if f.get('isBitfield'): return None
            ft = f.get('type', {}).get('qualType', '')
            name = f.get('name', '')
            sub_out = []
            sub = self.layout(ft, sub_out, 0, depth + 1)
            if not sub: return None
            z, a = sub
            align = max(align, a)
            start = 0 if is_union else (off + a - 1) // a * a
            if not PAD.match(name or 'pad') and not is_union:
                out.extend((base + start + o, sz, c) for o, sz, c in sub_out)
            off = start + z
            size = max(size, off)
        return (size + align - 1) // align * align, align


def scan(s):
    p = os.path.join(ROOT, s)
    lang = AST_C if s.endswith('.c') else AST_CXX
    fl = []
    for d in inc.get(s, []) + ['source/matching', os.path.dirname(s), 'tools/reference-headers']:
        fl.append('-I' + os.path.join(ROOT, d))
    r = subprocess.run([CLANG] + AST_TARGET + ['-fsyntax-only', '-w', '-Xclang', '-ast-dump=json', '-ferror-limit=0', '-funsigned-char', '-D__W3D_PORT__=1'] + fl + lang + [p], capture_output=True, errors='replace')
    if not r.stdout: return []
    try: ast = json.loads(r.stdout)
    except Exception: return []
    t = Types(); t.walk(ast)
    um = unit_map(s)
    res = []
    for n in ast.get('inner', []):
        stack = [n]
        while stack:
            d = stack.pop()
            if d.get('kind') == 'LinkageSpecDecl': stack.extend(d.get('inner', [])); continue
            if d.get('kind') != 'VarDecl' or not d.get('name'): continue
            name = d.get('mangledName', d['name'])
            ad = um.get(d['name'])
            if ad is None: m = re.search(r'(?:^|_)(80[0-9a-f]{6})$', d['name'], re.I); ad = int(m.group(1), 16) if m else None
            if ad is None or not DATA_LO <= ad < DATA_HI: continue
            out = []
            ty = d.get('type', {}).get('qualType', '')
            # Un array de char sin tamaño es una etiqueta sin tipo: no dice nada de lo que hay detrás.
            if re.fullmatch(r'(?:const |volatile )*(?:signed |unsigned )?char \[\]', ty): continue
            # Un array sin tamaño no dice cuánto ocupa: solo su primer elemento.
            ty = re.sub(r'\[\]$', '[1]', ty)
            if t.layout(ty, out, 0): res.extend((ad + o, z, c) for o, z, c in out)
    return res


votes = collections.defaultdict(collections.Counter)
with cf.ThreadPoolExecutor(12) as ex:
    for r in ex.map(scan, srcs):
        for a, z, c in r:
            for b in range(a, a + z): votes[b][(a if c != 'raw' else b, z, c)] += 1
runs = []
kinds = {}
for b, v in votes.items():
    cs = collections.Counter()
    for (a, z, c), n in v.items(): cs[c] += n
    # Un byte declarado como palabra y como char a la vez se queda en palabra: los char suelen ser vistas parciales.
    if 'raw' in cs and len(cs) > 1: del cs['raw']
    kinds[b] = cs.most_common(1)[0][0]
for b in sorted(kinds):
    if runs and runs[-1]['end'] == b and runs[-1]['kind'] == kinds[b]: runs[-1]['end'] = b + 1
    else: runs.append(dict(start=b, end=b + 1, kind=kinds[b]))
json.dump([dict(addr=hex(r['start']), size=r['end'] - r['start'], kind=r['kind']) for r in runs], open(f'{ROOT}/port/core/data/layout_types.json', 'w'), indent=0)
print('tramos', len(runs), collections.Counter(r['kind'] for r in runs), 'bytes', collections.Counter(kinds.values()))
