/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_matrix_euler_8009ea38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6Matrix = 0x801f6034;
w3d_asin_802e7c30 = 0x802e7c30;
w3d_rotate_cols_801f621c = 0x801f621c;
w3d_rotate_rows_801f61a0 = 0x801f61a0;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d25b_matrix_euler_8009ea38 0x8009ea38 : { *(.text.w3d_d25b_matrix_euler_8009ea38) }
  .rodata 0x80380698 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
