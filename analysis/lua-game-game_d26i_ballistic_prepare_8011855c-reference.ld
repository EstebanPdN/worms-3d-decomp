/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_ballistic_prepare_8011855c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_invert_801f60dc = 0x801f60dc;
SECTIONS {
  .text.d26i_ballistic_prepare_8011855c 0x8011855c : { *(.text.d26i_ballistic_prepare_8011855c) }
  .rodata 0x8039a9bc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
