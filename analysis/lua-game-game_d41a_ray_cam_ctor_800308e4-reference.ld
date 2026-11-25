/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41a_ray_cam_ctor_800308e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16d24d_WaterTargetPCci = 0x8015a0d4;
fn_80343748 = 0x80343748;
t_8040e588 = 0x8040e588;
terra_only_a11_camera_80036218 = 0x80036218;
w3d_actor_handle_member_initialize = 0x80126184;
w3d_actor_handle_member_set_slot_word = 0x801262e4;
w3d_actor_handle_member_set_word = 0x8012632c;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_constructor_native_cast = 0x80342a78;
w3d_ctor_801628b0 = 0x801628b0;
w3d_empty_80342a74 = 0x80342a74;
w3d_empty_80342fa4 = 0x80342fa4;
w3d_handle_member_query_8012629c = 0x8012629c;
w3d_spectator_message_801081dc = 0x801081dc;
SECTIONS {
  .text.w3d_d41a_ray_cam_ctor_800308e4 0x800308e4 : { *(.text.w3d_d41a_ray_cam_ctor_800308e4) }
  .rodata 0x80373168 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; g_self_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
