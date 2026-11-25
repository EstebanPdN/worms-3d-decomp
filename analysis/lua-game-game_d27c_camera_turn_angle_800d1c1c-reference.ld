/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_camera_turn_angle_800d1c1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
cos_802e86d4 = 0x802e86d4;
raised_800cfd98 = 0x800cfd98;
sin_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d27c_camera_turn_angle_800d1c1c 0x800d1c1c : { *(.text.d27c_camera_turn_angle_800d1c1c) }
  .rodata 0x80388200 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
