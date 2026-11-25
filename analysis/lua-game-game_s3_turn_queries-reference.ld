/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_turns_apply_named_scene_value)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178c48 = 0x80178c48;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_803426b4 = 0x803426b4;
w3d_f32_803a2cb8 = 0x803a2cb8;
w3d_fn_800fc230 = 0x800fc230;
w3d_fn_800fc43c = 0x800fc43c;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_80129424 = 0x80129424;
w3d_fn_80149f18 = 0x80149f18;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_motion_get_position_80066894 = 0x80066894;
w3d_str_803a2cbc = 0x803a2cbc;
w3d_type_803f04e8 = 0x803f04e8;
w3d_vec_message_value_80126034 = 0x80126034;
SECTIONS {
  .text.w3d_turns_apply_named_scene_value 0x80158810 : { *(.text.w3d_turns_apply_named_scene_value) }
  .text.w3d_turns_select_near_message_position 0x80158850 : { *(.text.w3d_turns_select_near_message_position) }
  .text.w3d_turns_record_message_position 0x8015896c : { *(.text.w3d_turns_record_message_position) }
  .text.w3d_turns_select_nearest_opponent 0x801589c8 : { *(.text.w3d_turns_select_nearest_opponent) }
  .text.w3d_turns_disable_movement_retain 0x80158af0 : { *(.text.w3d_turns_disable_movement_retain) }
  .text.w3d_turns_disable_movement_release 0x80158b4c : { *(.text.w3d_turns_disable_movement_release) }
  .text.w3d_turns_team_list_size 0x80158e74 : { *(.text.w3d_turns_team_list_size) }
  .text.w3d_turns_reset_global_actor_motion 0x80158fbc : { *(.text.w3d_turns_reset_global_actor_motion) }
  .text.w3d_turns_reset_actor_motion 0x80158fec : { *(.text.w3d_turns_reset_actor_motion) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; w3d_turns_804ab400 = .;
    . = 0x4ac8; w3d_cache_804afec8 = .;
    . = 0x4ae8; w3d_cache_804afee8 = .;
    . = 0x6354; w3d_global_804b1754 = .;
    . = 0x6388; w3d_scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
