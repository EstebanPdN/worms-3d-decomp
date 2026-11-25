/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(math_abs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos = 0x802e5574;
asin = 0x802e57f0;
atan = 0x802e710c;
ceil = 0x802e734c;
cos = 0x802e74b4;
exp = 0x802e5ccc;
floor = 0x802e75d0;
frexp = 0x802e773c;
log = 0x802e62d4;
log10 = 0x802e6564;
luaL_checknumber = 0x802dd10c;
luaL_openlib = 0x802dd2e8;
lua_pushcclosure = 0x802ce148;
lua_pushlstring = 0x802cdf60;
lua_pushnumber = 0x802cdf40;
lua_settable = 0x802ce4d8;
sin = 0x802e787c;
sqrt = 0x802e6ea8;
srand = 0x802ee7d0;
tan = 0x802e795c;
SECTIONS {
  .text.math_abs 0x802df800 : { *(.text.math_abs) }
  .text.math_sin 0x802df840 : { *(.text.math_sin) }
  .text.math_cos 0x802df884 : { *(.text.math_cos) }
  .text.math_tan 0x802df8c8 : { *(.text.math_tan) }
  .text.math_asin 0x802df90c : { *(.text.math_asin) }
  .text.math_acos 0x802df950 : { *(.text.math_acos) }
  .text.math_atan 0x802df994 : { *(.text.math_atan) }
  .text.math_ceil 0x802dfa3c : { *(.text.math_ceil) }
  .text.math_floor 0x802dfa80 : { *(.text.math_floor) }
  .text.math_sqrt 0x802dfb28 : { *(.text.math_sqrt) }
  .text.math_log 0x802dfbd0 : { *(.text.math_log) }
  .text.math_log10 0x802dfc14 : { *(.text.math_log10) }
  .text.math_exp 0x802dfc58 : { *(.text.math_exp) }
  .text.math_deg 0x802dfc9c : { *(.text.math_deg) }
  .text.math_rad 0x802dfce4 : { *(.text.math_rad) }
  .text.math_frexp 0x802dfd2c : { *(.text.math_frexp) }
  .text.math_randomseed 0x802e0130 : { *(.text.math_randomseed) }
  .text.luaopen_math 0x802e0168 : { *(.text.luaopen_math) }
  .rodata 0x803dae70 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
