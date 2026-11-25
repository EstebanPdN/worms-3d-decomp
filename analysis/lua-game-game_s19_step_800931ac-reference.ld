/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_step_all_800931ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800d40f4 = 0x800d40f4;
FUN_800d4584 = 0x800d4584;
w3d_auto_80178c48 = 0x80178c48;
w3d_motion_step_800d3160 = 0x800d3160;
SECTIONS {
  .text.s19_step_all_800931ac 0x800931ac : { *(.text.s19_step_all_800931ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
