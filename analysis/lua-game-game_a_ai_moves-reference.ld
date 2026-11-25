/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_move_queue_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_engine_get_context = 0x80165254;
w3d_handle_storage_release = 0x802134fc;
w3d_memmove_802eee50 = 0x802eee50;
w3d_message_post_current = 0x8016239c;
w3d_message_prepare_801613f0 = 0x801613f0;
w3d_message_target_80131a84 = 0x80131a84;
w3d_move_default_8045e788 = 0x8045e788;
w3d_move_queue_vtable_8040cad0 = 0x8040cad0;
w3d_move_step_apply_8001e224 = 0x8001e224;
w3d_object_base_destroy_80021468 = 0x80021468;
w3d_operator_delete_80015264 = 0x80015264;
w3d_str_move_backflip_80368e3c = 0x80368e3c;
w3d_str_move_delay_80368ea8 = 0x80368ea8;
w3d_str_move_jetpack_80368e6c = 0x80368e6c;
w3d_str_move_jump_forward_80368e2c = 0x80368e2c;
w3d_str_move_jump_up_80368e4c = 0x80368e4c;
w3d_str_move_jump_up_no_aftertouch_80368e54 = 0x80368e54;
w3d_str_move_keep_trying_80368e08 = 0x80368e08;
w3d_str_move_ninja_rope_80368e90 = 0x80368e90;
w3d_str_move_parachute_80368e84 = 0x80368e84;
w3d_str_move_parachute_start_80368e74 = 0x80368e74;
w3d_str_move_rethink_80368db0 = 0x80368db0;
w3d_str_move_skip_80368de0 = 0x80368de0;
w3d_str_move_super_sheep_80368e9c = 0x80368e9c;
w3d_str_move_unknown_80368eb0 = 0x80368eb0;
w3d_vector_clear_8034134c = 0x8034134c;
SECTIONS {
  .text.w3d_move_queue_construct 0x80003300 : { *(.text.w3d_move_queue_construct) }
  .text.w3d_move_queue_destroy 0x80003370 : { *(.text.w3d_move_queue_destroy) }
  .text.w3d_move_queue_release 0x800033d8 : { *(.text.w3d_move_queue_release) }
  .text.w3d_move_queue_reset_800039ac 0x800039ac : { *(.text.w3d_move_queue_reset_800039ac) }
  .text.w3d_move_queue_current_step 0x80003e78 : { *(.text.w3d_move_queue_current_step) }
  .text.w3d_move_queue_pop_front 0x80003ea0 : { *(.text.w3d_move_queue_pop_front) }
  .text.w3d_move_queue_advance 0x80003f58 : { *(.text.w3d_move_queue_advance) }
  .text.w3d_move_queue_check_timeout 0x80003fd4 : { *(.text.w3d_move_queue_check_timeout) }
  .text.w3d_move_type_name 0x80004038 : { *(.text.w3d_move_type_name) }
  .text.w3d_move_queue_start_wait 0x8000415c : { *(.text.w3d_move_queue_start_wait) }
  .text.w3d_move_step_apply 0x8000419c : { *(.text.w3d_move_step_apply) }
  .sdata 0x804ac824 (NOLOAD) : {
    . = 0x0; w3d_move_type_name_804ac824 = .;
    . = 0x4f28; w3d_move_wait_start_804b174c = .;
    . = 0x4f2c; w3d_move_wait_length_804b1750 = .;
    . = 0x4f30; w3d_message_queue_804b1754 = .;
    . = 0x4f34; w3d_move_cursor_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
