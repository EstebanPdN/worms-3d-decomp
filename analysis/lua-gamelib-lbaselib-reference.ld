/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaB_tonumber)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
getenv = 0x802eda04;
luaL_argerror = 0x802dcc74;
luaL_callmeta = 0x802dd264;
luaL_checkany = 0x802dcfdc;
luaL_checklstring = 0x802dd028;
luaL_checkstack = 0x802dcf40;
luaL_checktype = 0x802dcf90;
luaL_error = 0x802dce74;
luaL_getmetafield = 0x802dd1d8;
luaL_getn = 0x802dd660;
luaL_loadbuffer = 0x802ddbd8;
luaL_loadfile = 0x802dda0c;
luaL_openlib = 0x802dd2e8;
luaL_optlstring = 0x802dd090;
luaL_optnumber = 0x802dd180;
luaL_where = 0x802dcdec;
lua_call = 0x802ce6e4;
lua_checkstack = 0x802cd698;
lua_concat = 0x802ce920;
lua_error = 0x802ce89c;
lua_getfenv = 0x802ce468;
lua_getinfo = 0x802cef54;
lua_getmetatable = 0x802ce3d4;
lua_getstack = 0x802ceb88;
lua_gettable = 0x802ce264;
lua_gettop = 0x802cd7f4;
lua_insert = 0x802cd8e0;
lua_iscfunction = 0x802cda44;
lua_isnumber = 0x802cda9c;
lua_isstring = 0x802cdaf4;
lua_newtable = 0x802ce368;
lua_newthread = 0x802cd784;
lua_newuserdata = 0x802ce9d8;
lua_next = 0x802ce8c0;
lua_pcall = 0x802ce73c;
lua_pushboolean = 0x802ce214;
lua_pushcclosure = 0x802ce148;
lua_pushlstring = 0x802cdf60;
lua_pushnil = 0x802cdf24;
lua_pushnumber = 0x802cdf40;
lua_pushstring = 0x802cdfd4;
lua_pushvalue = 0x802cd99c;
lua_rawequal = 0x802cdb6c;
lua_rawget = 0x802ce2bc;
lua_rawgeti = 0x802ce30c;
lua_rawset = 0x802ce528;
lua_replace = 0x802cd94c;
lua_resume = 0x802d083c;
lua_setfenv = 0x802ce674;
lua_setgcthreshold = 0x802ce840;
lua_setmetatable = 0x802ce5ec;
lua_settable = 0x802ce4d8;
lua_settop = 0x802cd808;
lua_toboolean = 0x802cdcb0;
lua_tonumber = 0x802cdc5c;
lua_topointer = 0x802cde9c;
lua_tostring = 0x802cdd04;
lua_tothread = 0x802cde5c;
lua_touserdata = 0x802cde08;
lua_type = 0x802cd9e8;
lua_typename = 0x802cda1c;
lua_xmove = 0x802cd720;
lua_yield = 0x802d08c8;
sprintf = 0x802ec254;
strchr = 0x802ef198;
strlen = 0x802ef9c0;
strtoul = 0x802eecc8;
w3d_ctype_table = 0x803db448;
SECTIONS {
  .text.luaB_tonumber 0x802dde54 : { *(.text.luaB_tonumber) }
  .text.luaB_error 0x802ddfa8 : { *(.text.luaB_error) }
  .text.luaB_getmetatable 0x802de050 : { *(.text.luaB_getmetatable) }
  .text.luaB_setmetatable 0x802de0b8 : { *(.text.luaB_setmetatable) }
  .text.getfunc 0x802de16c : { *(.text.getfunc) }
  .text.aux_getfenv 0x802de25c : { *(.text.aux_getfenv) }
  .text.luaB_getfenv 0x802de2c8 : { *(.text.luaB_getfenv) }
  .text.luaB_setfenv 0x802de314 : { *(.text.luaB_setfenv) }
  .text.luaB_rawequal 0x802de3fc : { *(.text.luaB_rawequal) }
  .text.luaB_rawget 0x802de458 : { *(.text.luaB_rawget) }
  .text.luaB_rawset 0x802de4a8 : { *(.text.luaB_rawset) }
  .text.luaB_collectgarbage 0x802de590 : { *(.text.luaB_collectgarbage) }
  .text.luaB_type 0x802de5e0 : { *(.text.luaB_type) }
  .text.luaB_next 0x802de638 : { *(.text.luaB_next) }
  .text.luaB_pairs 0x802de69c : { *(.text.luaB_pairs) }
  .text.load_aux 0x802de810 : { *(.text.load_aux) }
  .text.luaB_loadstring 0x802de85c : { *(.text.luaB_loadstring) }
  .text.luaB_loadfile 0x802de8c8 : { *(.text.luaB_loadfile) }
  .text.luaB_dofile 0x802de918 : { *(.text.luaB_dofile) }
  .text.luaB_assert 0x802de988 : { *(.text.luaB_assert) }
  .text.luaB_unpack 0x802dea10 : { *(.text.luaB_unpack) }
  .text.luaB_pcall 0x802dea94 : { *(.text.luaB_pcall) }
  .text.luaB_xpcall 0x802deb04 : { *(.text.luaB_xpcall) }
  .text.luaB_tostring 0x802deb84 : { *(.text.luaB_tostring) }
  .text.luaB_newproxy 0x802ded34 : { *(.text.luaB_newproxy) }
  .text.getpath 0x802dee44 : { *(.text.getpath) }
  .text.pushnextpath 0x802deecc : { *(.text.pushnextpath) }
  .text.pushcomposename 0x802def50 : { *(.text.pushcomposename) }
  .text.luaB_require 0x802deff0 : { *(.text.luaB_require) }
  .text.auxresume 0x802df274 : { *(.text.auxresume) }
  .text.luaB_coresume 0x802df350 : { *(.text.luaB_coresume) }
  .text.luaB_auxwrap 0x802df3fc : { *(.text.luaB_auxwrap) }
  .text.luaB_cocreate 0x802df494 : { *(.text.luaB_cocreate) }
  .text.luaB_cowrap 0x802df520 : { *(.text.luaB_cowrap) }
  .text.luaB_yield 0x802df564 : { *(.text.luaB_yield) }
  .text.luaB_costatus 0x802df59c : { *(.text.luaB_costatus) }
  .text.base_open 0x802df660 : { *(.text.base_open) }
  .text.luaopen_base 0x802df784 : { *(.text.luaopen_base) }
  .rodata 0x803da8a8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
