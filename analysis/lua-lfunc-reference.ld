/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaF_newCclosure)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaC_link = 0x802d2044;
luaM_realloc = 0x802d2108;
SECTIONS {
  .text.luaF_newCclosure 0x802d0bbc : { *(.text.luaF_newCclosure) }
  .text.luaF_newLclosure 0x802d0c20 : { *(.text.luaF_newLclosure) }
  .text.luaF_findupval 0x802d0c98 : { *(.text.luaF_findupval) }
  .text.luaF_close 0x802d0d2c : { *(.text.luaF_close) }
  .text.luaF_newproto 0x802d0da4 : { *(.text.luaF_newproto) }
  .text.luaF_freeproto 0x802d0e40 : { *(.text.luaF_freeproto) }
  .text.luaF_freeclosure 0x802d0f0c : { *(.text.luaF_freeclosure) }
  .text.luaF_getlocalname 0x802d0f58 : { *(.text.luaF_getlocalname) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
