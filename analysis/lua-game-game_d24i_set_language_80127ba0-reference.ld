/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_set_language_80127ba0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__11d24i_String = 0x803426b8;
d24i_debug_802fb7ac = 0x802fb7ac;
d24i_entries_803fcd30 = 0x803fcd30;
d24i_load_entry_800fd504 = 0x800fd504;
d24i_message_8039bd6c = 0x8039bd6c;
d24i_name_8039bd80 = 0x8039bd80;
d24i_name_8039bd94 = 0x8039bd94;
d24i_name_8039bda4 = 0x8039bda4;
d24i_name_8039bdb8 = 0x8039bdb8;
d24i_refresh_80209968 = 0x80209968;
d24i_setting_read_800fc2b0 = 0x800fc2b0;
d24i_setting_write_800fc550 = 0x800fc550;
d24i_string_assign_8020bd38 = 0x8020bd38;
d24i_string_finish_8020c5c4 = 0x8020c5c4;
d24i_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d24i_set_language_80127ba0 0x80127ba0 : { *(.text.d24i_set_language_80127ba0) }
  .sdata 0x804b06a4 (NOLOAD) : {
    . = 0x0; d24i_state_804b06a4 = .;
    . = 0x10e4; d24i_service_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
