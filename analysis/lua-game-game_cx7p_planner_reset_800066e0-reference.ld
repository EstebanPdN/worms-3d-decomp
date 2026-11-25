/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7p_planner_reset_800066e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
copy_802eee50 = 0x802eee50;
named_destroy_80341518 = 0x80341518;
planner_state_800068a8 = 0x800068a8;
reset_time_803694e4 = 0x803694e4;
vector_destroy_803414b4 = 0x803414b4;
SECTIONS {
  .text.w3d_cx7p_planner_reset_800066e0 0x800066e0 : { *(.text.w3d_cx7p_planner_reset_800066e0) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; plans_804aa558 = .;
    . = 0x4; costs_804aa55c = .;
    . = 0x8; pending_804aa560 = .;
    . = 0x14; planner_zero_804aa56c = .;
    . = 0x18; planner_time_804aa570 = .;
    . = 0x20; planner_zero_804aa578 = .;
    . = 0x24; planner_zero_804aa57c = .;
    . = 0x1f8; named_804aa750 = .;
    . = 0x1fc; first_range_804aa754 = .;
    . = 0x204; second_range_804aa75c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
