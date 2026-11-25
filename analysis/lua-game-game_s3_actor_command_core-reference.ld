/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_command_jump)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_reset_construction_words = 0x8015286c;
w3d_actor_start_jump = 0x8014fd38;
w3d_auto_80020b20 = 0x80020b20;
w3d_auto_8014fedc = 0x8014fedc;
w3d_auto_80178c48 = 0x80178c48;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_803426b4 = 0x803426b4;
w3d_engine_get_context = 0x80165254;
w3d_f32_803a1b44 = 0x803a1b44;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_800fc7f8 = 0x800fc7f8;
w3d_fn_80131b50 = 0x80131b50;
w3d_fn_801418dc = 0x801418dc;
w3d_fn_80152a80 = 0x80152a80;
w3d_fn_801613f0 = 0x801613f0;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_motion_owner_matches = 0x8014c488;
w3d_motion_slope_allowed = 0x8014c7fc;
w3d_str_803a1be4 = 0x803a1be4;
w3d_str_803a1bec = 0x803a1bec;
w3d_type_8040db38 = 0x8040db38;
w3d_zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_actor_command_jump 0x80151c78 : { *(.text.w3d_actor_command_jump) }
  .text.w3d_actor_command_finish_flag 0x80152694 : { *(.text.w3d_actor_command_finish_flag) }
  .text.w3d_actor_command_check_progress 0x8015287c : { *(.text.w3d_actor_command_check_progress) }
  .text.w3d_actor_command_reset_owner 0x801529d8 : { *(.text.w3d_actor_command_reset_owner) }
  .text.w3d_actor_probe_slope 0x801531b0 : { *(.text.w3d_actor_probe_slope) }
  .text.w3d_actor_post_alliance_value 0x801533a4 : { *(.text.w3d_actor_post_alliance_value) }
  .text.w3d_actor_is_same_alliance 0x80153458 : { *(.text.w3d_actor_is_same_alliance) }
  .text.w3d_actor_has_list_entity 0x80153a1c : { *(.text.w3d_actor_has_list_entity) }
  .text.w3d_actor_post_owner_state_ten 0x80153c74 : { *(.text.w3d_actor_post_owner_state_ten) }
  .text.w3d_actor_entity_has_positive_state 0x80153db4 : { *(.text.w3d_actor_entity_has_positive_state) }
  .text.w3d_actor_set_fire_mode 0x80153dfc : { *(.text.w3d_actor_set_fire_mode) }
  .text.w3d_actor_mode_is_fourteen_to_eighteen 0x80153f38 : { *(.text.w3d_actor_mode_is_fourteen_to_eighteen) }
  .text.w3d_actor_apply_motion_segment 0x80153f80 : { *(.text.w3d_actor_apply_motion_segment) }
  .sdata 0x804aaef8 (NOLOAD) : {
    . = 0x0; w3d_flag_804aaef8 = .;
    . = 0x4; w3d_flag_804aaefc = .;
    . = 0x528; w3d_flag_804ab420 = .;
    . = 0x4c48; w3d_cache_804afb40 = .;
    . = 0x4d98; w3d_cache_804afc90 = .;
    . = 0x4e20; w3d_cache_804afd18 = .;
    . = 0x4e28; w3d_cache_804afd20 = .;
    . = 0x4e60; w3d_cache_804afd58 = .;
    . = 0x4e70; w3d_cache_804afd68 = .;
    . = 0x4e78; w3d_cache_804afd70 = .;
    . = 0x4f04; w3d_cache_804afdfc = .;
    . = 0x685c; w3d_global_804b1754 = .;
    . = 0x6868; w3d_global_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
