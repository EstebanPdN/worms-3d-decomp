/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_crate_spawn_announce_800492cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_a_80376764 = 0x80376764;
g_b_80376774 = 0x80376774;
g_msg_table_8040db38 = 0x8040db38;
s8_index_query_800fc6dc = 0x800fc6dc;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_cached_message_id = 0x8015f5a0;
w3d_d24h_pool_add_800c53a0 = 0x800c53a0;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_s20_forward_global_800e5ca4 = 0x800e5ca4;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_d30a_crate_spawn_announce_800492cc 0x800492cc : { *(.text.w3d_d30a_crate_spawn_announce_800492cc) }
  .rodata 0x80376780 : { *(.rodata) }
  .sdata 0x804ad2e0 (NOLOAD) : {
    . = 0x0; g_target_804ad2e0 = .;
    . = 0x18; g_health_804ad2f8 = .;
    . = 0x20; g_weapon_804ad300 = .;
    . = 0x28; g_utility_804ad308 = .;
    . = 0x4474; g_arena_804b1754 = .;
    . = 0x44a8; g_engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
