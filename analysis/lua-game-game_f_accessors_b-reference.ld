/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_component_step_8006bdf4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_bonus_table_80431db8 = 0x80431db8;
w3d_component_step_8006bce4 = 0x8006bce4;
w3d_handles_enable_8006eebc = 0x8006eebc;
w3d_player_list_refresh_8008a30c = 0x8008a30c;
w3d_score_value_800a830c = 0x800a830c;
w3d_selection_apply_8008f1e8 = 0x8008f1e8;
w3d_timer_set_80178d28 = 0x80178d28;
w3d_timer_state_80178d1c = 0x80178d1c;
SECTIONS {
  .text.w3d_component_step_8006bdf4 0x8006bdf4 : { *(.text.w3d_component_step_8006bdf4) }
  .text.w3d_component_step_second_8006be14 0x8006be14 : { *(.text.w3d_component_step_second_8006be14) }
  .text.w3d_handles_match_8006e10c 0x8006e10c : { *(.text.w3d_handles_match_8006e10c) }
  .text.w3d_round_value_reset_8006e6f4 0x8006e6f4 : { *(.text.w3d_round_value_reset_8006e6f4) }
  .text.w3d_scene_timer_is_one_8006e71c 0x8006e71c : { *(.text.w3d_scene_timer_is_one_8006e71c) }
  .text.w3d_scene_timer_set_8006e750 0x8006e750 : { *(.text.w3d_scene_timer_set_8006e750) }
  .text.w3d_handles_set_enabled_8006ee88 0x8006ee88 : { *(.text.w3d_handles_set_enabled_8006ee88) }
  .text.w3d_empty_80070708 0x80070708 : { *(.text.w3d_empty_80070708) }
  .text.w3d_player_list_roster_80071e28 0x80071e28 : { *(.text.w3d_player_list_roster_80071e28) }
  .text.w3d_return_minus_one_80072fdc 0x80072fdc : { *(.text.w3d_return_minus_one_80072fdc) }
  .text.w3d_empty_8007304c 0x8007304c : { *(.text.w3d_empty_8007304c) }
  .text.w3d_empty_80086630 0x80086630 : { *(.text.w3d_empty_80086630) }
  .text.w3d_empty_80088f24 0x80088f24 : { *(.text.w3d_empty_80088f24) }
  .text.w3d_player_list_team_count_8008c34c 0x8008c34c : { *(.text.w3d_player_list_team_count_8008c34c) }
  .text.w3d_player_list_worm_count_8008c440 0x8008c440 : { *(.text.w3d_player_list_worm_count_8008c440) }
  .text.w3d_player_list_weapon_count_8008c534 0x8008c534 : { *(.text.w3d_player_list_weapon_count_8008c534) }
  .text.w3d_player_list_refresh_8008cf14 0x8008cf14 : { *(.text.w3d_player_list_refresh_8008cf14) }
  .text.w3d_bonus_table_total_8008da54 0x8008da54 : { *(.text.w3d_bonus_table_total_8008da54) }
  .text.w3d_player_list_timer_active_8008dd18 0x8008dd18 : { *(.text.w3d_player_list_timer_active_8008dd18) }
  .text.w3d_player_list_selection_8008dd4c 0x8008dd4c : { *(.text.w3d_player_list_selection_8008dd4c) }
  .text.w3d_player_list_add_score_a_8008e0cc 0x8008e0cc : { *(.text.w3d_player_list_add_score_a_8008e0cc) }
  .text.w3d_player_list_add_score_b_8008e108 0x8008e108 : { *(.text.w3d_player_list_add_score_b_8008e108) }
  .text.w3d_selection_set_8008ed18 0x8008ed18 : { *(.text.w3d_selection_set_8008ed18) }
  .text.w3d_record_owner_records_80090d7c 0x80090d7c : { *(.text.w3d_record_owner_records_80090d7c) }
  .text.w3d_record_owner_set_mode_800919cc 0x800919cc : { *(.text.w3d_record_owner_set_mode_800919cc) }
  .text.w3d_pose_owner_set_pose_8009278c 0x8009278c : { *(.text.w3d_pose_owner_set_pose_8009278c) }
  .text.w3d_empty_80093294 0x80093294 : { *(.text.w3d_empty_80093294) }
  .text.w3d_empty_80095644 0x80095644 : { *(.text.w3d_empty_80095644) }
  .text.w3d_empty_800959cc 0x800959cc : { *(.text.w3d_empty_800959cc) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; w3d_scene_state_804aaabc = .;
    . = 0x9c; w3d_selected_id_804aab58 = .;
    . = 0xac; w3d_selection_target_804aab68 = .;
    . = 0x10a4; w3d_round_value_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
