/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_air_control_8014f8cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
construct_801f7538 = 0x801f7538;
scale_80178df0 = 0x80178df0;
sqrt_802e82c0 = 0x802e82c0;
wish_8014b8ec = 0x8014b8ec;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d25d_worm_air_control_8014f8cc 0x8014f8cc : { *(.text.d25d_worm_air_control_8014f8cc) }
  .rodata 0x803a17a4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
