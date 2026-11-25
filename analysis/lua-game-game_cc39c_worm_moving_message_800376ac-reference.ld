/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39c_worm_moving_message_800376ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39c_context_query_8015abcc = 0x8015abcc;
cc39c_default_80373e44 = 0x80373e44;
cc39c_deleted_id_80373e4c = 0x80373e4c;
cc39c_handle_cast_80341584 = 0x80341584;
cc39c_message_is_8015f65c = 0x8015f65c;
cc39c_message_text_8010a8fc = 0x8010a8fc;
cc39c_move_state_801797b4 = 0x801797b4;
cc39c_play_named_80035714 = 0x80035714;
cc39c_read_int_property_800fc230 = 0x800fc230;
cc39c_strcmp_802ef234 = 0x802ef234;
cc39c_string_base_finish_8020c5c4 = 0x8020c5c4;
cc39c_string_from_text_8020bb54 = 0x8020bb54;
cc39c_string_release_80341588 = 0x80341588;
cc39c_worm_moving_80373dd0 = 0x80373dd0;
cc39c_zero_80373e60 = 0x80373e60;
SECTIONS {
  .text.cc39c_worm_moving_message_800376ac 0x800376ac : { *(.text.cc39c_worm_moving_message_800376ac) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; cc39c_sounds_804aa8c8 = .;
    . = 0x2778; cc39c_message_804ad040 = .;
    . = 0x2780; cc39c_message_804ad048 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
