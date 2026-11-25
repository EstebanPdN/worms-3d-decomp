/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33a_bomber_start_8002ead8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80022e20 = 0x80022e20;
d24d_acquire_message_80162024 = 0x80162024;
fn_802e82c0 = 0x802e82c0;
g_clip1_803f3c7c = 0x803f3c7c;
g_clip2_803f3c90 = 0x803f3c90;
g_msg_table_8040db38 = 0x8040db38;
s8_property_read_800fc5dc = 0x800fc5dc;
s8_property_write_800fc43c = 0x800fc43c;
s_80372cec = 0x80372cec;
t_80361860 = 0x80361860;
t_803618f0 = 0x803618f0;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800361f8 = 0x800361f8;
w3d_auto_800fc230 = 0x800fc230;
w3d_auto_800fc270 = 0x800fc270;
w3d_auto_800fc2f0 = 0x800fc2f0;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_created_message_init_800c1620 = 0x800c1620;
w3d_d20a_bomber_position_8002f098 = 0x8002f098;
w3d_d24h_pool_add_800c53a0 = 0x800c53a0;
w3d_empty_80341584 = 0x80341584;
w3d_engine_get_context = 0x80165254;
w3d_k7a_clip_frames_8002f764 = 0x8002f764;
w3d_message_post_current = 0x8016239c;
w3d_s20_forward_global4_800fdd80 = 0x800fdd80;
SECTIONS {
  .text.w3d_d33a_bomber_start_8002ead8 0x8002ead8 : { *(.text.w3d_d33a_bomber_start_8002ead8) }
  .rodata 0x80372d00 : { *(.rodata) }
  .sdata 0x804acd2c (NOLOAD) : {
    . = 0x0; g_b_804acd2c = .;
    . = 0x8; g_a_804acd34 = .;
    . = 0x10; g_c_804acd3c = .;
    . = 0x4a28; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
