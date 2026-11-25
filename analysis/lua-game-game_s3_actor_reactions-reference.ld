/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_special_flag)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_80178d1c = 0x80178d1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_native_cast = 0x80342a78;
w3d_engine_get_context = 0x80165254;
w3d_f32_803a179c = 0x803a179c;
w3d_f32_803a17a0 = 0x803a17a0;
w3d_f32_803a17b8 = 0x803a17b8;
w3d_f32_803a17bc = 0x803a17bc;
w3d_f32_803a17d0 = 0x803a17d0;
w3d_f32_803a1850 = 0x803a1850;
w3d_factory_8040fe30 = 0x8040fe30;
w3d_fn_80022e20 = 0x80022e20;
w3d_fn_8004d870 = 0x8004d870;
w3d_fn_800b0824 = 0x800b0824;
w3d_fn_800dc3dc = 0x800dc3dc;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_800fc710 = 0x800fc710;
w3d_fn_800fc7f8 = 0x800fc7f8;
w3d_fn_800fdc80 = 0x800fdc80;
w3d_fn_801492ec = 0x801492ec;
w3d_fn_8014c488 = 0x8014c488;
w3d_fn_8014dc04 = 0x8014dc04;
w3d_fn_8014dcbc = 0x8014dcbc;
w3d_fn_8014de70 = 0x8014de70;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80164514 = 0x80164514;
w3d_fn_80178474 = 0x80178474;
w3d_fn_80178d28 = 0x80178d28;
w3d_fn_8020b680 = 0x8020b680;
w3d_get_800a830c = 0x800a830c;
w3d_handle_member_query_8012629c = 0x8012629c;
w3d_jump_origin_804538d4 = 0x804538d4;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_str_803a0e2c = 0x803a0e2c;
w3d_str_803a17c0 = 0x803a17c0;
w3d_type_80361860 = 0x80361860;
w3d_type_803618f0 = 0x803618f0;
w3d_zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_actor_special_flag 0x8014e9b4 : { *(.text.w3d_actor_special_flag) }
  .text.w3d_actor_lock_for_team_message 0x8014f728 : { *(.text.w3d_actor_lock_for_team_message) }
  .text.w3d_actor_unlock_for_team_message 0x8014f7d8 : { *(.text.w3d_actor_unlock_for_team_message) }
  .text.w3d_actor_post_team_message 0x8014f860 : { *(.text.w3d_actor_post_team_message) }
  .text.w3d_actor_ground_cast_clear 0x8014fcac : { *(.text.w3d_actor_ground_cast_clear) }
  .text.w3d_actor_start_jump 0x8014fd38 : { *(.text.w3d_actor_start_jump) }
  .text.w3d_actor_post_player_effect 0x8014fee8 : { *(.text.w3d_actor_post_player_effect) }
  .text.w3d_actor_clear_active_state 0x8014ffa4 : { *(.text.w3d_actor_clear_active_state) }
  .text.w3d_actor_camera_target_position 0x80150b38 : { *(.text.w3d_actor_camera_target_position) }
  .text.w3d_actor_create_third_link 0x80150b6c : { *(.text.w3d_actor_create_third_link) }
  .text.w3d_actor_has_active_link 0x801510c4 : { *(.text.w3d_actor_has_active_link) }
  .sdata 0x804afca8 (NOLOAD) : {
    . = 0x0; w3d_cached_804afca8 = .;
    . = 0x1aac; w3d_global_804b1754 = .;
    . = 0x1abc; w3d_cast_result_804b1764 = .;
    . = 0x1ae4; w3d_global_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
