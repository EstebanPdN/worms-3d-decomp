/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_facing_target_8013b3b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
cos_802e86d4 = 0x802e86d4;
sin_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d25d_facing_target_8013b3b8 0x8013b3b8 : { *(.text.d25d_facing_target_8013b3b8) }
  .rodata 0x8039f7d8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
