/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_projectile_tick_800d5c68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_handle_member_set_bounds = 0x80126278;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_effect_800e5ca4 = 0x800e5ca4;
w3d_f32_80388e4c = 0x80388e4c;
w3d_f32_80388e50 = 0x80388e50;
w3d_f32_80388e54 = 0x80388e54;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_owner_slot_message_8003a264 = 0x8003a264;
w3d_projectile_activate_800d65ec = 0x800d65ec;
w3d_projectile_bounce_800d6350 = 0x800d6350;
w3d_projectile_move_800d610c = 0x800d610c;
w3d_scene_timer_is_one_8006e71c = 0x8006e71c;
w3d_str_80388f68 = 0x80388f68;
w3d_trace_800b0824 = 0x800b0824;
w3d_trace_position_8043ae20 = 0x8043ae20;
w3d_zero_vector_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_projectile_tick_800d5c68 0x800d5c68 : { *(.text.w3d_projectile_tick_800d5c68) }
  .text.w3d_projectile_place_ground_800d5ff0 0x800d5ff0 : { *(.text.w3d_projectile_place_ground_800d5ff0) }
  .text.w3d_projectile_update_bounds_800d60ac 0x800d60ac : { *(.text.w3d_projectile_update_bounds_800d60ac) }
  .text.w3d_projectile_effect_800d673c 0x800d673c : { *(.text.w3d_projectile_effect_800d673c) }
  .text.w3d_projectile_post_owner_slot_800d6788 0x800d6788 : { *(.text.w3d_projectile_post_owner_slot_800d6788) }
  .rodata 0x80388f7c : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_message_pool_804b1754 = .;
    . = 0x4c; w3d_event_state_804b17a0 = .;
    . = 0x54; w3d_trace_slot_804b17a8 = .;
    . = 0x58; w3d_trace_owner_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
