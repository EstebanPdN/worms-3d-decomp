/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_script_buffer_80102660)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__21cc38a_String_803426b8 = 0x803426b8;
cc38a_call_802ce73c = 0x802ce73c;
cc38a_finish_8020c5c4 = 0x8020c5c4;
cc38a_format_8020c510 = 0x8020c510;
cc38a_format_80398e58 = 0x80398e58;
cc38a_load_802ddbd8 = 0x802ddbd8;
cc38a_panic_80101f90 = 0x80101f90;
cc38a_release_80341588 = 0x80341588;
cc38a_report_801022ec = 0x801022ec;
cc38a_top_802cd7f4 = 0x802cd7f4;
SECTIONS {
  .text.cc38a_script_buffer_80102660 0x80102660 : { *(.text.cc38a_script_buffer_80102660) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
