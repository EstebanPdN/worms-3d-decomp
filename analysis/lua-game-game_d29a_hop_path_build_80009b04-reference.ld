/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29a_hop_path_build_80009b04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__5Queue = 0x80003300;
cc26a_grid_byte_cell_8001dff8 = 0x8001dff8;
cc26a_grid_select_layer_8001e328 = 0x8001e328;
fn_8001bc1c = 0x8001bc1c;
g_centre_8041d3a0 = 0x8041d3a0;
k2a_apply_fit_8001c0d8 = 0x8001c0d8;
k5a_vec_offset_8001bbb0 = 0x8001bbb0;
sqrt_802e82c0 = 0x802e82c0;
w3d_ai_weapon_available = 0x80007ccc;
w3d_auto_8001523c = 0x8001523c;
w3d_d28a_command_vector_append_80003424 = 0x80003424;
w3d_trace_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_d29a_hop_path_build_80009b04 0x80009b04 : { *(.text.w3d_d29a_hop_path_build_80009b04) }
  .rodata 0x803695b8 : { *(.rodata) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; g_clock_804aa570 = .;
    . = 0x16c; w3d_game_804aa6dc = .;
    . = 0x170; w3d_busy_804aa6e0 = .;
    . = 0x174; w3d_lock_804aa6e4 = .;
    . = 0x71e8; w3d_grid_804b1758 = .;
    . = 0x71f4; g_hit_time_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
