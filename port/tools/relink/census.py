#!/usr/bin/env python3
"""Censo de enlazado: de qué dirección original es cada símbolo de los objetos convertidos.

Lee los objetos de /tmp/w3dp/objs (lift_all.py) y clasifica símbolos definidos e indefinidos.
Salida: port/docs-data/relink-census.json
"""
import collections, concurrent.futures as cf, glob, json, os, re, subprocess

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
OBJS = sorted(glob.glob('/tmp/w3dp/objs/*.o'))
led = json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))
addr_syms = json.load(open(f'{ROOT}/port/docs-data/address-symbols.json'))

SECTIONS = [('text', 0x80003100, 0x8035f3e0), ('d7', 0x8035f3e0, 0x80368ca0), ('rodata', 0x80368ca0, 0x803eb620), ('data', 0x803eb620, 0x8041cb80),
            ('bss', 0x8041cb80, 0x804aa540), ('sdata', 0x804aa540, 0x804ac820), ('sbss', 0x804ac820, 0x804b1920), ('sdata2', 0x804b1920, 0x804b3260), ('sbss2', 0x804b3260, 0x804b3280)]
ZONES = [('sn_debug', 0x802e34a4, 0x802e541c), ('sn_shims', 0x802e541c, 0x802e5574), ('libm', 0x802e5574, 0x802e9eac), ('newlib', 0x802e9eac, 0x802f356c), ('libgcc', 0x802f356c, 0x802f4ef0),
         ('dolphin_sdk', 0x802f4ef0, 0x8031bedc), ('thp_asm_cw', 0x8031bedc, 0x80322838), ('musyx', 0x80322838, 0x80341260), ('savegpr', 0x803412b0, 0x80341348)]


def where(a):
    for n, s, e in ZONES:
        if s <= a < e: return n
    for n, s, e in SECTIONS:
        if s <= a < e: return 'game_text' if n == 'text' else n
    return 'other'


# Mapas de enlazado por unidad (analysis/lua-*-reference.ld): símbolo = dirección.
name2addr = collections.defaultdict(set)
LD_SYM = re.compile(r'^\s*"?([\w.$]+)"?\s*=\s*(0x[0-9a-fA-F]+)\s*;', re.M)
LD_SEC = re.compile(r'^\s*\.text\.([\w.$]+)\s+(0x[0-9a-fA-F]+)\s*:', re.M)
for p in glob.glob(f'{ROOT}/analysis/lua-*-reference.ld'):
    t = open(p, errors='replace').read()
    for s, a in LD_SYM.findall(t) + LD_SEC.findall(t):
        if not s.startswith('_SDA'): name2addr[s].add(int(a, 16))
for a, syms in addr_syms.items():
    for s in syms:
        if s not in name2addr: name2addr[s].add(int(a, 16))
led_name = {}
for f in led['functions']:
    led_name[f.get('name') or f.get('symbol')] = int(f['address'], 16)
led_addr = {int(f['address'], 16) for f in led['functions']}
SUFFIX = re.compile(r'(?:^|_)(?:0x)?(80[0-9a-fA-F]{6})(?:$|_)')


def resolve(name):
    """Devuelve (dirección o None, cómo)."""
    if name in led_name: return led_name[name], 'ledger'
    c = name2addr.get(name)
    if c and len(c) == 1: return next(iter(c)), 'recibos'
    m = SUFFIX.findall(name)
    if m: return int(m[-1], 16), 'sufijo'
    if c: return None, 'ambiguo'
    return None, 'sin_dato'


def scan(o):
    r = subprocess.run(['nm', '-g', '-m', o], capture_output=True, text=True, errors='replace')
    d = []; u = []
    for l in r.stdout.splitlines():
        m = re.match(r'\s*(?:[0-9a-f]+\s+)?\((.*?)\)\s+(.*?)\s*external\s+(\S+)', l)
        if not m: continue
        kind, extra, name = m.groups()
        name = name[1:] if name.startswith('_') else name
        if 'undefined' in kind: u.append(name)
        else: d.append((name, 'weak' in extra))
    return o, d, u


with cf.ThreadPoolExecutor(12) as ex:
    res = list(ex.map(scan, OBJS))

defined = collections.defaultdict(list); weak = collections.Counter(); undefined = collections.Counter()
for o, d, u in res:
    for n, w in d:
        if w: weak[n] += 1
        else: defined[n].append(o)
    for n in u: undefined[n] += 1

dup = {n: len(v) for n, v in defined.items() if len(v) > 1}
dup_led = {n: c for n, c in dup.items() if n in led_name}
strong_not_ledger = [n for n in defined if n not in led_name]
open_u = [n for n in undefined if n not in defined and n not in weak]
how = collections.Counter(); zone = collections.Counter(); zone_refs = collections.Counter(); unresolved = collections.Counter()
mangled = collections.Counter(); per_addr = collections.defaultdict(set); ambiguous = collections.Counter()
for n in open_u:
    a, h = resolve(n)
    how[h] += 1
    if n.startswith('_Z'): mangled[h] += 1
    if a is None:
        unresolved[n] = undefined[n]
        if h == 'ambiguo': ambiguous[n] = undefined[n]
        continue
    z = where(a); zone[z] += 1; zone_refs[z] += undefined[n]; per_addr[z].add(a)
def_addr = {}
for n in defined:
    a, h = resolve(n)
    if a is not None: def_addr.setdefault(a, []).append(n)
missing_text = sorted(a for a in per_addr['game_text'] if a not in def_addr)
in_ledger_missing = [a for a in missing_text if a in led_addr]
out = dict(
    objects=len(OBJS), strong_defined=len(defined), weak_defined=len(weak), undefined_refs_distinct=len(undefined), open_undefined=len(open_u),
    duplicate_strong=len(dup), duplicate_strong_in_ledger=len(dup_led), duplicate_examples=sorted(dup.items(), key=lambda x: -x[1])[:30],
    strong_not_in_ledger=len(strong_not_ledger), strong_not_in_ledger_examples=strong_not_ledger[:30],
    resolved_how=how.most_common(), mangled_how=mangled.most_common(),
    open_by_zone=zone.most_common(), open_refs_by_zone=zone_refs.most_common(), distinct_addresses_by_zone={k: len(v) for k, v in per_addr.items()},
    game_text_addresses_undefined=len(missing_text), of_which_admitted_but_failed_to_compile=len(in_ledger_missing),
    ledger_functions=len(led_addr), ledger_addresses_with_definition=len(led_addr & set(def_addr)),
    unresolved_top=unresolved.most_common(80), ambiguous_top=ambiguous.most_common(40),
)
json.dump(out, open(f'{ROOT}/port/docs-data/relink-census.json', 'w'), indent=1)
for k, v in out.items():
    if not k.endswith(('_top', '_examples')): print(k, v)
print('sin resolver', unresolved.most_common(25))
print('ambiguos', ambiguous.most_common(15))
print('duplicados', out['duplicate_examples'][:12])
print('fuertes fuera del registro', strong_not_ledger[:25])
