/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29b_gun_fire_8009c87c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_nearest_sphere_801263fc = 0x801263fc;
effect_800e5ca4 = 0x800e5ca4;
lbl_803800e8 = 0x803800e8;
lbl_80380214 = 0x80380214;
lbl_8040db38 = 0x8040db38;
lbl_804364d0 = 0x804364d0;
lbl_8043ae20 = 0x8043ae20;
sqrt_802e82c0 = 0x802e82c0;
trace_800b0824 = 0x800b0824;
w3d_active_8003f240 = 0x8003f240;
w3d_active_actor_80156f88 = 0x80156f88;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_auto_80178df0 = 0x80178df0;
w3d_bind_effect_8009d6d4 = 0x8009d6d4;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_damage_8004ee4c = 0x8004ee4c;
w3d_empty_80342a74 = 0x80342a74;
w3d_euler_801a3eb0 = 0x801a3eb0;
w3d_explosion_800666b4 = 0x800666b4;
w3d_forward_800fdc80 = 0x800fdc80;
w3d_land_damage_add_8009d430 = 0x8009d430;
w3d_lookup_80164fc8 = 0x80164fc8;
w3d_message_int_init_800a82f0 = 0x800a82f0;
w3d_message_post_8016239c = 0x8016239c;
w3d_query_801262c0 = 0x801262c0;
w3d_random_80162bc8 = 0x80162bc8;
w3d_read_float_800fc270 = 0x800fc270;
w3d_read_vec_800fc2f0 = 0x800fc2f0;
w3d_water_800419cc = 0x800419cc;
w3d_worm_800fc6dc = 0x800fc6dc;
w3d_write_int_800fc43c = 0x800fc43c;
SECTIONS {
  .text.w3d_d29b_gun_fire_8009c87c 0x8009c87c : { *(.text.w3d_d29b_gun_fire_8009c87c) }
  .rodata 0x80380250 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; lbl_804aa95e = .;
    . = 0xaa2; lbl_804ab400 = .;
    . = 0x367a; lbl_804adfd8 = .;
    . = 0x36d2; lbl_804ae030 = .;
    . = 0x3742; lbl_804ae0a0 = .;
    . = 0x6df6; lbl_804b1754 = .;
    . = 0x6e06; lbl_804b1764 = .;
    . = 0x6e32; lbl_804b1790 = .;
    . = 0x6e46; lbl_804b17a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
