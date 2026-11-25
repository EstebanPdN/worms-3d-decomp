#!/usr/bin/env python3
"""Censo de convenciones de llamada: para cada dirección, cómo la definen y cómo la llaman las unidades."""
import collections, glob, json, os, re

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
SIG = re.compile(r'^(define|declare)\s+(.*?)@("?(?:\\01)?[\w.$]+"?)\((.*)\)(.*)$')


def cls(t):
    t = t.strip()
    if 'sret(' in t or t.startswith('sret'): return 'R'
    # Los atributos dicen poco: lo que cuenta es el tipo de IR que queda.
    t = re.sub(r'\b(?:byref|byval|align|dereferenceable|dereferenceable_or_null|captures|range|initializes)\([^)]*\)', ' ', t)
    t = re.sub(r'\b(?:align \d+|noundef|nonnull|signext|zeroext|inreg|nocapture|readonly|writeonly|returned|noalias|nofree|nonlazybind|immarg)\b', ' ', t)
    t = re.sub(r'%[\w.$"-]+\s*$', '', t).strip()
    if t == 'ptr' or t.endswith('*'): return 'P'
    if t == 'i64': return 'L'
    if re.match(r'i\d+$', t): return 'I'
    if t == 'float': return 'F'
    if t == 'double': return 'D'
    if t == 'void': return 'V'
    if t == '...': return '...'
    if t == '[1 x i32]': return 'P'  # ARM: Ptr32 y demás tipos triviales de una palabra.
    if t.startswith('['): return 'A'
    return 'S'


def split_args(s):
    out = []; d = 0; cur = ''
    for c in s:
        if c in '([{<': d += 1
        elif c in ')]}>': d -= 1
        if c == ',' and d == 0: out.append(cur); cur = ''
        else: cur += c
    if cur.strip(): out.append(cur)
    return out


def ir_signatures(path):
    """[(kind, nombre, (ret, params))] de un .ll"""
    out = []
    for line in open(path, errors='replace'):
        if not line.startswith(('define', 'declare')): continue
        g = SIG.match(line.rstrip())
        if not g: continue
        kind, ret, name, args, tail = g.groups()
        rt = 'V'
        for tok in reversed(ret.split()):
            rt = cls(tok)
            if tok not in ('noundef', 'signext', 'zeroext'): break
        name = name.strip('"')
        # Con nombre de ensamblado, \\01 marca el símbolo tal cual, ya con su guion bajo.
        if name.startswith('\\01'): name = name[3:]; name = name[1:] if name.startswith('_') else name
        out.append((kind, name, (rt, tuple(cls(x) for x in split_args(args)))))
    return out


if __name__ != '__main__':
    raise_stop = True
else:
    raise_stop = False

if not raise_stop:
    pass
    ren = json.load(open('/tmp/w3dp/link/rename.json'))
    defs = {}; uses = collections.defaultdict(collections.Counter); seen = 0
    for s, m in ren.items():
        p = '/tmp/w3dp/ll/' + re.sub(r'[^\w]', '_', s) + '.ll'
        if not os.path.exists(p): continue
        seen += 1
        for line in open(p, errors='replace'):
            if not line.startswith(('define', 'declare')): continue
            g = SIG.match(line.rstrip())
            if not g: continue
            kind, ret, name, args, tail = g.groups()
            name = name.strip('"')
            new = m.get('_' + name)
            if not new or not re.fullmatch(r'_A[0-9a-f]{8}', new): continue
            a = new[1:]
            rtoks = ret.split()
            rt = 'V'
            for tok in reversed(rtoks):
                rt = cls(tok)
                if tok not in ('noundef', 'signext', 'zeroext'): break
            ps = tuple(cls(x) for x in split_args(args))
            sig = (rt, ps)
            if kind == 'define': defs[a] = sig
            else: uses[a][sig] += 1
    conf = collections.Counter(); ex = collections.defaultdict(list); addr_conf = collections.defaultdict(set); thunk = {}
    for a, us in uses.items():
        d = defs.get(a)
        if d is None: continue
        dr, dp = d
        for (ur, up), n in us.items():
            kinds = set()
            if ('...' in up) != ('...' in dp): kinds.add('variadico')
            for i in range(min(len(up), len(dp))):
                x, y = up[i], dp[i]
                if x == y or x == '...' or y == '...': continue
                if {x, y} <= {'I', 'L'}: continue
                if y == 'P' and x in 'IL': kinds.add('arg_int_a_puntero_real')
                elif x == 'P' and y in 'IL': continue  # El bajo de x0 es el puntero guardado.
                elif {x, y} & {'F', 'D'}: kinds.add('arg_float_int')
                elif 'R' in (x, y): kinds.add('sret')
                else: kinds.add('arg_otro')
            if len(up) < len(dp): kinds.add('menos_args')
            if ur != dr and ur != 'V' and dr != 'V' and not ({ur, dr} <= {'I', 'L'}):
                if dr in 'IL' and ur == 'P': kinds.add('ret_int_a_puntero_real')
                elif dr == 'P' and ur in 'IL': pass
                elif {ur, dr} & {'F', 'D'}: kinds.add('ret_float_int')
                else: kinds.add('ret_otro')
            if ur != 'V' and dr == 'V': kinds.add('ret_usado_de_void')
            for k in kinds:
                conf[k] += n; addr_conf[k].add(a)
                if len(ex[k]) < 6: ex[k].append((a, ur, up, dr, dp))
    res = dict(units=seen, defined=len(defs), used=len(uses), conflicts_uses=conf.most_common(), conflicts_addresses={k: len(v) for k, v in addr_conf.items()}, examples=ex, addresses={k: sorted(v) for k, v in addr_conf.items()})
    json.dump(res, open(f'{ROOT}/port/docs-data/abi-census.json', 'w'), indent=0, default=str)
    print({k: v for k, v in res.items() if k not in ('examples', 'addresses')})
    for k, v in ex.items(): print(k, str(v[:2])[:400])
