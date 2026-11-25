/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_fill_unit_table_8008f478)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_sqrtf_802e82c0 = 0x802e82c0;
w3d_table_80431ea0 = 0x80431ea0;
w3d_zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d24b_fill_unit_table_8008f478 0x8008f478 : { *(.text.w3d_d24b_fill_unit_table_8008f478) }
  .rodata 0x8037e7ac : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
