/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d21c_effect_motion_800dc244)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_803898e4 = 0x803898e4;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d21c_effect_motion_800dc244 0x800dc244 : { *(.text.d21c_effect_motion_800dc244) }
  .rodata 0x803898e8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
