/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_ipairs_802de708)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaL_checktype = 0x802dcf90;
lua_pushlstring = 0x802cdf60;
lua_pushnumber = 0x802cdf40;
lua_pushvalue = 0x802cd99c;
lua_rawget = 0x802ce2bc;
lua_rawgeti = 0x802ce30c;
lua_tonumber = 0x802cdc5c;
lua_type = 0x802cd9e8;
SECTIONS {
  .text.w3d_k6b_lua_ipairs_802de708 0x802de708 : { *(.text.w3d_k6b_lua_ipairs_802de708) }
  .rodata 0x803daa44 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
