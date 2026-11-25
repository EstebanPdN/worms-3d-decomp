/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_score_area_attack_8000dd04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8000b2f8 = 0x8000b2f8;
w3d_cached_name_lookup_80341694 = 0x80341694;
w3d_cached_name_lookup_8034178c = 0x8034178c;
w3d_f32_80369f14 = 0x80369f14;
w3d_f32_80369f18 = 0x80369f18;
w3d_f32_8036a054 = 0x8036a054;
w3d_f32_8036a0c0 = 0x8036a0c0;
w3d_f32_8036a0c4 = 0x8036a0c4;
w3d_f32_8036a0c8 = 0x8036a0c8;
w3d_f32_8036a128 = 0x8036a128;
w3d_f32_8036a144 = 0x8036a144;
w3d_fn_8000a280 = 0x8000a280;
w3d_fn_8000af90 = 0x8000af90;
w3d_fn_8000affc = 0x8000affc;
w3d_fn_8000b344 = 0x8000b344;
w3d_fn_8000b4c4 = 0x8000b4c4;
w3d_fn_8000b6bc = 0x8000b6bc;
w3d_fn_8000b7dc = 0x8000b7dc;
w3d_fn_8000f804 = 0x8000f804;
SECTIONS {
  .text.w3d_ai_score_area_attack_8000dd04 0x8000dd04 : { *(.text.w3d_ai_score_area_attack_8000dd04) }
  .text.w3d_ai_bomber_damage_8000e058 0x8000e058 : { *(.text.w3d_ai_bomber_damage_8000e058) }
  .text.w3d_ai_bomber_radius_8000e094 0x8000e094 : { *(.text.w3d_ai_bomber_radius_8000e094) }
  .text.w3d_ai_bomber_range_8000e0bc 0x8000e0bc : { *(.text.w3d_ai_bomber_range_8000e0bc) }
  .text.w3d_ai_score_weapon_base_8000eb64 0x8000eb64 : { *(.text.w3d_ai_score_weapon_base_8000eb64) }
  .text.w3d_ai_projectile_damage_800102fc 0x800102fc : { *(.text.w3d_ai_projectile_damage_800102fc) }
  .text.w3d_ai_score_projectile_80010338 0x80010338 : { *(.text.w3d_ai_score_projectile_80010338) }
  .text.w3d_ai_test_projectile_a_800103d4 0x800103d4 : { *(.text.w3d_ai_test_projectile_a_800103d4) }
  .text.w3d_ai_execute_projectile_80010414 0x80010414 : { *(.text.w3d_ai_execute_projectile_80010414) }
  .text.w3d_ai_test_projectile_b_80010538 0x80010538 : { *(.text.w3d_ai_test_projectile_b_80010538) }
  .text.w3d_ai_test_projectile_c_80010584 0x80010584 : { *(.text.w3d_ai_test_projectile_c_80010584) }
  .text.w3d_ai_splash_damage_800105cc 0x800105cc : { *(.text.w3d_ai_splash_damage_800105cc) }
  .text.w3d_ai_splash_radius_80010608 0x80010608 : { *(.text.w3d_ai_splash_radius_80010608) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_ai_tuning_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
