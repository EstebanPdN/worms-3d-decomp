/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f7b_direction_angles_800ccf50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e7c30 = 0x802e7c30;
default_8045e788 = 0x8045e788;
sqrt_802e82c0 = 0x802e82c0;
turn_80387e20 = 0x80387e20;
SECTIONS {
  .text.f7b_direction_angles_800ccf50 0x800ccf50 : { *(.text.f7b_direction_angles_800ccf50) }
  .rodata 0x80387e18 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
