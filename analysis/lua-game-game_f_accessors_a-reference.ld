/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_owner_slot_assign_800609ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_component_refresh_80064c6c = 0x80064c6c;
w3d_component_step_80066068 = 0x80066068;
w3d_component_step_800ed090 = 0x800ed090;
w3d_empty_80343580 = 0x80343580;
w3d_engine_get_context = 0x80165254;
w3d_lazy_state_prepare_8015fd1c = 0x8015fd1c;
w3d_owned_release_800e5bb8 = 0x800e5bb8;
w3d_pause_prepare_800fde38 = 0x800fde38;
w3d_resource_set_mode_8018c5b0 = 0x8018c5b0;
w3d_session_attach_800c70e4 = 0x800c70e4;
w3d_session_current_800c8120 = 0x800c8120;
w3d_session_set_paused_800c7cd0 = 0x800c7cd0;
w3d_slot_table_8042e700 = 0x8042e700;
w3d_timed_state_apply_800642ac = 0x800642ac;
w3d_value_range_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_owner_slot_assign_800609ec 0x800609ec : { *(.text.w3d_owner_slot_assign_800609ec) }
  .text.w3d_component_step_80061684 0x80061684 : { *(.text.w3d_component_step_80061684) }
  .text.w3d_lazy_state_ensure_80062614 0x80062614 : { *(.text.w3d_lazy_state_ensure_80062614) }
  .text.w3d_component_refresh_800639e8 0x800639e8 : { *(.text.w3d_component_refresh_800639e8) }
  .text.w3d_timed_state_set_mode_80064190 0x80064190 : { *(.text.w3d_timed_state_set_mode_80064190) }
  .text.w3d_timed_state_resource_mode_80064274 0x80064274 : { *(.text.w3d_timed_state_resource_mode_80064274) }
  .text.w3d_timed_state_set_rate_80064548 0x80064548 : { *(.text.w3d_timed_state_set_rate_80064548) }
  .text.w3d_component_step_80065ff0 0x80065ff0 : { *(.text.w3d_component_step_80065ff0) }
  .text.w3d_timed_state_stamp_800664c4 0x800664c4 : { *(.text.w3d_timed_state_stamp_800664c4) }
  .text.w3d_motion_get_position_80066894 0x80066894 : { *(.text.w3d_motion_get_position_80066894) }
  .text.w3d_motion_get_velocity_800668b8 0x800668b8 : { *(.text.w3d_motion_get_velocity_800668b8) }
  .text.w3d_motion_get_30_800668dc 0x800668dc : { *(.text.w3d_motion_get_30_800668dc) }
  .text.w3d_motion_get_28_800668e4 0x800668e4 : { *(.text.w3d_motion_get_28_800668e4) }
  .text.w3d_motion_get_2c_800668ec 0x800668ec : { *(.text.w3d_motion_get_2c_800668ec) }
  .text.w3d_motion_get_20_800668f4 0x800668f4 : { *(.text.w3d_motion_get_20_800668f4) }
  .text.w3d_motion_get_24_800668fc 0x800668fc : { *(.text.w3d_motion_get_24_800668fc) }
  .text.w3d_placement_set_target_80067268 0x80067268 : { *(.text.w3d_placement_set_target_80067268) }
  .text.w3d_placement_set_offset_80067288 0x80067288 : { *(.text.w3d_placement_set_offset_80067288) }
  .text.w3d_placement_target_800672a8 0x800672a8 : { *(.text.w3d_placement_target_800672a8) }
  .text.w3d_placement_offset_800672b0 0x800672b0 : { *(.text.w3d_placement_offset_800672b0) }
  .text.w3d_placement_extra_800672b8 0x800672b8 : { *(.text.w3d_placement_extra_800672b8) }
  .text.w3d_empty_800672c0 0x800672c0 : { *(.text.w3d_empty_800672c0) }
  .text.w3d_stamp_pair_capture_80067510 0x80067510 : { *(.text.w3d_stamp_pair_capture_80067510) }
  .text.w3d_return_minus_one_800681cc 0x800681cc : { *(.text.w3d_return_minus_one_800681cc) }
  .text.w3d_empty_8006823c 0x8006823c : { *(.text.w3d_empty_8006823c) }
  .text.w3d_value_range_low_80069a28 0x80069a28 : { *(.text.w3d_value_range_low_80069a28) }
  .text.w3d_value_range_init_80069a30 0x80069a30 : { *(.text.w3d_value_range_init_80069a30) }
  .text.w3d_value_range_get_80069a50 0x80069a50 : { *(.text.w3d_value_range_get_80069a50) }
  .text.w3d_session_attach_80069be0 0x80069be0 : { *(.text.w3d_session_attach_80069be0) }
  .text.w3d_session_pause_80069c14 0x80069c14 : { *(.text.w3d_session_pause_80069c14) }
  .text.w3d_session_resume_80069c54 0x80069c54 : { *(.text.w3d_session_resume_80069c54) }
  .text.w3d_slot_table_get_8006bcd0 0x8006bcd0 : { *(.text.w3d_slot_table_get_8006bcd0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_game_context_804b1788 = .;
    . = 0x20; w3d_stamp_b_804b17a8 = .;
    . = 0x24; w3d_stamp_a_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
