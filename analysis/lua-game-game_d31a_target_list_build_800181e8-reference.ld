/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31a_target_list_build_800181e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
fn_8001977c = 0x8001977c;
g_centre_8041d3a0 = 0x8041d3a0;
k_zero_8036a8bc = 0x8036a8bc;
memcpy_802eee50 = 0x802eee50;
s19_check_pair_80015434 = 0x80015434;
s_empty_8036a87c = 0x8036a87c;
s_enemy_8036a8a8 = 0x8036a8a8;
s_friendly_8036a89c = 0x8036a89c;
s_quote2_8036a8b8 = 0x8036a8b8;
s_quote_8036a898 = 0x8036a898;
s_target_8036a880 = 0x8036a880;
s_worm_8036a8b0 = 0x8036a8b0;
strcmp = 0x802ef234;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_auto_8001523c = 0x8001523c;
w3d_auto_80015264 = 0x80015264;
w3d_auto_800153dc = 0x800153dc;
w3d_auto_80015564 = 0x80015564;
w3d_auto_80015588 = 0x80015588;
w3d_auto_800155ac = 0x800155ac;
w3d_auto_80018be0 = 0x80018be0;
w3d_d27a_entry_weight_pass_80018ce0 = 0x80018ce0;
w3d_d27a_plan_score_update_80017f0c = 0x80017f0c;
w3d_d30a_collect_named_80015960 = 0x80015960;
w3d_f2a_update_water_80018ed0 = 0x80018ed0;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_string_append = 0x8020bf2c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d31a_target_list_build_800181e8 0x800181e8 : { *(.text.w3d_d31a_target_list_build_800181e8) }
  .rodata 0x8036a8c0 : { *(.rodata) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; g_self_804aa6c0 = .;
    . = 0x18; w3d_game_804aa6d8 = .;
    . = 0x28; g_self_index_804aa6e8 = .;
    . = 0x90; g_blasts_804aa750 = .;
    . = 0xa4; g_blast_scale_804aa764 = .;
    . = 0xa8; g_busy_804aa768 = .;
    . = 0xac; g_done_804aa76c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
