/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_script_close_lock_80103254)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38a_count_error_803991f0 = 0x803991f0;
cc38a_destroy_80178474 = 0x80178474;
cc38a_lock_error_8039925c = 0x8039925c;
cc38a_report_801022ec = 0x801022ec;
cc38a_settop_802cd808 = 0x802cd808;
cc38a_top_802cd7f4 = 0x802cd7f4;
cc38a_type_802cd9e8 = 0x802cd9e8;
cc38a_type_error_8039922c = 0x8039922c;
cc38a_userdata_802cde08 = 0x802cde08;
SECTIONS {
  .text.cc38a_script_close_lock_80103254 0x80103254 : { *(.text.cc38a_script_close_lock_80103254) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
