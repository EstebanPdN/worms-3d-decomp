/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17d_float_edit_8027a2c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atof = 0x802ed878;
w3d_auto_8027a98c = 0x8027a98c;
w3d_s21_state_dispatch_8027ae00 = 0x8027ae00;
w3d_s21_vector_get_801e9db8 = 0x801e9db8;
SECTIONS {
  .text.w3d_cc17d_float_edit_8027a2c4 0x8027a2c4 : { *(.text.w3d_cc17d_float_edit_8027a2c4) }
  .text.w3d_cc17d_bool_edit_8027a7fc 0x8027a7fc : { *(.text.w3d_cc17d_bool_edit_8027a7fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
