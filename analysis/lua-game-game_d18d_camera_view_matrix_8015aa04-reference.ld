/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d18d_camera_view_matrix_8015aa04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_camera_basis_8015a6f0 = 0x8015a6f0;
SECTIONS {
  .text.d18d_camera_view_matrix_8015aa04 0x8015aa04 : { *(.text.d18d_camera_view_matrix_8015aa04) }
  .rodata 0x803a4234 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
