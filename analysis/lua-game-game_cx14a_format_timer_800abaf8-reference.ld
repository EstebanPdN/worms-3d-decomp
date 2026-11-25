/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_format_timer_800abaf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
context_80165254 = 0x80165254;
format_802ec254 = 0x802ec254;
format_80381c1c = 0x80381c1c;
remaining_800ac0f4 = 0x800ac0f4;
SECTIONS {
  .text.w3d_cx14a_format_timer_800abaf8 0x800abaf8 : { *(.text.w3d_cx14a_format_timer_800abaf8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
