/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31a_walk_pick_direction_80018f88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_grid_byte_cell_8001dff8 = 0x8001dff8;
cc26a_grid_select_layer_8001e328 = 0x8001e328;
g_origin_8041d480 = 0x8041d480;
g_reach_803eb8e8 = 0x803eb8e8;
s19_lookup_slot_8008c548 = 0x8008c548;
sqrt_802e82c0 = 0x802e82c0;
w3d_cc18a_grid_cell_slot_8001e11c = 0x8001e11c;
w3d_construct_801f6034 = 0x801f6034;
w3d_player_list_weapon_count_8008c534 = 0x8008c534;
w3d_rotate_rows_y_801f61a0 = 0x801f61a0;
SECTIONS {
  .text.w3d_d31a_walk_pick_direction_80018f88 0x80018f88 : { *(.text.w3d_d31a_walk_pick_direction_80018f88) }
  .rodata 0x8036a900 : { *(.rodata) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; g_blasts_804aa750 = .;
    . = 0x4; g_marks_804aa754 = .;
    . = 0x14; g_blast_scale_804aa764 = .;
    . = 0x3fc; g_players_804aab4c = .;
    . = 0x2174; g_ready_804ac8c4 = .;
    . = 0x7008; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
