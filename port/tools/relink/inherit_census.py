#!/usr/bin/env python3
"""Argumentos heredados: registros r4-r10 y f1-f8 que una función del original lee sin escribir antes.

GCC deja vivos los registros de argumento entre llamadas: una función declarada con un argumento puede reenviar r4
a quien llama sin mencionarlo. En arm64 esos registros se pisan. Se calcula, sobre el listado PPC, qué registros de
entrada usa de verdad cada función (siguiendo las llamadas directas) y se compara con lo que declara su unidad.
Salida: port/docs-data/inherit-census.json
"""
import collections, glob, json, os, re, sys
sys.path.insert(0, os.path.dirname(__file__))
from abi_census import cls, split_args, SIG

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
ARGS = {f'r{i}' for i in range(3, 11)} | {f'f{i}' for i in range(1, 9)}
CLOBBER = {f'r{i}' for i in list(range(0, 1)) + list(range(3, 13))} | {f'f{i}' for i in range(0, 14)}
REG = re.compile(r'\b([rf]\d+)\b')
NOWRITE = re.compile(r'^(st|cmp|fcmp|tw|mt|dc|ic|sync|isync|eieio|ps_cmp|psq_st|rfi|sc|crclr|crset|cror|crxor|crnot)')
BR = re.compile(r'^b[a-z]*[-+]?$')


def parse(path):
    out = []
    for l in open(path, errors='replace'):
        p = l.split(None, 3)
        if len(p) < 3: continue
        try: ad = int(p[0], 16)
        except ValueError: continue
        out.append((ad, p[2], p[3].strip() if len(p) > 3 else ''))
    return out


def effects(mn, ops):
    regs = REG.findall(ops)
    if NOWRITE.match(mn): return regs, []
    if not regs: return [], []
    first = ops.split(',')[0].strip()
    if first in regs:
        reads = regs[1:]
        if mn.startswith(('rlwimi', 'fmadd', 'fmsub', 'fnmadd', 'fnmsub')): reads = regs
        return reads, [first]
    return regs, []


funcs = {}
for f in glob.glob(f'{ROOT}/source/recovered/refined/functions/*/*.asm'):
    a = int(os.path.basename(f)[:-4], 16)
    funcs[a] = parse(f)
live = {a: set() for a in funcs}
info = {}


def analyse(a):
    ins = funcs[a]
    idx = {x[0]: i for i, x in enumerate(ins)}
    state = [None] * len(ins)
    if not ins: return set()
    state[0] = frozenset()
    reads_out = set(); work = [0]
    while work:
        i = work.pop()
        st = state[i]; ad, mn, ops = ins[i]
        succ = []; w = set(st)
        target = None
        m = re.search(r'0x([0-9a-f]+)', ops)
        if m: target = int(m.group(1), 16)
        if BR.match(mn):
            base = mn.rstrip('+-')
            if base in ('bl', 'bla'):
                reads_out |= (live.get(target, set()) - w)
                w |= CLOBBER; succ = [i + 1]
            elif base in ('bctrl', 'blrl') or base.endswith('ctrl') or base.endswith('lrl'):
                r, _ = effects('st', ops)
                # Reenvío virtual fino: una función corta suele pasar sus argumentos al método sin nombrarlos.
                # Reenvío virtual fino: una sola llamada, sin más trabajo; los argumentos siguen vivos en los registros.
                calls_ = [x for x in ins if x[1].rstrip('+-') in ('bl', 'bla', 'bctrl', 'blrl') or x[1].rstrip('+-').endswith(('ctrl', 'lrl'))]
                if len(ins) <= 24 and len(calls_) == 1: reads_out |= ({'r4', 'r5', 'r6', 'r7', 'r8'} - w)
                w |= CLOBBER; succ = [i + 1]
            elif base == 'b':
                if target in idx: succ = [idx[target]]
                else: reads_out |= (live.get(target, set()) - w)
            elif base in ('blr', 'bctr', 'rfi') or (base.endswith('lr') and base != 'blr') :
                succ = [] if base in ('blr', 'bctr', 'rfi') else [i + 1]
            else:
                succ = [i + 1]
                if target in idx: succ.append(idx[target])
        else:
            r, wr = effects(mn, ops)
            reads_out |= {x for x in r if x in ARGS and x not in w}
            w |= set(wr)
            succ = [i + 1]
        fw = frozenset(w)
        for s in succ:
            if s >= len(ins): continue
            if state[s] is None:
                state[s] = fw; work.append(s)
            else:
                n = state[s] & fw
                if n != state[s]:
                    state[s] = n; work.append(s)
    # Una variádica guarda todos los registros de argumento en su zona: eso no dice lo que usa de verdad.
    if {f'f{i}' for i in range(1, 9)} <= reads_out or {'r7', 'r8', 'r9', 'r10'} <= reads_out: return {'r3'} & reads_out
    return reads_out & ARGS


changed = True; rounds = 0
while changed and rounds < 30:
    changed = False; rounds += 1
    for a in funcs:
        n = analyse(a)
        if n != live[a]:
            live[a] = n; changed = True
print('rondas', rounds, 'funciones', len(funcs))

ren = json.load(open('/tmp/w3dp/link/rename.json'))
defs = {}
for s, m in ren.items():
    p = '/tmp/w3dp/ll/' + re.sub(r'[^\w]', '_', s) + '.ll'
    if not os.path.exists(p): continue
    for line in open(p, errors='replace'):
        if not line.startswith('define'): continue
        g = SIG.match(line.rstrip())
        if not g: continue
        _, ret, name, args, _t = g.groups()
        new = m.get('_' + name.strip('"'), '').split('__')[0]
        if re.fullmatch(r'_A[0-9a-f]{8}', new):
            defs[int(new[2:], 16)] = (s, name.strip('"'), tuple(cls(x) for x in split_args(args)))
res = []
for a, (s, name, ps) in defs.items():
    if a not in live or '...' in ps: continue
    ints = sum(1 for x in ps if x in 'ILPSAR'); fps = sum(1 for x in ps if x in 'FD')
    li = [int(x[1:]) for x in live[a] if x[0] == 'r']; lf = [int(x[1:]) for x in live[a] if x[0] == 'f']
    need_i = max(li) - 2 if li else 0; need_f = max(lf) if lf else 0
    if need_i > ints or need_f > fps:
        res.append(dict(addr=hex(a), name=name, source=s, declared=''.join(ps), need_int=need_i, need_fp=need_f, ints=ints, fps=fps))
res.sort(key=lambda x: x['addr'])
json.dump(res, open(f'{ROOT}/port/docs-data/inherit-census.json', 'w'), indent=0)
print('definidas', len(defs), 'con registros de más', len(res))
print(collections.Counter((r['need_int'] - r['ints'], r['need_fp'] - r['fps']) for r in res).most_common(12))
for r in res[:40]: print(r['addr'], r['name'][:44], r['declared'], 'necesita', r['need_int'], r['need_fp'])
