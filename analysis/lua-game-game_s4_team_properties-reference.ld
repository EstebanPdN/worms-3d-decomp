/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_team_update_named_state)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_lookup_text_800fc2b0 = 0x800fc2b0;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_str_803d097c = 0x803d097c;
w3d_str_803d0bf0 = 0x803d0bf0;
w3d_str_803d0c2c = 0x803d0c2c;
w3d_str_803d0c40 = 0x803d0c40;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_from_text = 0x8020bb54;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_team_kind_802997fc = 0x802997fc;
w3d_team_set_named_80299b48 = 0x80299b48;
w3d_update_team_8029b83c = 0x8029b83c;
SECTIONS {
  .text.w3d_s4_team_update_named_state 0x80298dd4 : { *(.text.w3d_s4_team_update_named_state) }
  .text.w3d_s4_team_has_capacity 0x80299a94 : { *(.text.w3d_s4_team_has_capacity) }
  .text.w3d_s4_team_refresh_game_names 0x8029b410 : { *(.text.w3d_s4_team_refresh_game_names) }
  .text.w3d_s4_team_update_for_game_type 0x8029b73c : { *(.text.w3d_s4_team_update_for_game_type) }
  .text.w3d_s4_team_network_update 0x8029b7e4 : { *(.text.w3d_s4_team_network_update) }
  .sdata 0x804b0e54 (NOLOAD) : {
    . = 0x0; w3d_message_804b0e54 = .;
    . = 0x900; w3d_global_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
