/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_girder_points_80095b58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__5Point = 0x80343740;
w3d_identity_8045e748 = 0x8045e748;
w3d_matrix_rotation_801a3eb0 = 0x801a3eb0;
w3d_matrix_scale_801f781c = 0x801f781c;
SECTIONS {
  .text.w3d_d24b_girder_points_80095b58 0x80095b58 : { *(.text.w3d_d24b_girder_points_80095b58) }
  .rodata 0x8037ebc4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
