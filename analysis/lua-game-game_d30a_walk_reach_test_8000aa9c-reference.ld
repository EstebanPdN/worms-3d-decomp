/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_walk_reach_test_8000aa9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_grid_byte_cell_8001dff8 = 0x8001dff8;
cc26a_grid_select_layer_8001e328 = 0x8001e328;
g_centre_8041d3a0 = 0x8041d3a0;
k2a_grid_position_8001f9f0 = 0x8001f9f0;
sqrt_802e82c0 = 0x802e82c0;
w3d_cached_name_lookup_80341694 = 0x80341694;
w3d_cx12a_sample_grid_8001e224 = 0x8001e224;
SECTIONS {
  .text.w3d_d30a_walk_reach_test_8000aa9c 0x8000aa9c : { *(.text.w3d_d30a_walk_reach_test_8000aa9c) }
  .rodata 0x80369be8 : { *(.rodata) }
  .sdata 0x804b1758 (NOLOAD) : {
    . = 0x0; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
