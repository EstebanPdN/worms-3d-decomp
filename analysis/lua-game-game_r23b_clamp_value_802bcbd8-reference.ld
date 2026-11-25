/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r23b_clamp_value_802bcbd8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
r23b_lower_803d82f8 = 0x803d82f8;
r23b_refresh_802bc570 = 0x802bc570;
r23b_upper_803d82fc = 0x803d82fc;
SECTIONS {
  .text.w3d_r23b_clamp_value_802bcbd8 0x802bcbd8 : { *(.text.w3d_r23b_clamp_value_802bcbd8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
