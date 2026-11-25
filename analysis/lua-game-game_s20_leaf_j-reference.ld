/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_get_quad_8016768c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_get_quad_8016768c 0x8016768c : { *(.text.w3d_s20_get_quad_8016768c) }
  .text.w3d_s20_get_matrix_80167824 0x80167824 : { *(.text.w3d_s20_get_matrix_80167824) }
  .text.w3d_s20_set_matrix_80167898 0x80167898 : { *(.text.w3d_s20_set_matrix_80167898) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
