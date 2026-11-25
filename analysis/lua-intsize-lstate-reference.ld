/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(stack_init)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaC_callGCTM = 0x802d1d54;
luaC_link = 0x802d2044;
luaC_separateudata = 0x802d10dc;
luaC_sweep = 0x802d1e10;
luaD_rawrunprotected = 0x802cfcc0;
luaF_close = 0x802d0d2c;
luaM_realloc = 0x802d2108;
luaS_freeall = 0x802d5c38;
SECTIONS {
  .text.stack_init 0x802d56ac : { *(.text.stack_init) }
  .text.freestack 0x802d5770 : { *(.text.freestack) }
  .text.preinit_state 0x802d5944 : { *(.text.preinit_state) }
  .text.close_state 0x802d5990 : { *(.text.close_state) }
  .text.luaE_newthread 0x802d5a40 : { *(.text.luaE_newthread) }
  .text.luaE_freethread 0x802d5ab0 : { *(.text.luaE_freethread) }
  .text.lua_open 0x802d5b00 : { *(.text.lua_open) }
  .text.callallgcTM 0x802d5b90 : { *(.text.callallgcTM) }
  .text.lua_close 0x802d5bb0 : { *(.text.lua_close) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
