/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_trajectory_800d94a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
half_8038955c = 0x8038955c;
neutral_80389558 = 0x80389558;
refresh_801797b4 = 0x801797b4;
touch_80341584 = 0x80341584;
SECTIONS {
  .text.w3d_cx11a_trajectory_800d94a4 0x800d94a4 : { *(.text.w3d_cx11a_trajectory_800d94a4) }
  .rodata 0x80389550 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
