/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8a_motion_state_assign_800d308c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
reset_80388cc4 = 0x80388cc4;
state_query_8015a6b8 = 0x8015a6b8;
SECTIONS {
  .text.w3d_cx8a_motion_state_assign_800d308c 0x800d308c : { *(.text.w3d_cx8a_motion_state_assign_800d308c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
