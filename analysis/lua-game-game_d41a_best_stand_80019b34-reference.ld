/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41a_best_stand_80019b34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_grid_byte_cell_8001dff8 = 0x8001dff8;
cc26a_grid_select_layer_8001e328 = 0x8001e328;
grid_finish_8001f25c = 0x8001f25c;
grid_probe_8001f1d8 = 0x8001f1d8;
w3d_center_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.w3d_d41a_best_stand_80019b34 0x80019b34 : { *(.text.w3d_d41a_best_stand_80019b34) }
  .rodata 0x8036a954 : { *(.rodata) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; g_team_804aa6c0 = .;
    . = 0x98; g_cells_804aa758 = .;
    . = 0x7098; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
