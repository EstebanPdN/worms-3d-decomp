/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_audio_set_mode5_80129738)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_app_enter_8015cc24 = 0x8015cc24;
w3d_app_is_active_8015ccbc = 0x8015ccbc;
w3d_app_leave_8015cc64 = 0x8015cc64;
w3d_base_construct_800ea180 = 0x800ea180;
w3d_base_construct_8015fef0 = 0x8015fef0;
w3d_base_destroy_800ea324 = 0x800ea324;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_base_handle_message_800ea62c = 0x800ea62c;
w3d_base_handle_message_8015fb34 = 0x8015fb34;
w3d_data_8039cff0 = 0x8039cff0;
w3d_empty_80341584 = 0x80341584;
w3d_f32_8039d22c = 0x8039d22c;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_message_is_8015f620 = 0x8015f620;
w3d_options_select_80127ba0 = 0x80127ba0;
w3d_owner_list_remove = 0x8020fd2c;
w3d_resource_info_801797b4 = 0x801797b4;
w3d_save_set_int_800fc43c = 0x800fc43c;
w3d_selector_set_80178d28 = 0x80178d28;
w3d_sound_mode_802ff730 = 0x802ff730;
w3d_state_register = 0x8020fd04;
w3d_str_8039c994 = 0x8039c994;
w3d_str_8039d9b0 = 0x8039d9b0;
w3d_str_8039daa4 = 0x8039daa4;
w3d_str_8039dac4 = 0x8039dac4;
w3d_vec_message_value_80126034 = 0x80126034;
w3d_video_mode_802ff854 = 0x802ff854;
w3d_walking_payload_logic_entity_attach_8012a618 = 0x8012a618;
w3d_walking_payload_logic_entity_list_80361470 = 0x80361470;
w3d_walking_payload_logic_entity_vtable_80410cd0 = 0x80410cd0;
w3d_water_ripples_graphic_entity_add_ripple_8012ad58 = 0x8012ad58;
w3d_water_ripples_graphic_entity_attach_8012aec0 = 0x8012aec0;
w3d_water_ripples_graphic_entity_list_803614a0 = 0x803614a0;
w3d_water_ripples_graphic_entity_vtable_80410d40 = 0x80410d40;
w3d_water_sparkles_graphic_entity_attach_8012b870 = 0x8012b870;
w3d_water_sparkles_graphic_entity_list_803614d0 = 0x803614d0;
w3d_water_sparkles_graphic_entity_vtable_80410d80 = 0x80410d80;
w3d_weapon_cursor_graphic_entity_attach_8012bd78 = 0x8012bd78;
w3d_weapon_cursor_graphic_entity_list_80361500 = 0x80361500;
w3d_weapon_cursor_graphic_entity_vtable_80410dc0 = 0x80410dc0;
w3d_weapon_flags_80451a9c = 0x80451a9c;
w3d_weapon_layout_803fd9e4 = 0x803fd9e4;
w3d_weapon_select_panel_logic_entity_construct_8012c098 = 0x8012c098;
w3d_weapon_select_panel_logic_entity_list_80361530 = 0x80361530;
w3d_weapon_select_panel_logic_entity_vtable_80410e00 = 0x80410e00;
w3d_weapon_select_panel_refresh_8012f77c = 0x8012f77c;
SECTIONS {
  .text.w3d_audio_set_mode5_80129738 0x80129738 : { *(.text.w3d_audio_set_mode5_80129738) }
  .text.w3d_options_apply_sound_mode_80129770 0x80129770 : { *(.text.w3d_options_apply_sound_mode_80129770) }
  .text.w3d_options_apply_video_mode_801297ec 0x801297ec : { *(.text.w3d_options_apply_video_mode_801297ec) }
  .text.w3d_app_enter_80129878 0x80129878 : { *(.text.w3d_app_enter_80129878) }
  .text.w3d_app_leave_801298cc 0x801298cc : { *(.text.w3d_app_leave_801298cc) }
  .text.w3d_options_table_801299b8 0x801299b8 : { *(.text.w3d_options_table_801299b8) }
  .text.w3d_walking_payload_logic_entity_list_get_801299c4 0x801299c4 : { *(.text.w3d_walking_payload_logic_entity_list_get_801299c4) }
  .text.w3d_walking_payload_logic_entity_unlink_801299d0 0x801299d0 : { *(.text.w3d_walking_payload_logic_entity_unlink_801299d0) }
  .text.w3d_walking_payload_logic_entity_create_80129a14 0x80129a14 : { *(.text.w3d_walking_payload_logic_entity_create_80129a14) }
  .text.w3d_walking_payload_logic_entity_release_80129a74 0x80129a74 : { *(.text.w3d_walking_payload_logic_entity_release_80129a74) }
  .text.w3d_walking_payload_logic_entity_retain_80129ad0 0x80129ad0 : { *(.text.w3d_walking_payload_logic_entity_retain_80129ad0) }
  .text.w3d_walking_payload_logic_entity_construct_80129ae8 0x80129ae8 : { *(.text.w3d_walking_payload_logic_entity_construct_80129ae8) }
  .text.w3d_walking_payload_logic_entity_destroy_80129b2c 0x80129b2c : { *(.text.w3d_walking_payload_logic_entity_destroy_80129b2c) }
  .text.w3d_walking_payload_logic_entity_handle_message_80129b5c 0x80129b5c : { *(.text.w3d_walking_payload_logic_entity_handle_message_80129b5c) }
  .text.w3d_walking_payload_logic_entity_detach_8012a6bc 0x8012a6bc : { *(.text.w3d_walking_payload_logic_entity_detach_8012a6bc) }
  .text.w3d_walking_payload_logic_entity_get_offset_8012a6c0 0x8012a6c0 : { *(.text.w3d_walking_payload_logic_entity_get_offset_8012a6c0) }
  .text.w3d_water_ripples_graphic_entity_list_get_8012a814 0x8012a814 : { *(.text.w3d_water_ripples_graphic_entity_list_get_8012a814) }
  .text.w3d_water_ripples_graphic_entity_unlink_8012a820 0x8012a820 : { *(.text.w3d_water_ripples_graphic_entity_unlink_8012a820) }
  .text.w3d_water_ripples_graphic_entity_create_8012a864 0x8012a864 : { *(.text.w3d_water_ripples_graphic_entity_create_8012a864) }
  .text.w3d_water_ripples_graphic_entity_release_8012a8c4 0x8012a8c4 : { *(.text.w3d_water_ripples_graphic_entity_release_8012a8c4) }
  .text.w3d_water_ripples_graphic_entity_retain_8012a920 0x8012a920 : { *(.text.w3d_water_ripples_graphic_entity_retain_8012a920) }
  .text.w3d_water_ripples_graphic_entity_construct_8012a938 0x8012a938 : { *(.text.w3d_water_ripples_graphic_entity_construct_8012a938) }
  .text.w3d_water_ripples_graphic_entity_destroy_8012a980 0x8012a980 : { *(.text.w3d_water_ripples_graphic_entity_destroy_8012a980) }
  .text.w3d_water_ripples_graphic_entity_handle_message_8012a9fc 0x8012a9fc : { *(.text.w3d_water_ripples_graphic_entity_handle_message_8012a9fc) }
  .text.w3d_water_ripples_graphic_entity_detach_8012affc 0x8012affc : { *(.text.w3d_water_ripples_graphic_entity_detach_8012affc) }
  .text.w3d_water_sparkles_graphic_entity_list_get_8012b09c 0x8012b09c : { *(.text.w3d_water_sparkles_graphic_entity_list_get_8012b09c) }
  .text.w3d_water_sparkles_graphic_entity_unlink_8012b0a8 0x8012b0a8 : { *(.text.w3d_water_sparkles_graphic_entity_unlink_8012b0a8) }
  .text.w3d_water_sparkles_graphic_entity_create_8012b0ec 0x8012b0ec : { *(.text.w3d_water_sparkles_graphic_entity_create_8012b0ec) }
  .text.w3d_water_sparkles_graphic_entity_release_8012b14c 0x8012b14c : { *(.text.w3d_water_sparkles_graphic_entity_release_8012b14c) }
  .text.w3d_water_sparkles_graphic_entity_retain_8012b1a8 0x8012b1a8 : { *(.text.w3d_water_sparkles_graphic_entity_retain_8012b1a8) }
  .text.w3d_water_sparkles_graphic_entity_construct_8012b1c0 0x8012b1c0 : { *(.text.w3d_water_sparkles_graphic_entity_construct_8012b1c0) }
  .text.w3d_water_sparkles_graphic_entity_destroy_8012b208 0x8012b208 : { *(.text.w3d_water_sparkles_graphic_entity_destroy_8012b208) }
  .text.w3d_water_sparkles_graphic_entity_handle_message_8012b284 0x8012b284 : { *(.text.w3d_water_sparkles_graphic_entity_handle_message_8012b284) }
  .text.w3d_water_sparkles_graphic_entity_detach_8012ba08 0x8012ba08 : { *(.text.w3d_water_sparkles_graphic_entity_detach_8012ba08) }
  .text.w3d_weapon_cursor_graphic_entity_list_get_8012ba98 0x8012ba98 : { *(.text.w3d_weapon_cursor_graphic_entity_list_get_8012ba98) }
  .text.w3d_weapon_cursor_graphic_entity_unlink_8012baa4 0x8012baa4 : { *(.text.w3d_weapon_cursor_graphic_entity_unlink_8012baa4) }
  .text.w3d_weapon_cursor_graphic_entity_create_8012bae8 0x8012bae8 : { *(.text.w3d_weapon_cursor_graphic_entity_create_8012bae8) }
  .text.w3d_weapon_cursor_graphic_entity_release_8012bb48 0x8012bb48 : { *(.text.w3d_weapon_cursor_graphic_entity_release_8012bb48) }
  .text.w3d_weapon_cursor_graphic_entity_retain_8012bba4 0x8012bba4 : { *(.text.w3d_weapon_cursor_graphic_entity_retain_8012bba4) }
  .text.w3d_weapon_cursor_graphic_entity_construct_8012bbbc 0x8012bbbc : { *(.text.w3d_weapon_cursor_graphic_entity_construct_8012bbbc) }
  .text.w3d_weapon_cursor_graphic_entity_destroy_8012bc04 0x8012bc04 : { *(.text.w3d_weapon_cursor_graphic_entity_destroy_8012bc04) }
  .text.w3d_weapon_cursor_graphic_entity_handle_message_8012bc80 0x8012bc80 : { *(.text.w3d_weapon_cursor_graphic_entity_handle_message_8012bc80) }
  .text.w3d_weapon_cursor_graphic_entity_detach_8012bee4 0x8012bee4 : { *(.text.w3d_weapon_cursor_graphic_entity_detach_8012bee4) }
  .text.w3d_weapon_select_panel_logic_entity_list_get_8012bf74 0x8012bf74 : { *(.text.w3d_weapon_select_panel_logic_entity_list_get_8012bf74) }
  .text.w3d_weapon_select_panel_logic_entity_unlink_8012bf80 0x8012bf80 : { *(.text.w3d_weapon_select_panel_logic_entity_unlink_8012bf80) }
  .text.w3d_weapon_select_panel_logic_entity_create_8012bfc4 0x8012bfc4 : { *(.text.w3d_weapon_select_panel_logic_entity_create_8012bfc4) }
  .text.w3d_weapon_select_panel_logic_entity_release_8012c024 0x8012c024 : { *(.text.w3d_weapon_select_panel_logic_entity_release_8012c024) }
  .text.w3d_weapon_select_panel_logic_entity_retain_8012c080 0x8012c080 : { *(.text.w3d_weapon_select_panel_logic_entity_retain_8012c080) }
  .text.w3d_weapon_select_panel_logic_entity_destroy_8012c348 0x8012c348 : { *(.text.w3d_weapon_select_panel_logic_entity_destroy_8012c348) }
  .text.w3d_weapon_layout_row_start_8012c768 0x8012c768 : { *(.text.w3d_weapon_layout_row_start_8012c768) }
  .text.w3d_weapon_select_panel_refresh_if_dirty_8012d894 0x8012d894 : { *(.text.w3d_weapon_select_panel_refresh_if_dirty_8012d894) }
  .text.w3d_weapon_select_panel_reason_text_8012f0f8 0x8012f0f8 : { *(.text.w3d_weapon_select_panel_reason_text_8012f0f8) }
  .text.w3d_weapon_flags_8012f954 0x8012f954 : { *(.text.w3d_weapon_flags_8012f954) }
  .text.w3d_weapon_select_panel_set_mode_8012f964 0x8012f964 : { *(.text.w3d_weapon_select_panel_set_mode_8012f964) }
  .sdata 0x804ab0cc (NOLOAD) : {
    . = 0x0; w3d_weapon_select_panel_instance_804ab0cc = .;
    . = 0x0; w3d_weapon_select_panel_logic_entity_instance_804ab0cc = .;
    . = 0x4; w3d_weapon_select_panel_mode_804ab0d0 = .;
    . = 0x453c; w3d_msg_804af608 = .;
    . = 0x66bc; w3d_application_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
