/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaZ_fill)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaM_realloc = 0x802d2108;
SECTIONS {
  .text.luaZ_fill 0x802d9a50 : { *(.text.luaZ_fill) }
  .text.luaZ_lookahead 0x802d9ac4 : { *(.text.luaZ_lookahead) }
  .text.luaZ_init 0x802d9b2c : { *(.text.luaZ_init) }
  .text.luaZ_openspace 0x802d9c08 : { *(.text.luaZ_openspace) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
