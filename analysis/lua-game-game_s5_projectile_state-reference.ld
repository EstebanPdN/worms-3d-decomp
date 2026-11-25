/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_projectile_init_800d58ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_actor_base_initialize = 0x80161014;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_actor_handle_member_initialize = 0x80126184;
w3d_actor_handle_member_set_bounds = 0x80126278;
w3d_actor_handle_member_set_slot_word = 0x801262e4;
w3d_actor_handle_member_set_word = 0x8012632c;
w3d_f32_80388e18 = 0x80388e18;
w3d_projectile_vtable_8040fd08 = 0x8040fd08;
w3d_zero_vector_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_projectile_init_800d58ec 0x800d58ec : { *(.text.w3d_projectile_init_800d58ec) }
  .text.w3d_projectile_destroy_800d5a14 0x800d5a14 : { *(.text.w3d_projectile_destroy_800d5a14) }
  .rodata 0x80388e1c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
