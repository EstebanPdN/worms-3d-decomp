/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_wind_dispatch_80130320)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_method_member_initialize = 0x801181bc;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_auto_80178df0 = 0x80178df0;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_80342a74 = 0x80342a74;
w3d_empty_80343584 = 0x80343584;
w3d_empty_8034380c = 0x8034380c;
w3d_f32_8039e15c = 0x8039e15c;
w3d_f32_8039e160 = 0x8039e160;
w3d_f32_8039e164 = 0x8039e164;
w3d_f32_8039e174 = 0x8039e174;
w3d_f32_8039e178 = 0x8039e178;
w3d_f32_8039e1ec = 0x8039e1ec;
w3d_f32_8039e27c = 0x8039e27c;
w3d_fn_80130638 = 0x80130638;
w3d_fn_8015f620 = 0x8015f620;
w3d_fn_80189828 = 0x80189828;
w3d_fn_802e86d4 = 0x802e86d4;
w3d_fn_802e88ac = 0x802e88ac;
w3d_mesh_instance_control_3c = 0x801817e0;
w3d_obj_8040db38 = 0x8040db38;
w3d_wind_animation_80130ed8 = 0x80130ed8;
SECTIONS {
  .text.w3d_wind_dispatch_80130320 0x80130320 : { *(.text.w3d_wind_dispatch_80130320) }
  .text.w3d_wind_update_ratio_80130d1c 0x80130d1c : { *(.text.w3d_wind_update_ratio_80130d1c) }
  .text.w3d_wind_ratio_80130dd4 0x80130dd4 : { *(.text.w3d_wind_ratio_80130dd4) }
  .text.w3d_wind_digits_80130e24 0x80130e24 : { *(.text.w3d_wind_digits_80130e24) }
  .text.w3d_wind_clear_animation_80130f78 0x80130f78 : { *(.text.w3d_wind_clear_animation_80130f78) }
  .text.w3d_wind_direction_80131520 0x80131520 : { *(.text.w3d_wind_direction_80131520) }
  .text.w3d_wind_set_visible_801315a0 0x801315a0 : { *(.text.w3d_wind_set_visible_801315a0) }
  .text.w3d_motion_message_construct_80131a84 0x80131a84 : { *(.text.w3d_motion_message_construct_80131a84) }
  .sdata 0x804af730 (NOLOAD) : {
    . = 0x0; w3d_obj_804af730 = .;
    . = 0x8; w3d_obj_804af738 = .;
    . = 0x70; w3d_obj_804af7a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
