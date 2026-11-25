/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_look_blend_801381f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
asin_802e7c30 = 0x802e7c30;
construct_801f7538 = 0x801f7538;
index_query_800fc6dc = 0x800fc6dc;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26d_worm_look_blend_801381f0 0x801381f0 : { *(.text.d26d_worm_look_blend_801381f0) }
  .rodata 0x8039f57c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
