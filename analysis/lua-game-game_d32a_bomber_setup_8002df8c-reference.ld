/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_bomber_setup_8002df8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
fn_802e7c30 = 0x802e7c30;
fn_802e82c0 = 0x802e82c0;
g_clip1_803f3c7c = 0x803f3c7c;
g_clip2_803f3c90 = 0x803f3c90;
g_msg_table_8040db38 = 0x8040db38;
s8_property_write_800fc43c = 0x800fc43c;
s_80372b54 = 0x80372b54;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_800fc230 = 0x800fc230;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_cached_message_id = 0x8015f5a0;
w3d_cc21b_play_named_clip_80181640 = 0x80181640;
w3d_cx12a_forward_positions_8002e59c = 0x8002e59c;
w3d_empty_80343584 = 0x80343584;
w3d_handle_member_init_kind_8012656c = 0x8012656c;
w3d_handle_set_name = 0x8015adf4;
w3d_heap_allocate = 0x802098d8;
w3d_k7a_follow_transform_8002e670 = 0x8002e670;
w3d_light_member_attach_80126610 = 0x80126610;
w3d_message_post_current = 0x8016239c;
w3d_s20_forward_global5_800e5cf0 = 0x800e5cf0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d32a_bomber_setup_8002df8c 0x8002df8c : { *(.text.w3d_d32a_bomber_setup_8002df8c) }
  .rodata 0x80372c10 : { *(.rodata) }
  .sdata 0x804aa898 (NOLOAD) : {
    . = 0x0; g_898_804aa898 = .;
    . = 0x4; g_89c_804aa89c = .;
    . = 0x8; g_8a0_804aa8a0 = .;
    . = 0xc; g_8a4_804aa8a4 = .;
    . = 0x10; g_8a8_804aa8a8 = .;
    . = 0x2478; g_id_804acd10 = .;
    . = 0x4d24; g_af5bc_804af5bc = .;
    . = 0x6ebc; g_arena_804b1754 = .;
    . = 0x6ef0; g_engine_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
