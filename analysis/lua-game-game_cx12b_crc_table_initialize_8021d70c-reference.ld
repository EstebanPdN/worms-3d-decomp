/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_crc_table_initialize_8021d70c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
table_804a98f8 = 0x804a98f8;
transform_8021d7b0 = 0x8021d7b0;
SECTIONS {
  .text.w3d_cx12b_crc_table_initialize_8021d70c 0x8021d70c : { *(.text.w3d_cx12b_crc_table_initialize_8021d70c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
