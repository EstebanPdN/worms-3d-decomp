/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_script_start_timer_80102b2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
error_801022ec = 0x801022ec;
lua_gettop = 0x802cd7f4;
lua_isnumber = 0x802cda9c;
lua_isstring = 0x802cdaf4;
lua_pushnumber = 0x802cdf40;
lua_settop = 0x802cd808;
lua_tonumber = 0x802cdc5c;
lua_tostring = 0x802cdd04;
start_8005ffc8 = 0x8005ffc8;
SECTIONS {
  .text.d25c_script_start_timer_80102b2c 0x80102b2c : { *(.text.d25c_script_start_timer_80102b2c) }
  .rodata 0x80398f48 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
