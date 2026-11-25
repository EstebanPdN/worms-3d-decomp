/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_trajectory_800d9628)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
neutral_80389568 = 0x80389568;
refresh_801797b4 = 0x801797b4;
touch_80341584 = 0x80341584;
SECTIONS {
  .text.w3d_cx11a_trajectory_800d9628 0x800d9628 : { *(.text.w3d_cx11a_trajectory_800d9628) }
  .rodata 0x80389560 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
