/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17a_select_plans_800071ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
empty_800072b0 = 0x800072b0;
pop_800075b0 = 0x800075b0;
push_800075c4 = 0x800075c4;
sort_800076c4 = 0x800076c4;
state_800068a8 = 0x800068a8;
terminal_8036951c = 0x8036951c;
SECTIONS {
  .text.w3d_cc17a_select_plans_800071ec 0x800071ec : { *(.text.w3d_cc17a_select_plans_800071ec) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; selected_804aa558 = .;
    . = 0x8; pending_804aa560 = .;
    . = 0x24; flag_804aa57c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
