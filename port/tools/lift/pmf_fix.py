#!/usr/bin/env python3
"""Punteros a método con la forma de GCC 2.95.

GCC 2.95 guarda {short delta, short index, pfn o desplazamiento de tabla} en 8 bytes; Itanium en arm64 usa 16 bytes
con otra forma. Las estructuras del juego los guardan y los datos del DOL pueden traerlos. Esta pasada, sobre el texto
convertido, cambia los tipos `R (C::*n)(A)` por `w3d::Pmf<C, R(A)> n` y las llamadas `(o->*m)(a)` por `(m)(o, a)`.
"""
import re

TYPE = re.compile(r'((?:\b(?:const|volatile|unsigned|signed|short|long|int|char|void|float|double|bool)\b[ \t]*'
                  r'|\b[A-Za-z_][\w:]*(?:<(?:[^<>;()]|<[^<>;()]*>)*>)?[ \t]*)+[*& \t]*)'
                  r'\([ \t]*([A-Za-z_][\w:]*)::\*[ \t]*(\w*)[ \t]*\)[ \t]*\(([^()]*)\)')


def fix_types(s):
    def rep(m):
        ret, cls, name, args = m.group(1).strip(), m.group(2), m.group(3), m.group(4).strip()
        lead = ''
        g = re.match(r'((?:typedef|static|extern|inline)\s+)+', ret)
        if g:
            lead = g.group(0); ret = ret[g.end():]
        if args == 'void': args = ''
        return f'{lead}w3d::Pmf<{cls}, {ret}({args})> {name}'.rstrip()
    return TYPE.sub(rep, s)


def _close(s, i):
    d = 0
    while i < len(s):
        if s[i] in '([{': d += 1
        elif s[i] in ')]}':
            d -= 1
            if d == 0: return i
        i += 1
    return -1


def _open(s, i):
    d = 0
    while i >= 0:
        if s[i] in ')]}': d += 1
        elif s[i] in '([{':
            if d == 0: return i
            d -= 1
        i -= 1
    return -1


def fix_calls(s):
    pos = len(s)
    while True:
        a = s.rfind('->*', 0, pos); b = s.rfind('.*', 0, pos)
        if b > 0 and not (s[b - 1].isalnum() or s[b - 1] in ')]_'): 
            pos = b; continue
        if a < 0 and b < 0: return s
        arrow = a > b
        at = a if arrow else b
        n = 3 if arrow else 2
        lp = _open(s, at - 1)
        rp = _close(s, lp) if lp >= 0 else -1
        if lp < 0 or rp < 0 or rp + 1 >= len(s) or s[rp + 1] != '(':
            pos = at; continue
        end = _close(s, rp + 1)
        obj = s[lp + 1:at].strip(); mem = s[at + n:rp].strip(); args = s[rp + 2:end].strip()
        self_ = obj if arrow else f'&({obj})'
        s = s[:lp] + f'({mem})({self_}{", " + args if args else ""})' + s[end + 1:]
        pos = lp + 1


def apply(path):
    s = open(path).read()
    if '::*' not in s and '->*' not in s and '.*' not in s: return False
    new = fix_calls(fix_types(s))
    if new != s:
        open(path, 'w').write(new)
        return True
    return False
