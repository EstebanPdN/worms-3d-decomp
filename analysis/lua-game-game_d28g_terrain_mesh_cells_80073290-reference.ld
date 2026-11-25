/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28g_terrain_mesh_cells_80073290)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178df0 = 0x80178df0;
w3d_cell_offset_804336a0 = 0x804336a0;
w3d_cell_offset_804336ac = 0x804336ac;
w3d_cell_offset_804336b8 = 0x804336b8;
w3d_cell_offset_804336c4 = 0x804336c4;
w3d_cell_offset_804336d0 = 0x804336d0;
w3d_cell_offset_804336dc = 0x804336dc;
w3d_cell_offset_804336e8 = 0x804336e8;
w3d_cell_offset_804336f4 = 0x804336f4;
w3d_d26b_preview_init_80091ee0 = 0x80091ee0;
w3d_empty_80342a74 = 0x80342a74;
w3d_quad_uv_table_80430020 = 0x80430020;
SECTIONS {
  .text.w3d_d28g_terrain_mesh_cells_80073290 0x80073290 : { *(.text.w3d_d28g_terrain_mesh_cells_80073290) }
  .rodata 0x8037ce54 : { *(.rodata) }
  .sdata 0x804ae548 (NOLOAD) : {
    . = 0x0; lbl_804ae548 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
