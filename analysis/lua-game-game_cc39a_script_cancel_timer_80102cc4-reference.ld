/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39a_script_cancel_timer_80102cc4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39a_cancel_80060050 = 0x80060050;
cc39a_countError_80398fe8 = 0x80398fe8;
cc39a_isnumber_802cda9c = 0x802cda9c;
cc39a_number_802cdc5c = 0x802cdc5c;
cc39a_report_801022ec = 0x801022ec;
cc39a_settop_802cd808 = 0x802cd808;
cc39a_top_802cd7f4 = 0x802cd7f4;
cc39a_typeError_80399020 = 0x80399020;
SECTIONS {
  .text.cc39a_script_cancel_timer_80102cc4 0x80102cc4 : { *(.text.cc39a_script_cancel_timer_80102cc4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
