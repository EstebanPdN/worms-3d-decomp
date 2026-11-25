/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_plan_return_zero_800063bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ai_planner_clear_800066e0 = 0x800066e0;
w3d_ai_planner_step_800064d4 = 0x800064d4;
w3d_ai_select_team_800152fc = 0x800152fc;
w3d_ai_team_active_804a84d8 = 0x804a84d8;
w3d_ai_team_alive_80015400 = 0x80015400;
w3d_ai_team_exists_800153dc = 0x800153dc;
w3d_ai_team_state_804a8518 = 0x804a8518;
w3d_ai_turn_active_800157cc = 0x800157cc;
w3d_ai_weapon_names_803eb63c = 0x803eb63c;
w3d_command_create_19_80009404 = 0x80009404;
w3d_command_create_1_80007d58 = 0x80007d58;
w3d_command_create_21_8000953c = 0x8000953c;
w3d_command_create_6_80008d84 = 0x80008d84;
w3d_f32_100_803694d0 = 0x803694d0;
w3d_f32_200_803694d4 = 0x803694d4;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_memcpy_802eee50 = 0x802eee50;
w3d_string_assign = 0x8020bd38;
w3d_vector_destroy_virtual16 = 0x80341450;
w3d_weapon_lookup_800fc330 = 0x800fc330;
w3d_world_map_refresh_8001f2cc = 0x8001f2cc;
w3d_world_map_update_8002013c = 0x8002013c;
SECTIONS {
  .text.w3d_ai_plan_return_zero_800063bc 0x800063bc : { *(.text.w3d_ai_plan_return_zero_800063bc) }
  .text.w3d_ai_plan_nop_800063c4 0x800063c4 : { *(.text.w3d_ai_plan_nop_800063c4) }
  .text.w3d_ai_plan_return_zero_800063c8 0x800063c8 : { *(.text.w3d_ai_plan_return_zero_800063c8) }
  .text.w3d_ai_planner_stop 0x800063d0 : { *(.text.w3d_ai_planner_stop) }
  .text.w3d_ai_planner_update 0x80006444 : { *(.text.w3d_ai_planner_update) }
  .text.w3d_ai_planner_destroy 0x8000666c : { *(.text.w3d_ai_planner_destroy) }
  .text.w3d_ai_planner_reset 0x80006694 : { *(.text.w3d_ai_planner_reset) }
  .text.w3d_ai_planner_set_state 0x800068a8 : { *(.text.w3d_ai_planner_set_state) }
  .text.w3d_ai_swap_plan_lists 0x80006b64 : { *(.text.w3d_ai_swap_plan_lists) }
  .text.w3d_ai_init_teams 0x80006ff4 : { *(.text.w3d_ai_init_teams) }
  .text.w3d_ai_push_plan_b 0x80007514 : { *(.text.w3d_ai_push_plan_b) }
  .text.w3d_ai_push_plan_a 0x8000753c : { *(.text.w3d_ai_push_plan_a) }
  .text.w3d_ai_plan_get_name 0x8000756c : { *(.text.w3d_ai_plan_get_name) }
  .text.w3d_ai_vector_pop 0x800075b0 : { *(.text.w3d_ai_vector_pop) }
  .text.w3d_ai_vector_push 0x800075c4 : { *(.text.w3d_ai_vector_push) }
  .text.w3d_ai_plan_skip_turn_name 0x80007758 : { *(.text.w3d_ai_plan_skip_turn_name) }
  .text.w3d_ai_plan_nop_80007760 0x80007760 : { *(.text.w3d_ai_plan_nop_80007760) }
  .text.w3d_ai_plan_return_zero_80007764 0x80007764 : { *(.text.w3d_ai_plan_return_zero_80007764) }
  .text.w3d_ai_check_skip_weapon 0x8000776c : { *(.text.w3d_ai_check_skip_weapon) }
  .text.w3d_ai_plan_skip_turn 0x80007790 : { *(.text.w3d_ai_plan_skip_turn) }
  .text.w3d_ai_plan_seed_name 0x800077e8 : { *(.text.w3d_ai_plan_seed_name) }
  .text.w3d_ai_plan_nop_800077f0 0x800077f0 : { *(.text.w3d_ai_plan_nop_800077f0) }
  .text.w3d_ai_select_team 0x80007b44 : { *(.text.w3d_ai_select_team) }
  .text.w3d_ai_begin_turn 0x80007b64 : { *(.text.w3d_ai_begin_turn) }
  .text.w3d_ai_weapon_fired 0x80007bf4 : { *(.text.w3d_ai_weapon_fired) }
  .text.w3d_ai_select_weapon 0x80007c18 : { *(.text.w3d_ai_select_weapon) }
  .text.w3d_ai_set_registry 0x80007cc4 : { *(.text.w3d_ai_set_registry) }
  .text.w3d_ai_weapon_available 0x80007ccc : { *(.text.w3d_ai_weapon_available) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; w3d_ai_plans_a_804aa558 = .;
    . = 0x4; w3d_ai_plans_b_804aa55c = .;
    . = 0xc; w3d_command_list_804aa564 = .;
    . = 0x10; w3d_ai_planner_state_804aa568 = .;
    . = 0x18; w3d_ai_planner_timer_804aa570 = .;
    . = 0x1c; w3d_ai_planner_ticks_804aa574 = .;
    . = 0x20; w3d_ai_planner_flag_804aa578 = .;
    . = 0x28; w3d_ai_turn_team_804aa580 = .;
    . = 0x2c; w3d_ai_weapon_804aa584 = .;
    . = 0x30; w3d_ai_weapon_shots_804aa588 = .;
    . = 0x34; w3d_ai_flag_804aa58c = .;
    . = 0x38; w3d_ai_weapon_ready_804aa590 = .;
    . = 0x40; w3d_ai_teams_ready_804aa598 = .;
    . = 0x4c; w3d_command_registry_804aa5a4 = .;
    . = 0x50; w3d_ai_weapon_table_804aa5a8 = .;
    . = 0x54; w3d_ai_plan_name_skip_turn_804aa5ac = .;
    . = 0x58; w3d_ai_plan_name_seed_804aa5b0 = .;
    . = 0x168; w3d_ai_team_804aa6c0 = .;
    . = 0x16c; w3d_ai_team_804aa6c4 = .;
    . = 0x170; w3d_ai_team_804aa6c8 = .;
    . = 0x174; w3d_ai_limit_804aa6cc = .;
    . = 0x178; w3d_ai_value_804aa6d0 = .;
    . = 0x188; w3d_ai_value_804aa6e0 = .;
    . = 0x18c; w3d_ai_value_804aa6e4 = .;
    . = 0x190; w3d_ai_value_804aa6e8 = .;
    . = 0x7200; w3d_world_map_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
