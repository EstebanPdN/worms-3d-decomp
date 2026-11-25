/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_lua_table_getnum_802d6b98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
hashnum = 0x802d5f84;
SECTIONS {
  .text.w3d_k6b_lua_table_getnum_802d6b98 0x802d6b98 : { *(.text.w3d_k6b_lua_table_getnum_802d6b98) }
  .rodata 0x803da0c8 : { *(.rodata) }
  .sdata 0x804b1968 (NOLOAD) : {
    . = 0x0; luaO_nilobject = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
