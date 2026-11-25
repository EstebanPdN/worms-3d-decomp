/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_collision_state_is_contact)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178d1c = 0x80178d1c;
w3d_auto_80178df0 = 0x80178df0;
w3d_constructor_native_cast = 0x80342a78;
w3d_empty_803426b4 = 0x803426b4;
w3d_f32_803a13a8 = 0x803a13a8;
w3d_f32_803a1498 = 0x803a1498;
w3d_f32_803a149c = 0x803a149c;
w3d_f32_803a1518 = 0x803a1518;
w3d_fn_800c2494 = 0x800c2494;
w3d_fn_800fc270 = 0x800fc270;
w3d_fn_800fc710 = 0x800fc710;
w3d_fn_8014b8ec = 0x8014b8ec;
w3d_fn_8014ca54 = 0x8014ca54;
w3d_fn_80178474 = 0x80178474;
w3d_fn_802e82c0 = 0x802e82c0;
w3d_str_803a1214 = 0x803a1214;
w3d_vector_8043ae20 = 0x8043ae20;
SECTIONS {
  .text.w3d_collision_state_is_contact 0x801418c4 : { *(.text.w3d_collision_state_is_contact) }
  .text.w3d_motion_get_direction 0x80146f10 : { *(.text.w3d_motion_get_direction) }
  .text.w3d_motion_refresh_velocity 0x80146f34 : { *(.text.w3d_motion_refresh_velocity) }
  .text.w3d_motion_set_actor_value 0x801492ec : { *(.text.w3d_motion_set_actor_value) }
  .text.w3d_motion_has_combined_flags 0x8014b3b4 : { *(.text.w3d_motion_has_combined_flags) }
  .text.w3d_motion_apply_velocity_constraint 0x8014b40c : { *(.text.w3d_motion_apply_velocity_constraint) }
  .text.w3d_motion_get_input_direction 0x8014c260 : { *(.text.w3d_motion_get_input_direction) }
  .text.w3d_motion_owner_matches 0x8014c488 : { *(.text.w3d_motion_owner_matches) }
  .text.w3d_motion_get_contact_point 0x8014c4cc : { *(.text.w3d_motion_get_contact_point) }
  .text.w3d_motion_slope_allowed 0x8014c7fc : { *(.text.w3d_motion_slope_allowed) }
  .rodata 0x803a1494 : { *(.rodata) }
  .sdata 0x804afdf0 (NOLOAD) : {
    . = 0x0; w3d_global_804afdf0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
