/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_weapon_drop_fire_8002f3d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f10b_crate_defaults_8008a044 = 0x8008a044;
fn_80164514 = 0x80164514;
g_fixed_8045e788 = 0x8045e788;
g_key_8040fd78 = 0x8040fd78;
g_msg_table_8040db38 = 0x8040db38;
s8_property_read_800fc550 = 0x800fc550;
s8_property_read_800fc5dc = 0x800fc5dc;
s8_property_write_800fc3b0 = 0x800fc3b0;
s_80372e98 = 0x80372e98;
s_80372eb0 = 0x80372eb0;
s_80372ec8 = 0x80372ec8;
s_80372edc = 0x80372edc;
s_80372ee8 = 0x80372ee8;
s_80372ef0 = 0x80372ef0;
s_80372f00 = 0x80372f00;
s_80372f18 = 0x80372f18;
strcmp = 0x802ef234;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_assign_interface_arg_800eb65c = 0x800eb65c;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_copy12_800eb8d0 = 0x800eb8d0;
w3d_copy12_800eb8f0 = 0x800eb8f0;
w3d_cx9a_service_result_append_80089eec = 0x80089eec;
w3d_empty_80341584 = 0x80341584;
w3d_message_post_current = 0x8016239c;
w3d_s10_service_forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.w3d_d30a_weapon_drop_fire_8002f3d4 0x8002f3d4 : { *(.text.w3d_d30a_weapon_drop_fire_8002f3d4) }
  .rodata 0x80372f30 : { *(.rodata) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; g_team_804aab4c = .;
    . = 0x21f8; g_msg_804acd44 = .;
    . = 0x6c08; g_arena_804b1754 = .;
    . = 0x6c40; g_hub_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
