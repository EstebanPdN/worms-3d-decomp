#!/usr/bin/env python3
"""Dirección original de cada tabla virtual que los constructores convertidos instalan.

Las unidades nombran las tablas (__vt_4Base) pero el enlace no las define, y un mismo nombre puede ser una clase distinta
en otra unidad. Aquí se sacan de los bytes PPC de cada unidad: lis/addi de una dirección de datos seguido de stw, cuyo destino
tiene forma de tabla (dos palabras de cabecera y al menos una función). Se asignan por orden de aparición con los nombres de la unidad.
Salida: port/docs-data/vtables.json {fuente: {nombre: dirección}} y los casos no resueltos.
"""
import collections, json, os, re, struct, sys
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
DATA_LO, DATA_HI, TEXT_LO = 0x8035f3e0, 0x804b3280, 0x80003100
SET = re.compile(r'W3D_SET_VPTR\([^,]+, *\w+, *"([^"]+)"')
led = json.load(open(f'{ROOT}/analysis/recovery-ledger.json'))['functions']
dol = open(f'{ROOT}/gamedata/GWMP8P/sys/main.dol', 'rb').read()
off = struct.unpack_from('>18I', dol, 0); adr = struct.unpack_from('>18I', dol, 0x48); siz = struct.unpack_from('>18I', dol, 0x90)
def word(a):
    for o, s, n in zip(off, adr, siz):
        if n and s <= a < s + n: return struct.unpack_from('>I', dol, o + a - s)[0]
    return None
def is_table(a):
    if a % 4: return False
    h0, h1, first = word(a), word(a + 4), word(a + 8)
    return h0 == 0 and h1 == 0 and first is not None and TEXT_LO <= first < DATA_LO
def stores(addr, size):
    """Tablas instaladas por una función, en orden."""
    regs = {}; out = []
    for k in range(0, size, 4):
        w = word(addr + k)
        if w is None: break
        op = w >> 26; rd = (w >> 21) & 31; ra = (w >> 16) & 31; imm = w & 0xffff; s = imm - 0x10000 if imm & 0x8000 else imm
        if op == 15 and ra == 0: regs[rd] = imm << 16
        elif op == 14 and ra in regs: regs[rd] = (regs[ra] + s) & 0xffffffff
        elif op == 24 and ra == rd and rd in regs: regs[rd] |= imm
        elif op == 36 and rd in regs and DATA_LO <= regs[rd] < DATA_HI and is_table(regs[rd]): out.append(regs[rd])
        elif op == 15: regs.pop(rd, None)
    return out
def table_len(a):
    n = 0
    while True:
        v = word(a + 8 + 4 * n)
        if v is None or not (v == 0 or TEXT_LO <= v < DATA_LO): break
        n += 1
    while n and word(a + 8 + 4 * (n - 1)) == 0: n -= 1
    return n
def methods(cls, text, depth=0):
    """Nombres de las virtuales de una clase y sus bases, o None si no se encuentra su definición."""
    m = re.search(r'(?:struct|class)\s+%s\b\s*(:[^{;]*)?\{' % cls, text)
    if not m or depth > 8: return None
    i = m.end(); level = 1
    while i < len(text) and level:
        level += {'{': 1, '}': -1}.get(text[i], 0); i += 1
    found = set()
    for b in re.findall(r'\b(\w+)\s*(?:,|$)', (m[1] or ':')[1:].strip()):
        inherited = methods(b, text, depth + 1)
        if inherited: found |= inherited
    for sig in re.findall(r'\bvirtual\b[^;{(]*?(~?\w+)\s*\(', text[m.end():i]): found.add('~' if sig.startswith('~') else sig)
    return found
def slots(name, text):
    c = re.match(r'__vt_\d+(\w+)$', name)
    found = methods(c[1], text) if c else None
    return len(found) if found else None
prodg = json.load(open(f'{ROOT}/port/docs-data/vtables-prodg.json'))['resolved']  # tools/relink/vtable_prodg.py, exactas
by_src = collections.defaultdict(list)
for f in led: by_src[f['source']].append((int(f['address'], 16), f['bytes']))
result = {}; unresolved = {}
for src, funcs in by_src.items():
    rel = re.sub(r'^source/matching/game', 'port/core/game', src); rel = re.sub(r'^source/matching', 'port/core/engine', rel); rel = re.sub(r'^source/vendor', 'port/core/vendor', rel)
    path = os.path.join(ROOT, rel.rsplit('.', 1)[0] + '.cpp')
    if not os.path.exists(path): continue
    text = open(path, errors='replace').read()
    for inc in re.findall(r'#include "([^"]+)"', text):
        p = os.path.join(os.path.dirname(path), inc)
        if os.path.exists(p): text = open(p, errors='replace').read() + text
    names = list(dict.fromkeys(SET.findall(text)))
    if not names: continue
    exact = dict(prodg.get(src, {}))
    seen = list(dict.fromkeys(t for a, n in sorted(funcs) for t in stores(a, n)))
    used = {int(v, 16) for v in exact.values()}
    free = [t for t in seen if t not in used]
    def base_of(n):
        m = re.match(r'__vt_\d+(\w+)$', n)
        b = m and re.search(r'(?:struct|class)\s+%s\s*:\s*(?:public\s+)?(\w+)' % m[1], text)
        return f'__vt_{len(b[1])}{b[1]}' if b else None
    final = {n: exact[n] for n in names if n in exact}
    left = [n for n in names if n not in final]
    # Lo que ProDG no nombra: la clase comparte tabla con su base, o queda una sola candidata libre para una sola clase.
    if len(left) == 1 and len(free) == 1 and not any(base_of(x) == left[0] for x in names): final[left[0]] = hex(free[0]); left = []
    for _ in range(4):
        for n in list(left):
            b = base_of(n)
            if b in final or b in exact: final[n] = final.get(b, exact.get(b)); left.remove(n)
    if len(left) == len(free) and not exact:
        for n, t in zip(left, free): final[n] = hex(t)
        left = []
    if final: result[src] = final
    if left: unresolved[src] = dict(names=left, tables=[hex(t) for t in free])
json.dump(dict(resolved=result, unresolved=unresolved), open(f'{ROOT}/port/docs-data/vtables.json', 'w'), indent=0)
print('unidades resueltas', len(result), 'tablas', sum(map(len, result.values())), 'sin resolver', len(unresolved))
for s, u in list(unresolved.items())[:25]: print(' ', os.path.basename(s), len(u['names']), len(u['tables']), u['names'][:4], u['tables'][:4])
