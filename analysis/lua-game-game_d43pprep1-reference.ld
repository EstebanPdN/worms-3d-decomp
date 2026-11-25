/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40a_grid_finish_setup_8001d9ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
bounds_merge_8001d240 = 0x8001d240;
entry_free_800152ac = 0x800152ac;
grid_8001f2cc = 0x8001f2cc;
heap_free_80015264 = 0x80015264;
jump_ranges_8001fa68 = 0x8001fa68;
layer_setup_8001d388 = 0x8001d388;
layer_shift_8001d1d8 = 0x8001d1d8;
memcpy_802eee50 = 0x802eee50;
refresh_radius_8001e49c = 0x8001e49c;
s19_random_unit_80015810 = 0x80015810;
sqrt_802e82c0 = 0x802e82c0;
update_queue_8001ea34 = 0x8001ea34;
w3d_auto_80015860 = 0x80015860;
w3d_empty_80342fa4 = 0x80342fa4;
w3d_vector_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.w3d_d40a_grid_finish_setup_8001d9ac 0x8001d9ac : { *(.text.w3d_d40a_grid_finish_setup_8001d9ac) }
  .text.w3d_d43p_grid_pick_empty_cell_8001dd28 0x8001dd28 : { *(.text.w3d_d43p_grid_pick_empty_cell_8001dd28) }
  .rodata 0x8036b800 : { *(.rodata) }
  .sdata 0x804aa788 (NOLOAD) : {
    . = 0x0; g_804aa788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
