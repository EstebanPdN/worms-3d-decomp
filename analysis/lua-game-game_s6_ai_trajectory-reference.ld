/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_push_scaled_trajectory_8001080c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ai_scale_trajectory_800106e0 = 0x800106e0;
w3d_auto_8000b2f8 = 0x8000b2f8;
w3d_auto_8001523c = 0x8001523c;
w3d_cached_name_lookup_80341694 = 0x80341694;
w3d_cached_name_lookup_80341808 = 0x80341808;
w3d_f32_8036a188 = 0x8036a188;
w3d_f32_8036a18c = 0x8036a18c;
w3d_f32_8036a1dc = 0x8036a1dc;
w3d_f32_8036a284 = 0x8036a284;
w3d_f32_8036a288 = 0x8036a288;
w3d_f32_8036a2b0 = 0x8036a2b0;
w3d_f32_8036a2c8 = 0x8036a2c8;
w3d_f32_8036a2e4 = 0x8036a2e4;
w3d_f32_8036a2fc = 0x8036a2fc;
w3d_f32_8036a328 = 0x8036a328;
w3d_fn_80003558 = 0x80003558;
w3d_fn_80009984 = 0x80009984;
w3d_fn_8000aa9c = 0x8000aa9c;
w3d_fn_8000af90 = 0x8000af90;
w3d_fn_8000affc = 0x8000affc;
w3d_fn_8000b4c4 = 0x8000b4c4;
w3d_fn_8000b6bc = 0x8000b6bc;
w3d_move_queue_construct = 0x80003300;
SECTIONS {
  .text.w3d_ai_push_scaled_trajectory_8001080c 0x8001080c : { *(.text.w3d_ai_push_scaled_trajectory_8001080c) }
  .text.w3d_ai_execute_trajectory_8001084c 0x8001084c : { *(.text.w3d_ai_execute_trajectory_8001084c) }
  .text.w3d_ai_reset_trajectory_time_800108b8 0x800108b8 : { *(.text.w3d_ai_reset_trajectory_time_800108b8) }
  .text.w3d_ai_score_trajectory_80010920 0x80010920 : { *(.text.w3d_ai_score_trajectory_80010920) }
  .text.w3d_ai_execute_weapon_80010f34 0x80010f34 : { *(.text.w3d_ai_execute_weapon_80010f34) }
  .text.w3d_ai_weapon_damage_80010f60 0x80010f60 : { *(.text.w3d_ai_weapon_damage_80010f60) }
  .text.w3d_ai_weapon_power_80010f9c 0x80010f9c : { *(.text.w3d_ai_weapon_power_80010f9c) }
  .text.w3d_ai_weapon_distance_80010fc4 0x80010fc4 : { *(.text.w3d_ai_weapon_distance_80010fc4) }
  .text.w3d_ai_query_sheep_80010ff8 0x80010ff8 : { *(.text.w3d_ai_query_sheep_80010ff8) }
  .text.w3d_ai_query_radius_80011058 0x80011058 : { *(.text.w3d_ai_query_radius_80011058) }
  .text.w3d_ai_query_radius_alt_800110ac 0x800110ac : { *(.text.w3d_ai_query_radius_alt_800110ac) }
  .text.w3d_ai_execute_sheep_80011344 0x80011344 : { *(.text.w3d_ai_execute_sheep_80011344) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_s6_settings_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
