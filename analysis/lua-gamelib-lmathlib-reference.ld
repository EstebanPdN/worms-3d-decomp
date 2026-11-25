/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(math_abs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
frexp = 0x802e773c;
luaL_checknumber = 0x802dd10c;
luaL_openlib = 0x802dd2e8;
lua_pushcclosure = 0x802ce148;
lua_pushlstring = 0x802cdf60;
lua_pushnumber = 0x802cdf40;
lua_settable = 0x802ce4d8;
srand = 0x802ee7d0;
SECTIONS {
  .text.math_abs 0x802df800 : { *(.text.math_abs) }
  .text.math_frexp 0x802dfd2c : { *(.text.math_frexp) }
  .text.math_randomseed 0x802e0130 : { *(.text.math_randomseed) }
  .text.luaopen_math 0x802e0168 : { *(.text.luaopen_math) }
  .rodata 0x803dae68 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
