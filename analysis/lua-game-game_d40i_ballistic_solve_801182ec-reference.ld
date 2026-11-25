/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40i_ballistic_solve_801182ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_copy12_800d7788 = 0x800d7788;
w3d_prepare_8011855c = 0x8011855c;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d40i_ballistic_solve_801182ec 0x801182ec : { *(.text.d40i_ballistic_solve_801182ec) }
  .rodata 0x8039a9b4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
