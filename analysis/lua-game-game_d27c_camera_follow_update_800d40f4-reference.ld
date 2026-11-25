/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_camera_follow_update_800d40f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
spherical_800d4d64 = 0x800d4d64;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d27c_camera_follow_update_800d40f4 0x800d40f4 : { *(.text.d27c_camera_follow_update_800d40f4) }
  .rodata 0x80388ce8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
