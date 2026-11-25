/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaL_argerror)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_call = 0x802ce6e4;
lua_checkstack = 0x802cd698;
lua_concat = 0x802ce920;
lua_error = 0x802ce89c;
lua_getinfo = 0x802cef54;
lua_getmetatable = 0x802ce3d4;
lua_getstack = 0x802ceb88;
lua_gettable = 0x802ce264;
lua_gettop = 0x802cd7f4;
lua_insert = 0x802cd8e0;
lua_isnumber = 0x802cda9c;
lua_load = 0x802ce7c0;
lua_newtable = 0x802ce368;
lua_pcall = 0x802ce73c;
lua_pushcclosure = 0x802ce148;
lua_pushfstring = 0x802ce07c;
lua_pushlstring = 0x802cdf60;
lua_pushnumber = 0x802cdf40;
lua_pushstring = 0x802cdfd4;
lua_pushvalue = 0x802cd99c;
lua_pushvfstring = 0x802ce024;
lua_rawget = 0x802ce2bc;
lua_rawgeti = 0x802ce30c;
lua_rawset = 0x802ce528;
lua_rawseti = 0x802ce588;
lua_remove = 0x802cd878;
lua_setmetatable = 0x802ce5ec;
lua_settable = 0x802ce4d8;
lua_settop = 0x802cd808;
lua_strlen = 0x802cdd9c;
lua_tonumber = 0x802cdc5c;
lua_tostring = 0x802cdd04;
lua_type = 0x802cd9e8;
lua_typename = 0x802cda1c;
strcmp = 0x802ef234;
strlen = 0x802ef9c0;
SECTIONS {
  .text.luaL_argerror 0x802dcc74 : { *(.text.luaL_argerror) }
  .text.luaL_typerror 0x802dcd3c : { *(.text.luaL_typerror) }
  .text.tag_error 0x802dcda8 : { *(.text.tag_error) }
  .text.luaL_where 0x802dcdec : { *(.text.luaL_where) }
  .text.luaL_error 0x802dce74 : { *(.text.luaL_error) }
  .text.luaL_checkstack 0x802dcf40 : { *(.text.luaL_checkstack) }
  .text.luaL_checktype 0x802dcf90 : { *(.text.luaL_checktype) }
  .text.luaL_checkany 0x802dcfdc : { *(.text.luaL_checkany) }
  .text.luaL_checklstring 0x802dd028 : { *(.text.luaL_checklstring) }
  .text.luaL_optlstring 0x802dd090 : { *(.text.luaL_optlstring) }
  .text.luaL_getmetafield 0x802dd1d8 : { *(.text.luaL_getmetafield) }
  .text.luaL_callmeta 0x802dd264 : { *(.text.luaL_callmeta) }
  .text.luaL_openlib 0x802dd2e8 : { *(.text.luaL_openlib) }
  .text.checkint 0x802dd40c : { *(.text.checkint) }
  .text.getsizes 0x802dd47c : { *(.text.getsizes) }
  .text.luaL_setn 0x802dd540 : { *(.text.luaL_setn) }
  .text.luaL_getn 0x802dd660 : { *(.text.luaL_getn) }
  .text.luaL_ref 0x802dd76c : { *(.text.luaL_ref) }
  .text.luaL_unref 0x802dd884 : { *(.text.luaL_unref) }
  .text.getS 0x802ddbb0 : { *(.text.getS) }
  .text.luaL_loadbuffer 0x802ddbd8 : { *(.text.luaL_loadbuffer) }
  .text.aux_do 0x802ddcc0 : { *(.text.aux_do) }
  .rodata 0x803da7b8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
