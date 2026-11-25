/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41g_crate_spawn_setup_80049d48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_acquire_message_80162024 = 0x80162024;
s_bounce_80376f14 = 0x80376f14;
s_disable_80376e60 = 0x80376e60;
s_drop_80376ebc = 0x80376ebc;
s_expl_80376efc = 0x80376efc;
s_file_80376e48 = 0x80376e48;
s_gravity_80376e90 = 0x80376e90;
s_low_80376e98 = 0x80376e98;
s_rand_80376ee4 = 0x80376ee4;
s_show_80376ed4 = 0x80376ed4;
s_spawn_80376e3c = 0x80376e3c;
s_spawnname_80376e78 = 0x80376e78;
s_type_80376e84 = 0x80376e84;
s_water_80376eb0 = 0x80376eb0;
tsonnet_b33_arena_801613f0 = 0x801613f0;
type_a_80361860 = 0x80361860;
type_b_803618f0 = 0x803618f0;
w3d_actor_handle_member_set_slot_word = 0x801262e4;
w3d_actor_handle_member_set_word = 0x8012632c;
w3d_assert_80022e20 = 0x80022e20;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_800fc230 = 0x800fc230;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_800fc2f0 = 0x800fc2f0;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_created_message_init_800c1620 = 0x800c1620;
w3d_d28g_spawner_pick_clear_spot_8004a408 = 0x8004a408;
w3d_empty_80342a74 = 0x80342a74;
w3d_find_spawn_point_8004a608 = 0x8004a608;
w3d_fn_8004a7f4 = 0x8004a7f4;
w3d_handle_member_query_8012629c = 0x8012629c;
w3d_handle_member_query_801262c0 = 0x801262c0;
w3d_handle_member_query_80126308 = 0x80126308;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.d41g_crate_spawn_setup_80049d48 0x80049d48 : { *(.text.d41g_crate_spawn_setup_80049d48) }
  .sdata 0x804ad370 (NOLOAD) : {
    . = 0x0; m7_804ad370 = .;
    . = 0x18; m0_804ad388 = .;
    . = 0x20; m1_804ad390 = .;
    . = 0x38; m2_804ad3a8 = .;
    . = 0x50; m3_804ad3c0 = .;
    . = 0x60; m4_804ad3d0 = .;
    . = 0x68; m5_804ad3d8 = .;
    . = 0x70; m6_804ad3e0 = .;
    . = 0x78; m8_804ad3e8 = .;
    . = 0x43e4; arena_804b1754 = .;
    . = 0x4418; engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
