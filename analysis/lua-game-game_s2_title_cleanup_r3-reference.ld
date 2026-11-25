/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_title_default_vector_8011f2c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_8039b54c = 0x8039b54c;
w3d_f32_8039b550 = 0x8039b550;
SECTIONS {
  .text.w3d_title_default_vector_8011f2c8 0x8011f2c8 : { *(.text.w3d_title_default_vector_8011f2c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
