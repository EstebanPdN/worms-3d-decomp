/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_slope_angle_80149348)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
acos_802e79e0 = 0x802e79e0;
asin_802e7c30 = 0x802e7c30;
construct_801f7538 = 0x801f7538;
normal_80146f10 = 0x80146f10;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26d_worm_slope_angle_80149348 0x80149348 : { *(.text.d26d_worm_slope_angle_80149348) }
  .rodata 0x803a12f0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
