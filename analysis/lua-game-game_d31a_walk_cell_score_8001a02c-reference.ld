/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31a_walk_cell_score_8001a02c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_grid_byte_cell_8001dff8 = 0x8001dff8;
k5a_grid_cell_slot_8001e1a0 = 0x8001e1a0;
s19_lookup_slot_8008c548 = 0x8008c548;
sqrt_802e82c0 = 0x802e82c0;
w3d_auto_80015588 = 0x80015588;
w3d_cc18a_grid_cell_slot_8001e11c = 0x8001e11c;
w3d_cx12a_sample_grid_8001e224 = 0x8001e224;
w3d_fn_802e8094 = 0x802e8094;
w3d_libm_forward_802e83cc = 0x802e83cc;
w3d_player_list_weapon_count_8008c534 = 0x8008c534;
SECTIONS {
  .text.w3d_d31a_walk_cell_score_8001a02c 0x8001a02c : { *(.text.w3d_d31a_walk_cell_score_8001a02c) }
  .rodata 0x8036a960 : { *(.rodata) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; g_tick_804aa570 = .;
    . = 0x168; w3d_game_804aa6d8 = .;
    . = 0x1e0; g_blasts_804aa750 = .;
    . = 0x1e4; g_marks_804aa754 = .;
    . = 0x1ec; g_mines_804aa75c = .;
    . = 0x1f4; g_blast_scale_804aa764 = .;
    . = 0x5dc; g_players_804aab4c = .;
    . = 0x71e8; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
