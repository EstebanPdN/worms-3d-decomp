/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_mine_like_update_80048840)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800492cc = 0x800492cc;
g_clip_name_803766bc = 0x803766bc;
s19_handle_not_minus1_80049298 = 0x80049298;
w3d_cc21b_play_named_clip_80181640 = 0x80181640;
w3d_empty_80343584 = 0x80343584;
w3d_fn_80049108 = 0x80049108;
w3d_fn_80049180 = 0x80049180;
w3d_handle_member_destroy_801265a4 = 0x801265a4;
w3d_handle_member_query_801265ec = 0x801265ec;
w3d_mesh_instance_control_3c = 0x801817e0;
w3d_mesh_instance_is_playing = 0x80181ccc;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_d30a_mine_like_update_80048840 0x80048840 : { *(.text.w3d_d30a_mine_like_update_80048840) }
  .rodata 0x803766c4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
