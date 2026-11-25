/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_clone_and_enqueue_8000c078)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ai_push_plan_a = 0x8000753c;
w3d_ai_select_weapon = 0x80007c18;
w3d_cached_name_lookup_80341694 = 0x80341694;
w3d_cached_name_lookup_80341710 = 0x80341710;
w3d_command_create_7 = 0x80008c44;
w3d_f32_80369d10 = 0x80369d10;
w3d_f32_80369d28 = 0x80369d28;
w3d_f32_80369d44 = 0x80369d44;
w3d_f32_80369dec = 0x80369dec;
w3d_f32_80369df0 = 0x80369df0;
w3d_f32_80369e3c = 0x80369e3c;
w3d_fn_8000a6ec = 0x8000a6ec;
w3d_fn_8000a758 = 0x8000a758;
w3d_fn_8000af90 = 0x8000af90;
w3d_fn_8000affc = 0x8000affc;
w3d_fn_8000b6bc = 0x8000b6bc;
w3d_fn_800157cc = 0x800157cc;
w3d_fn_8001b734 = 0x8001b734;
w3d_move_queue_release = 0x800033d8;
SECTIONS {
  .text.w3d_ai_clone_and_enqueue_8000c078 0x8000c078 : { *(.text.w3d_ai_clone_and_enqueue_8000c078) }
  .text.w3d_ai_weapon_damage_8000ce84 0x8000ce84 : { *(.text.w3d_ai_weapon_damage_8000ce84) }
  .text.w3d_ai_weapon_radius_8000cec0 0x8000cec0 : { *(.text.w3d_ai_weapon_radius_8000cec0) }
  .text.w3d_ai_weapon_range_8000cee8 0x8000cee8 : { *(.text.w3d_ai_weapon_range_8000cee8) }
  .text.w3d_ai_test_range_a_8000d068 0x8000d068 : { *(.text.w3d_ai_test_range_a_8000d068) }
  .text.w3d_ai_test_range_b_8000d0b4 0x8000d0b4 : { *(.text.w3d_ai_test_range_b_8000d0b4) }
  .text.w3d_ai_test_range_c_8000d120 0x8000d120 : { *(.text.w3d_ai_test_range_c_8000d120) }
  .text.w3d_ai_test_raised_origin_8000d1dc 0x8000d1dc : { *(.text.w3d_ai_test_raised_origin_8000d1dc) }
  .text.w3d_ai_test_range_d_8000d2c8 0x8000d2c8 : { *(.text.w3d_ai_test_range_d_8000d2c8) }
  .text.w3d_ai_test_range_e_8000d328 0x8000d328 : { *(.text.w3d_ai_test_range_e_8000d328) }
  .text.w3d_ai_named_damage_8000d99c 0x8000d99c : { *(.text.w3d_ai_named_damage_8000d99c) }
  .text.w3d_ai_named_range_8000da0c 0x8000da0c : { *(.text.w3d_ai_named_range_8000da0c) }
  .text.w3d_ai_named_scaled_count_8000da34 0x8000da34 : { *(.text.w3d_ai_named_scaled_count_8000da34) }
  .text.w3d_ai_execute_named_attack_8000dbd4 0x8000dbd4 : { *(.text.w3d_ai_execute_named_attack_8000dbd4) }
  .text.w3d_ai_execute_fixed_a_8000dc78 0x8000dc78 : { *(.text.w3d_ai_execute_fixed_a_8000dc78) }
  .text.w3d_ai_execute_fixed_b_8000dcbc 0x8000dcbc : { *(.text.w3d_ai_execute_fixed_b_8000dcbc) }
  .rodata 0x80369e88 : { *(.rodata) }
  .sdata 0x804aa588 (NOLOAD) : {
    . = 0x0; w3d_ai_mode_804aa588 = .;
    . = 0x150; w3d_ai_tuning_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
