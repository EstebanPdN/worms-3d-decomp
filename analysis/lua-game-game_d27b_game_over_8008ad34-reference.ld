/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27b_game_over_8008ad34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
s_8037daf4 = 0x8037daf4;
s_8037dc3c = 0x8037dc3c;
s_8037dc50 = 0x8037dc50;
s_8037dc58 = 0x8037dc58;
s_8037dc70 = 0x8037dc70;
s_8037dc78 = 0x8037dc78;
s_8037dc80 = 0x8037dc80;
s_8037dc8c = 0x8037dc8c;
s_8037dc98 = 0x8037dc98;
s_8037dca0 = 0x8037dca0;
s_8037dcbc = 0x8037dcbc;
s_8037dcc0 = 0x8037dcc0;
s_8037dcd0 = 0x8037dcd0;
s_8037dce8 = 0x8037dce8;
s_8037dcfc = 0x8037dcfc;
s_8037dd0c = 0x8037dd0c;
s_8037dd1c = 0x8037dd1c;
s_8037dd34 = 0x8037dd34;
s_8037dd54 = 0x8037dd54;
s_8037dd6c = 0x8037dd6c;
s_8037dd88 = 0x8037dd88;
s_8037dd9c = 0x8037dd9c;
s_8037ddac = 0x8037ddac;
s_8037ddc8 = 0x8037ddc8;
s_8037dde8 = 0x8037dde8;
s_8037de08 = 0x8037de08;
s_8037de28 = 0x8037de28;
s_8037de5c = 0x8037de5c;
s_8037de6c = 0x8037de6c;
w3d_address_80127da4 = 0x80127da4;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_camera_select_80035a30 = 0x80035a30;
w3d_cast_803426b4 = 0x803426b4;
w3d_context_80165254 = 0x80165254;
w3d_count_records_8008acd0 = 0x8008acd0;
w3d_handle_800fc82c = 0x800fc82c;
w3d_handle_800fc948 = 0x800fc948;
w3d_inventory_reset_8008b80c = 0x8008b80c;
w3d_list_freeze_800c4de8 = 0x800c4de8;
w3d_list_toggle_800c4b00 = 0x800c4b00;
w3d_list_trim_800c4e18 = 0x800c4e18;
w3d_member_count_8008ac48 = 0x8008ac48;
w3d_message_equals_8015f65c = 0x8015f65c;
w3d_message_get_800a830c = 0x800a830c;
w3d_message_int_init_800a82f0 = 0x800a82f0;
w3d_message_post_8016239c = 0x8016239c;
w3d_player_800fc6dc = 0x800fc6dc;
w3d_pool_add_800c53a0 = 0x800c53a0;
w3d_read_int_800fc230 = 0x800fc230;
w3d_read_scheme_800fc330 = 0x800fc330;
w3d_read_text_800fc2b0 = 0x800fc2b0;
w3d_read_time_800fc1f0 = 0x800fc1f0;
w3d_record_800fc7f8 = 0x800fc7f8;
w3d_strcmp_802ef234 = 0x802ef234;
w3d_string_assign_8020bd38 = 0x8020bd38;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_format_8020c510 = 0x8020c510;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
w3d_timer_set_8006e750 = 0x8006e750;
w3d_value_80178c48 = 0x80178c48;
w3d_vtable_8040db38 = 0x8040db38;
w3d_write_int_800fc43c = 0x800fc43c;
w3d_write_text_800fc550 = 0x800fc550;
SECTIONS {
  .text.w3d_d27b_game_over_8008ad34 0x8008ad34 : { *(.text.w3d_d27b_game_over_8008ad34) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_camera_804aa8c8 = .;
    . = 0x1f4; w3d_lists_804aaabc = .;
    . = 0xb58; w3d_flag_804ab420 = .;
    . = 0x3314; c_804adbdc = .;
    . = 0x337c; c_804adc44 = .;
    . = 0x3384; c_804adc4c = .;
    . = 0x338c; c_804adc54 = .;
    . = 0x3394; c_804adc5c = .;
    . = 0x339c; c_804adc64 = .;
    . = 0x33a4; c_804adc6c = .;
    . = 0x33ac; c_804adc74 = .;
    . = 0x33b4; c_804adc7c = .;
    . = 0x33bc; c_804adc84 = .;
    . = 0x33c4; c_804adc8c = .;
    . = 0x33cc; c_804adc94 = .;
    . = 0x340c; c_804adcd4 = .;
    . = 0x3424; c_804adcec = .;
    . = 0x349c; c_804add64 = .;
    . = 0x34ac; c_804add74 = .;
    . = 0x6e8c; w3d_arena_804b1754 = .;
    . = 0x6ec0; w3d_system_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
