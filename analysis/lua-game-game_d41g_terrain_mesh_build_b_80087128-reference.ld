/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41g_terrain_mesh_build_b_80087128)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8010abc8 = 0x8010abc8;
lbl_8010ad20 = 0x8010ad20;
lbl_8037d0c4 = 0x8037d0c4;
memset = 0x802eefe0;
w3d_cells_80087628 = 0x80087628;
w3d_preview_init_80091ee0 = 0x80091ee0;
w3d_render_8010d8a4 = 0x8010d8a4;
w3d_row_80086b08 = 0x80086b08;
SECTIONS {
  .text.d41g_terrain_mesh_build_b_80087128 0x80087128 : { *(.text.d41g_terrain_mesh_build_b_80087128) }
  .rodata 0x8037d0c8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
