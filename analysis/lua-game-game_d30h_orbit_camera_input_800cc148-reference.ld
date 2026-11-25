/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30h_orbit_camera_input_800cc148)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
construct_801f7538 = 0x801f7538;
in_range_800cc070 = 0x800cc070;
lbl_80387d34 = 0x80387d34;
lbl_8043ae20 = 0x8043ae20;
read_80178df0 = 0x80178df0;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d30h_orbit_camera_input_800cc148 0x800cc148 : { *(.text.d30h_orbit_camera_input_800cc148) }
  .rodata 0x80387d38 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
