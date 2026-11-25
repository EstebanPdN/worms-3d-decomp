/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_plan_score_update_80017f0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_center_8041d3a0 = 0x8041d3a0;
s19_check_pair_80015434 = 0x80015434;
s19_lookup_slot_8008c454 = 0x8008c454;
s8_index_query_800fc6dc = 0x800fc6dc;
s8_index_query_800fcb4c = 0x800fcb4c;
sqrt_802e82c0 = 0x802e82c0;
w3d_auto_80015488 = 0x80015488;
w3d_auto_80015588 = 0x80015588;
w3d_auto_800155ac = 0x800155ac;
w3d_component_position_801256ec = 0x801256ec;
w3d_component_radius_801256e4 = 0x801256e4;
w3d_fn_802e8094 = 0x802e8094;
w3d_libm_forward_802e83cc = 0x802e83cc;
w3d_player_list_worm_count_8008c440 = 0x8008c440;
SECTIONS {
  .text.w3d_d27a_plan_score_update_80017f0c 0x80017f0c : { *(.text.w3d_d27a_plan_score_update_80017f0c) }
  .rodata 0x8036a858 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_settings_804aa6d8 = .;
    . = 0x6c; g_b_804aa744 = .;
    . = 0x70; g_a_804aa748 = .;
    . = 0x74; g_scale_804aa74c = .;
    . = 0x474; g_players_804aab4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
