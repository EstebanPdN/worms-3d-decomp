/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaM_growaux)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_throw = 0x802cfc7c;
luaG_runerror = 0x802cfb10;
w3d_lua_reallocate = 0x8019e260;
w3d_lua_release = 0x8019e328;
SECTIONS {
  .text.luaM_growaux 0x802d2068 : { *(.text.luaM_growaux) }
  .text.luaM_realloc 0x802d2108 : { *(.text.luaM_realloc) }
  .rodata 0x803d9cd4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
