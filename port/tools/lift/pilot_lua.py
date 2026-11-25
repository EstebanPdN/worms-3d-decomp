#!/usr/bin/env python3
"""Piloto de la fase 0: convierte Lua 5.0 (fuente del juego) a port/core/lua."""
import os, sys, json
sys.path.insert(0, os.path.dirname(__file__))
from lift import lift_file
ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../..'))
SRC = f'{ROOT}/build/lua-game-source'
LIB = f'{ROOT}/build/lua-gamelib-source/src/lib'
OUT = f'{ROOT}/port/core/lua'
FLAGS = [f'-I{SRC}/include', f'-I{SRC}/src', f'-I{ROOT}/source/matching', '-DLUA_NUMBER=float', '-DNDEBUG', '-DW3D_LUA_GAME_CONFIG=1', '-DLUA_USER_H="lua_game_reference_user.h"', f'-I{ROOT}/tools/reference-headers']
MODS = 'lapi lcode ldebug ldo ldump lfunc lgc llex lmem lobject lopcodes lparser lstate lstring ltable ltm lundump lvm lzio'.split()
PATCH = {
 '*': [(r'\b(luaM_new(?:vector)?|luaM_freearray|luaM_growvector|luaM_reallocvector)\s*\(([^;]*?),\s*([A-Za-z_]\w*)\s*\*\s*\)', r'\1(\2, Ptr32<\3>)')],
 'llimits.h': [(r'#define IntPoint\(p\)\s+\(\(lu_hash\)\(p\)\)', '#define IntPoint(p)  ((lu_hash)w3d::H(p))')],
 'lobject.h': [],
 'lstate.h': [],
}
tot = {}
MAP = [(SRC, OUT), (LIB, f'{OUT}/lib')]
def go(p, roots):
    l, w = lift_file(p, 'c', FLAGS, roots, MAP, PATCH)
    for k, v in l.stats.items(): tot[k] = tot.get(k, 0) + v
    for q in l.problems[:5]: print(os.path.basename(p), 'PROBLEMA', q)
for m in MODS: go(f'{SRC}/src/{m}.c', [SRC])
for m in 'lauxlib lbaselib lmathlib lstrlib ltablib ldblib'.split():
    p = f'{LIB}/{m}.c'
    if not os.path.exists(p): p = f'{SRC}/src/lib/{m}.c'
    if os.path.exists(p): go(p, [SRC, LIB])
print(json.dumps(tot, indent=1))
