/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaS_freeall)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaM_realloc = 0x802d2108;
memcmp = 0x802eedc0;
memcpy = 0x802eee50;
SECTIONS {
  .text.luaS_freeall 0x802d5c38 : { *(.text.luaS_freeall) }
  .text.luaS_resize 0x802d5c6c : { *(.text.luaS_resize) }
  .text.newlstr 0x802d5d50 : { *(.text.newlstr) }
  .text.luaS_newlstr 0x802d5e30 : { *(.text.luaS_newlstr) }
  .text.luaS_newudata 0x802d5f10 : { *(.text.luaS_newudata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
