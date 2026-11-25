/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_input_owner_on_message_8012028c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_base_construct_8015fef0 = 0x8015fef0;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_base_destroy_801628ec = 0x801628ec;
w3d_base_handle_message_8015fb34 = 0x8015fb34;
w3d_cached_message_id = 0x8015f5a0;
w3d_camera_set_mode_80035714 = 0x80035714;
w3d_component_attach_80125108 = 0x80125108;
w3d_component_construct_80124edc = 0x80124edc;
w3d_component_list_80361440 = 0x80361440;
w3d_component_on_worm_moved_801256f4 = 0x801256f4;
w3d_component_update_80125934 = 0x80125934;
w3d_component_vtable_80410bd8 = 0x80410bd8;
w3d_entity_attach_interface_80174820 = 0x80174820;
w3d_entity_finish_8015fd1c = 0x8015fd1c;
w3d_entity_get_point_8015ac04 = 0x8015ac04;
w3d_entity_has_focus_8015abcc = 0x8015abcc;
w3d_entity_lookup_80164fc8 = 0x80164fc8;
w3d_f32_8039b6c0 = 0x8039b6c0;
w3d_f32_8039b858 = 0x8039b858;
w3d_f32_8039b85c = 0x8039b85c;
w3d_f32_8039b860 = 0x8039b860;
w3d_f32_8039b864 = 0x8039b864;
w3d_game_paused_8006e71c = 0x8006e71c;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_input_active_80158dd4 = 0x80158dd4;
w3d_interface_id_804144f8 = 0x804144f8;
w3d_interface_lookup_8020b680 = 0x8020b680;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_handle_init_801190b4 = 0x801190b4;
w3d_message_int_init = 0x800a82f0;
w3d_message_is_8015f65c = 0x8015f65c;
w3d_message_payload_int_800a830c = 0x800a830c;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_message_vtable_8040db38 = 0x8040db38;
w3d_owner_list_remove = 0x8020fd2c;
w3d_payload_get_int_800fc230 = 0x800fc230;
w3d_random_80162ba8 = 0x80162ba8;
w3d_service_construct_801628b0 = 0x801628b0;
w3d_service_subscribe_80162024 = 0x80162024;
w3d_state_register = 0x8020fd04;
w3d_str_8039b6a4 = 0x8039b6a4;
w3d_str_8039b6ac = 0x8039b6ac;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_trail_graphic_entity_construct_80121878 = 0x80121878;
w3d_trail_graphic_entity_list_803613b0 = 0x803613b0;
w3d_trail_graphic_entity_vtable_80410b18 = 0x80410b18;
w3d_transition_play_80181640 = 0x80181640;
w3d_transition_service_list_803613e0 = 0x803613e0;
w3d_transition_service_load_mesh_801247d0 = 0x801247d0;
w3d_transition_service_vtable_80410b58 = 0x80410b58;
w3d_transition_state_80181ccc = 0x80181ccc;
w3d_trigger_graphic_entity_attach_80124c5c = 0x80124c5c;
w3d_trigger_graphic_entity_list_80361410 = 0x80361410;
w3d_trigger_graphic_entity_vtable_80410b98 = 0x80410b98;
w3d_vec3_zero_8043ae20 = 0x8043ae20;
w3d_worm_class_803615f0 = 0x803615f0;
w3d_worm_data_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.w3d_input_owner_on_message_8012028c 0x8012028c : { *(.text.w3d_input_owner_on_message_8012028c) }
  .text.w3d_entity_point_or_zero_801212d4 0x801212d4 : { *(.text.w3d_entity_point_or_zero_801212d4) }
  .text.w3d_input_owner_post_reorient_80121568 0x80121568 : { *(.text.w3d_input_owner_post_reorient_80121568) }
  .text.w3d_trail_graphic_entity_list_get_80121754 0x80121754 : { *(.text.w3d_trail_graphic_entity_list_get_80121754) }
  .text.w3d_trail_graphic_entity_unlink_80121760 0x80121760 : { *(.text.w3d_trail_graphic_entity_unlink_80121760) }
  .text.w3d_trail_graphic_entity_create_801217a4 0x801217a4 : { *(.text.w3d_trail_graphic_entity_create_801217a4) }
  .text.w3d_trail_graphic_entity_release_80121804 0x80121804 : { *(.text.w3d_trail_graphic_entity_release_80121804) }
  .text.w3d_trail_graphic_entity_retain_80121860 0x80121860 : { *(.text.w3d_trail_graphic_entity_retain_80121860) }
  .text.w3d_trail_graphic_entity_destroy_80121940 0x80121940 : { *(.text.w3d_trail_graphic_entity_destroy_80121940) }
  .text.w3d_trail_graphic_entity_handle_message_80121a78 0x80121a78 : { *(.text.w3d_trail_graphic_entity_handle_message_80121a78) }
  .text.w3d_trail_graphic_entity_attach_801222b8 0x801222b8 : { *(.text.w3d_trail_graphic_entity_attach_801222b8) }
  .text.w3d_trail_graphic_entity_set_segment_80122800 0x80122800 : { *(.text.w3d_trail_graphic_entity_set_segment_80122800) }
  .text.w3d_trail_graphic_entity_set_flag_80122af8 0x80122af8 : { *(.text.w3d_trail_graphic_entity_set_flag_80122af8) }
  .text.w3d_trail_graphic_entity_attach_interface_80122b04 0x80122b04 : { *(.text.w3d_trail_graphic_entity_attach_interface_80122b04) }
  .text.w3d_trail_graphic_entity_attach_interface_80122b80 0x80122b80 : { *(.text.w3d_trail_graphic_entity_attach_interface_80122b80) }
  .text.w3d_trail_graphic_entity_detach_80123e88 0x80123e88 : { *(.text.w3d_trail_graphic_entity_detach_80123e88) }
  .text.w3d_transition_service_list_get_80123f18 0x80123f18 : { *(.text.w3d_transition_service_list_get_80123f18) }
  .text.w3d_transition_service_unlink_80123f24 0x80123f24 : { *(.text.w3d_transition_service_unlink_80123f24) }
  .text.w3d_transition_service_create_80123f68 0x80123f68 : { *(.text.w3d_transition_service_create_80123f68) }
  .text.w3d_transition_service_release_80123fc8 0x80123fc8 : { *(.text.w3d_transition_service_release_80123fc8) }
  .text.w3d_transition_service_retain_80124024 0x80124024 : { *(.text.w3d_transition_service_retain_80124024) }
  .text.w3d_transition_service_construct_8012403c 0x8012403c : { *(.text.w3d_transition_service_construct_8012403c) }
  .text.w3d_transition_service_destroy_80124100 0x80124100 : { *(.text.w3d_transition_service_destroy_80124100) }
  .text.w3d_transition_service_tick_801242bc 0x801242bc : { *(.text.w3d_transition_service_tick_801242bc) }
  .text.w3d_transition_service_attach_801242e0 0x801242e0 : { *(.text.w3d_transition_service_attach_801242e0) }
  .text.w3d_transition_service_detach_801243b0 0x801243b0 : { *(.text.w3d_transition_service_detach_801243b0) }
  .text.w3d_transition_service_circle_in_80124424 0x80124424 : { *(.text.w3d_transition_service_circle_in_80124424) }
  .text.w3d_transition_service_circle_out_801244d8 0x801244d8 : { *(.text.w3d_transition_service_circle_out_801244d8) }
  .text.w3d_transition_service_update_8012458c 0x8012458c : { *(.text.w3d_transition_service_update_8012458c) }
  .text.w3d_transition_service_is_busy_801248cc 0x801248cc : { *(.text.w3d_transition_service_is_busy_801248cc) }
  .text.w3d_trigger_graphic_entity_list_get_80124a00 0x80124a00 : { *(.text.w3d_trigger_graphic_entity_list_get_80124a00) }
  .text.w3d_trigger_graphic_entity_unlink_80124a0c 0x80124a0c : { *(.text.w3d_trigger_graphic_entity_unlink_80124a0c) }
  .text.w3d_trigger_graphic_entity_create_80124a50 0x80124a50 : { *(.text.w3d_trigger_graphic_entity_create_80124a50) }
  .text.w3d_trigger_graphic_entity_release_80124ab0 0x80124ab0 : { *(.text.w3d_trigger_graphic_entity_release_80124ab0) }
  .text.w3d_trigger_graphic_entity_retain_80124b0c 0x80124b0c : { *(.text.w3d_trigger_graphic_entity_retain_80124b0c) }
  .text.w3d_trigger_graphic_entity_construct_80124b24 0x80124b24 : { *(.text.w3d_trigger_graphic_entity_construct_80124b24) }
  .text.w3d_trigger_graphic_entity_destroy_80124b6c 0x80124b6c : { *(.text.w3d_trigger_graphic_entity_destroy_80124b6c) }
  .text.w3d_trigger_graphic_entity_handle_message_80124bcc 0x80124bcc : { *(.text.w3d_trigger_graphic_entity_handle_message_80124bcc) }
  .text.w3d_trigger_graphic_entity_priority_80124c54 0x80124c54 : { *(.text.w3d_trigger_graphic_entity_priority_80124c54) }
  .text.w3d_trigger_graphic_entity_detach_80124d28 0x80124d28 : { *(.text.w3d_trigger_graphic_entity_detach_80124d28) }
  .text.w3d_component_list_get_80124db8 0x80124db8 : { *(.text.w3d_component_list_get_80124db8) }
  .text.w3d_component_unlink_80124dc4 0x80124dc4 : { *(.text.w3d_component_unlink_80124dc4) }
  .text.w3d_component_create_80124e08 0x80124e08 : { *(.text.w3d_component_create_80124e08) }
  .text.w3d_component_release_80124e68 0x80124e68 : { *(.text.w3d_component_release_80124e68) }
  .text.w3d_component_retain_80124ec4 0x80124ec4 : { *(.text.w3d_component_retain_80124ec4) }
  .text.w3d_component_destroy_80124f4c 0x80124f4c : { *(.text.w3d_component_destroy_80124f4c) }
  .text.w3d_component_handle_message_80124ff0 0x80124ff0 : { *(.text.w3d_component_handle_message_80124ff0) }
  .text.w3d_component_tick_801250c4 0x801250c4 : { *(.text.w3d_component_tick_801250c4) }
  .text.w3d_component_detach_80125404 0x80125404 : { *(.text.w3d_component_detach_80125404) }
  .text.w3d_component_on_target_8012545c 0x8012545c : { *(.text.w3d_component_on_target_8012545c) }
  .text.w3d_component_post_text_8012568c 0x8012568c : { *(.text.w3d_component_post_text_8012568c) }
  .text.w3d_component_radius_801256e4 0x801256e4 : { *(.text.w3d_component_radius_801256e4) }
  .text.w3d_component_position_801256ec 0x801256ec : { *(.text.w3d_component_position_801256ec) }
  .text.w3d_component_on_worm_entered_80125aa0 0x80125aa0 : { *(.text.w3d_component_on_worm_entered_80125aa0) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_camera_804aa8c8 = .;
    . = 0x77c; w3d_transition_service_instance_804ab044 = .;
    . = 0x780; w3d_transition_in_names_804ab048 = .;
    . = 0x788; w3d_transition_out_names_804ab050 = .;
    . = 0xb38; w3d_input_state_804ab400 = .;
    . = 0x4c04; w3d_msg_804af4cc = .;
    . = 0x4c14; w3d_msg_804af4dc = .;
    . = 0x4c1c; w3d_msg_804af4e4 = .;
    . = 0x4c28; w3d_msg_804af4f0 = .;
    . = 0x4c30; w3d_msg_804af4f8 = .;
    . = 0x4c38; w3d_msg_804af500 = .;
    . = 0x4c40; w3d_msg_804af508 = .;
    . = 0x4c50; w3d_msg_804af518 = .;
    . = 0x4c7c; w3d_msg_804af544 = .;
    . = 0x4c84; w3d_msg_804af54c = .;
    . = 0x4c8c; w3d_msg_804af554 = .;
    . = 0x4cc4; w3d_msg_804af58c = .;
    . = 0x6e8c; w3d_message_arena_804b1754 = .;
    . = 0x6fa4; w3d_trail_graphic_entity_current_804b186c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
