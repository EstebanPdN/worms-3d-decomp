/* Generated reference addresses; source bytes come only from compiled Lua. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(lua_gettop)
luaC_collectgarbage = 0x802d1fe4;
luaD_call = 0x802d0660;
luaD_growstack = 0x802cff34;
luaD_pcall = 0x802d09b8;
luaD_protectedparser = 0x802d0b24;
luaE_newthread = 0x802d5a40;
luaF_newCclosure = 0x802d0bbc;
luaG_errormsg = 0x802cfa50;
luaH_get = 0x802d6ca0;
luaH_getnum = 0x802d6b98;
luaH_new = 0x802d68d8;
luaH_next = 0x802d61d8;
luaH_set = 0x802d6d30;
luaH_setnum = 0x802d6ddc;
luaO_pushvfstring = 0x802d256c;
luaO_rawequalObj = 0x802d23c0;
luaS_newlstr = 0x802d5e30;
luaS_newudata = 0x802d5f10;
luaT_typenames = 0x803da108;
luaV_concat = 0x802d8698;
luaV_equalval = 0x802d8560;
luaV_gettable = 0x802d7f1c;
luaV_settable = 0x802d7fb8;
luaV_tonumber = 0x802d7a5c;
luaV_tostring = 0x802d7acc;
luaZ_init = 0x802d9b2c;
luaZ_lookahead = 0x802d9ac4;
strlen = 0x802ef9c0;
SECTIONS {
  .text.negindex 0x802cd5a4 : { *(.text.negindex) }
  .text.luaA_index 0x802cd60c : { *(.text.luaA_index) }
  .text.luaA_indexAcceptable 0x802cd648 : { *(.text.luaA_indexAcceptable) }
  .text.lua_checkstack 0x802cd698 : { *(.text.lua_checkstack) }
  .text.lua_xmove 0x802cd720 : { *(.text.lua_xmove) }
  .text.lua_atpanic 0x802cd774 : { *(.text.lua_atpanic) }
  .text.lua_newthread 0x802cd784 : { *(.text.lua_newthread) }
  .text.lua_gettop 0x802cd7f4 : { *(.text.lua_gettop) }
  .text.lua_settop 0x802cd808 : { *(.text.lua_settop) }
  .text.lua_remove 0x802cd878 : { *(.text.lua_remove) }
  .text.lua_insert 0x802cd8e0 : { *(.text.lua_insert) }
  .text.lua_replace 0x802cd94c : { *(.text.lua_replace) }
  .text.lua_pushvalue 0x802cd99c : { *(.text.lua_pushvalue) }
  .text.lua_type 0x802cd9e8 : { *(.text.lua_type) }
  .text.lua_typename 0x802cda1c : { *(.text.lua_typename) }
  .text.lua_iscfunction 0x802cda44 : { *(.text.lua_iscfunction) }
  .text.lua_isnumber 0x802cda9c : { *(.text.lua_isnumber) }
  .text.lua_isstring 0x802cdaf4 : { *(.text.lua_isstring) }
  .text.lua_isuserdata 0x802cdb24 : { *(.text.lua_isuserdata) }
  .text.lua_rawequal 0x802cdb6c : { *(.text.lua_rawequal) }
  .text.lua_equal 0x802cdbd0 : { *(.text.lua_equal) }
  .text.lua_tonumber 0x802cdc5c : { *(.text.lua_tonumber) }
  .text.lua_toboolean 0x802cdcb0 : { *(.text.lua_toboolean) }
  .text.lua_tostring 0x802cdd04 : { *(.text.lua_tostring) }
  .text.lua_strlen 0x802cdd9c : { *(.text.lua_strlen) }
  .text.lua_touserdata 0x802cde08 : { *(.text.lua_touserdata) }
  .text.lua_tothread 0x802cde5c : { *(.text.lua_tothread) }
  .text.lua_topointer 0x802cde9c : { *(.text.lua_topointer) }
  .text.lua_pushnil 0x802cdf24 : { *(.text.lua_pushnil) }
  .text.lua_pushnumber 0x802cdf40 : { *(.text.lua_pushnumber) }
  .text.lua_pushlstring 0x802cdf60 : { *(.text.lua_pushlstring) }
  .text.lua_pushstring 0x802cdfd4 : { *(.text.lua_pushstring) }
  .text.lua_pushvfstring 0x802ce024 : { *(.text.lua_pushvfstring) }
  .text.lua_pushfstring 0x802ce07c : { *(.text.lua_pushfstring) }
  .text.lua_pushcclosure 0x802ce148 : { *(.text.lua_pushcclosure) }
  .text.lua_pushboolean 0x802ce214 : { *(.text.lua_pushboolean) }
  .text.lua_pushlightuserdata 0x802ce244 : { *(.text.lua_pushlightuserdata) }
  .text.lua_gettable 0x802ce264 : { *(.text.lua_gettable) }
  .text.lua_rawget 0x802ce2bc : { *(.text.lua_rawget) }
  .text.lua_rawgeti 0x802ce30c : { *(.text.lua_rawgeti) }
  .text.lua_newtable 0x802ce368 : { *(.text.lua_newtable) }
  .text.lua_getmetatable 0x802ce3d4 : { *(.text.lua_getmetatable) }
  .text.lua_getfenv 0x802ce468 : { *(.text.lua_getfenv) }
  .text.lua_settable 0x802ce4d8 : { *(.text.lua_settable) }
  .text.lua_rawset 0x802ce528 : { *(.text.lua_rawset) }
  .text.lua_rawseti 0x802ce588 : { *(.text.lua_rawseti) }
  .text.lua_setmetatable 0x802ce5ec : { *(.text.lua_setmetatable) }
  .text.lua_setfenv 0x802ce674 : { *(.text.lua_setfenv) }
  .text.lua_call 0x802ce6e4 : { *(.text.lua_call) }
  .text.f_call 0x802ce714 : { *(.text.f_call) }
  .text.lua_pcall 0x802ce73c : { *(.text.lua_pcall) }
  .text.lua_load 0x802ce7c0 : { *(.text.lua_load) }
  .text.lua_getgcthreshold 0x802ce820 : { *(.text.lua_getgcthreshold) }
  .text.lua_getgccount 0x802ce830 : { *(.text.lua_getgccount) }
  .text.lua_setgcthreshold 0x802ce840 : { *(.text.lua_setgcthreshold) }
  .text.lua_error 0x802ce89c : { *(.text.lua_error) }
  .text.lua_next 0x802ce8c0 : { *(.text.lua_next) }
  .text.lua_concat 0x802ce920 : { *(.text.lua_concat) }
  .text.lua_newuserdata 0x802ce9d8 : { *(.text.lua_newuserdata) }
  .rodata 0x803d99e0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.comment) }
}
