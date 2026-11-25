/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_reset_cell_80022704)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_reset_cell_80022704 0x80022704 : { *(.text.s19_reset_cell_80022704) }
  .text.s19_release_ref_80023200 0x80023200 : { *(.text.s19_release_ref_80023200) }
  .text.s19_fire_once_8002ad9c 0x8002ad9c : { *(.text.s19_fire_once_8002ad9c) }
  .text.s19_set_pose_8002e558 0x8002e558 : { *(.text.s19_set_pose_8002e558) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
