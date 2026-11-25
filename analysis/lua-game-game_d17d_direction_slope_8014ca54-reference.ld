/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17d_direction_slope_8014ca54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_acos_802e79e0 = 0x802e79e0;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d17d_direction_slope_8014ca54 0x8014ca54 : { *(.text.d17d_direction_slope_8014ca54) }
  .rodata 0x803a151c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
