/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_table_length_802cd408)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__assert = 0x802ed7b0;
luaH_getstr = 0x802d6c48;
luaS_newlstr = 0x802d5e30;
negindex = 0x802cd5a4;
SECTIONS {
  .text.w3d_k6b_lua_table_length_802cd408 0x802cd408 : { *(.text.w3d_k6b_lua_table_length_802cd408) }
  .rodata 0x803d9998 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
