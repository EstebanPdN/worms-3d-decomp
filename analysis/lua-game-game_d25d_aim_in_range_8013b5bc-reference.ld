/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_aim_in_range_8013b5bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
acos_802e79e0 = 0x802e79e0;
asin_802e83ec = 0x802e83ec;
atan2_802e7e5c = 0x802e7e5c;
construct_801f7538 = 0x801f7538;
cos_802e86d4 = 0x802e86d4;
sin_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d25d_aim_in_range_8013b5bc 0x8013b5bc : { *(.text.d25d_aim_in_range_8013b5bc) }
  .rodata 0x8039f7ec : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
