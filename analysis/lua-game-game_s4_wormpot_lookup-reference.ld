/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_wormpot_find_value)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_table_803d6b7c = 0x803d6b7c;
w3d_table_803d6bd0 = 0x803d6bd0;
w3d_table_803d6c24 = 0x803d6c24;
SECTIONS {
  .text.w3d_s4_wormpot_find_value 0x802ab378 : { *(.text.w3d_s4_wormpot_find_value) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
