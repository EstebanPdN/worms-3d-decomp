#!/usr/bin/env python3
"""Símbolos del núcleo: de nombre de cada unidad a dirección original.

Cada unidad admitida tiene su mapa de enlazado (analysis/lua-*-reference.ld). Dos unidades pueden usar el
mismo nombre para funciones distintas (String::String existe en 196 versiones), así que la resolución
es siempre por unidad. El símbolo canónico de una dirección es A<dirección>.
"""
import collections, glob, json, os, re, subprocess

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
LD_SYM = re.compile(r'^\s*"?([\w.$]+)"?\s*=\s*(0x[0-9a-fA-F]+)\s*;', re.M)
LD_SEC = re.compile(r'^\s*\.text\.([\w.$]+)\s+(0x[0-9a-fA-F]+)\s*:', re.M)
LD_LINKONCE = re.compile(r'^\s*\.gnu\.linkonce\.t\.([\w.$]+)\s+(0x[0-9a-fA-F]+)\s*:', re.M)
LD_BLOCK = re.compile(r'^\s*\.(?:sdata|sbss|bss|data|rodata|sdata2|sbss2)\s+(0x[0-9a-fA-F]+)\s*(?:\(NOLOAD\))?\s*:\s*\{(.*?)\}', re.M | re.S)
LD_DOT = re.compile(r'\.\s*=\s*(0x[0-9a-fA-F]+)\s*;\s*([\w.$]+)\s*=\s*\.')
SUFFIX = re.compile(r'(?:^|_)(?:0x)?(80[0-9a-fA-F]{6})(?:$|_|\b)')
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


def canon(a): return 'A%08x' % a


def unit_id(source):
    """lua-game-game_d24c_x_800f30f0-reference.ld a partir de source/matching/game/d24c/x.cpp."""
    return os.path.basename(source).rsplit('.', 1)[0]


def load_unit_maps():
    maps = {}
    for p in glob.glob(f'{ROOT}/analysis/lua-*-reference.ld'):
        key = os.path.basename(p)[len('lua-'):-len('-reference.ld')]
        t = open(p, errors='replace').read()
        m = {}
        for s, a in LD_SYM.findall(t) + LD_SEC.findall(t) + LD_LINKONCE.findall(t):
            if not s.startswith('_SDA'): m[s] = int(a, 16)
        # Datos colocados dentro de un bloque: .sdata 0x804ac668 : { . = 0x3fa8; nombre = .; }
        for base, inner in LD_BLOCK.findall(t):
            for off, name in LD_DOT.findall(inner):
                m[name] = int(base, 16) + int(off, 16)
        maps[key] = m
    return maps


def load_global():
    g = collections.defaultdict(set)
    for m in load_unit_maps().values():
        for s, a in m.items(): g[s].add(a)
    for a, syms in json.load(open(f'{ROOT}/port/docs-data/address-symbols.json')).items():
        for s in syms:
            if s not in g: g[s].add(int(a, 16))
    return g


def _qualified_last(t):
    """Último componente de un nombre calificado GCC 2.95: Q24_STLt8hash_map5Z... da hash_map."""
    m = re.match(r'Q(?:_(\d+)_|(\d))', t)
    if not m: return None
    n = int(m.group(1) or m.group(2)); i = m.end(); name = None
    for k in range(n):
        tmpl = i < len(t) and t[i] == 't'
        if tmpl: i += 1
        d = re.compile(r'\d+').match(t, i)
        if not d: return None
        ln = int(d.group(0)); i = d.end()
        name = t[i:i + ln]; i += ln
        if tmpl and k != n - 1: return None
    return name


def parse_gcc2(sym):
    """(clase, método) de un nombre GCC 2.95. Devuelve None si no es un miembro sencillo."""
    m = re.match(r'_\._(\d+)(\w+)$', sym)
    if m and int(m.group(1)) == len(m.group(2)): return m.group(2), '~'
    m = re.match(r'_\._(Q.*)$', sym)
    if m:
        c = _qualified_last(m.group(1))
        return (c, '~') if c else None
    m = re.match(r'(?:_vt[._]|__vt_)(\d+)(\w+)$', sym)
    if m and int(m.group(1)) == len(m.group(2)): return m.group(2), 'vtable'
    OPS = {'nw': 'new', 'dl': 'delete', 'vn': 'new[]', 'vd': 'delete[]', 'as': 'operator=', 'eq': 'operator==', 'ne': 'operator!=', 'pl': 'operator+', 'apl': 'operator+=', 'ls': 'operator<<', 'vc': 'operator[]', 'ml': 'operator*', 'pp': 'operator++'}
    m = re.match(r'__(nw|dl|vn|vd|as|eq|ne|pl|apl|ls|vc|ml|pp)__(.*)$', sym)
    if m:
        rest = m.group(2).lstrip('C')
        q = _qualified_last(rest)
        if q: return q, OPS[m.group(1)]
        d = re.match(r'(\d+)(\w+)$', rest)
        if d: return d.group(2)[:int(d.group(1))], OPS[m.group(1)]
        d = re.match(r't(\d+)(\w+)$', rest)
        if d: return d.group(2)[:int(d.group(1))], OPS[m.group(1)]
        return None
    m = re.match(r'__(Q.*)$', sym)
    if m:
        c = _qualified_last(m.group(1))
        return (c, 'ctor') if c else None
    m = re.match(r'__t(\d+)(\w+)$', sym)
    if m: return m.group(2)[:int(m.group(1))], 'ctor'
    m = re.match(r'__(\d+)(\w+)$', sym)
    if m:
        cl = m.group(2)[:int(m.group(1))]
        return cl, 'ctor'
    m = re.match(r'(\w+?)__C?(Q.*)$', sym)
    if m:
        c = _qualified_last(m.group(2))
        if c: return c, m.group(1)
    m = re.match(r'(\w+?)__C?t(\d+)(\w+)$', sym)
    if m: return m.group(3)[:int(m.group(2))], m.group(1)
    m = re.match(r'(\w+?)__C?(\d+)(\w+)$', sym)
    if m:
        n = int(m.group(2))
        if len(m.group(3)) >= n: return m.group(3)[:n], m.group(1)
    m = re.match(r'(\w+?)__F', sym)
    if m: return None, m.group(1)
    return None


def _strip_templates(d):
    out = []; depth = 0; i = 0
    while i < len(d):
        c = d[i]
        if d.startswith('operator<', i) or d.startswith('operator>', i):
            out.append(d[i:i + 9]); i += 9
            while i < len(d) and d[i] in '<>=': out.append(d[i]); i += 1
            continue
        if c == '<': depth += 1
        elif c == '>': depth = max(0, depth - 1)
        elif depth == 0: out.append(c)
        i += 1
    return ''.join(out)


def parse_demangled(d):
    """(clase, método) de un nombre desmontado por llvm-cxxfilt."""
    d = _strip_templates(d.strip())
    m = re.match(r'vtable for (?:\w+::)*(\w+)$', d)
    if m: return m.group(1), 'vtable'
    m = re.match(r'(?:[\w:,\s\*&]+\s)?([A-Za-z_]\w*)::operator\s*(new\[\]|delete\[\]|new|delete|[^\s(]+)\s*\(', d)
    if m:
        op = m.group(2)
        return m.group(1), op if op in ('new', 'delete', 'new[]', 'delete[]') else 'operator' + op
    head = d.split('(')[0]
    parts = head.split('::')
    if len(parts) >= 2:
        meth = parts[-1].split()[-1] if parts[-1].split() else ''
        cl = parts[-2].split()[-1] if parts[-2].split() else ''
        if meth.startswith('~'): return cl, '~'
        if meth == cl: return cl, 'ctor'
        if cl and meth: return cl, meth
    m = re.match(r'(?:[\w:,\s\*&]+\s)?([A-Za-z_]\w*)\(', d)
    if m: return None, m.group(1)
    return None


def demangled_arity(d):
    """Número de argumentos de un nombre desmontado; None si no se sabe."""
    i = d.find('(')
    if i < 0: return None
    depth = 0; n = 0; empty = True
    for c in d[i + 1:]:
        if c in '(<': depth += 1
        elif c == '>': depth -= 1
        elif c == ')':
            if depth == 0: break
            depth -= 1
        elif c == ',' and depth == 0: n += 1
        if not c.isspace(): empty = False
    return 0 if empty or d[i + 1:].startswith(')') or d[i + 1:].startswith('void)') else n + 1


def gcc2_arity(sym):
    """Argumentos del final de un nombre GCC 2.95, tras la clase. None si no se entiende."""
    m = re.match(r'(?:__(?:nw|dl|vn|vd|as|eq|ne|pl|apl|ls|vc|ml|pp)__|\w*?__)C?(\d+)(\w*)$', sym)
    if not m: return None
    ln = int(m.group(1)); t = m.group(2)
    if len(t) < ln: return None
    t = t[ln:]
    i = 0; n = 0
    while i < len(t):
        while i < len(t) and t[i] in 'PRCVUS': i += 1
        if i >= len(t): return None
        c = t[i]
        if c.isdigit():
            d = re.compile(r'\d+').match(t, i); i = d.end() + int(d.group(0))
        elif c == 'T':
            d = re.compile(r'T(\d)').match(t, i)
            if not d: return None
            i = d.end()
        elif c == 'N':
            d = re.compile(r'N(\d)(\d)').match(t, i)
            if not d: return None
            n += int(d.group(1)); i = d.end(); continue
        elif c in 'Qt': return None
        elif c == 'v': return 0
        elif c in 'icsfdlbwx': i += 1
        else: return None
        n += 1
    return n


def demangle(names):
    names = list(names)
    if not names: return {}
    r = subprocess.run(['xcrun', 'llvm-cxxfilt'], input='\n'.join('_' + n for n in names), capture_output=True, text=True)
    return dict(zip(names, r.stdout.splitlines()))


class UnitResolver:
    """Resuelve nombres de un objeto con su mapa y, si no, con el global cuando no es ambiguo."""

    def __init__(self, unit_map, global_map, ledger_names):
        self.u = unit_map or {}
        self.g = global_map
        self.led = ledger_names
        self.members = collections.defaultdict(set)
        self.by_arity = collections.defaultdict(set)
        for s, a in self.u.items():
            k = parse_gcc2(s)
            if k:
                self.members[k].add(a)
                self.by_arity[(k, gcc2_arity(s))].add(a)

    def plain(self, name):
        if name in self.u: return self.u[name], 'unidad'
        if name in self.led: return self.led[name], 'registro'
        c = self.g.get(name)
        if c and len(c) == 1: return next(iter(c)), 'global'
        m = SUFFIX.findall(name)
        if m: return int(m[-1], 16), 'sufijo'
        return None, 'ambiguo' if c else 'sin_dato'

    def member(self, key, arity=None):
        c = self.members.get(key)
        if c and len(c) == 1: return next(iter(c)), 'miembro'
        if c and arity is not None:
            ca = self.by_arity.get((key, arity))
            if ca and len(ca) == 1: return next(iter(ca)), 'miembro_aridad'
        if key[0] is None:
            return self.plain(key[1])
        # Un nombre de clase puede llevar la dirección: String_803426b8.
        m = SUFFIX.findall(key[0]) if key[1] in ('ctor', '~') else []
        if m: return int(m[-1], 16), 'sufijo_clase'
        return None, 'ambiguo' if c else 'sin_dato'
