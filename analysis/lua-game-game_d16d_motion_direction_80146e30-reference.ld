/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16d_motion_normalize_direction_80146e30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_member_80141564 = 0x80141564;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d16d_motion_normalize_direction_80146e30 0x80146e30 : { *(.text.d16d_motion_normalize_direction_80146e30) }
  .rodata 0x803a0fec : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
