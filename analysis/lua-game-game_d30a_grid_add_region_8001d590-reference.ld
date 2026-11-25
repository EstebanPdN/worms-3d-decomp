/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30a_grid_add_region_8001d590)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc25a_bounds_merge_xz_8001d240 = 0x8001d240;
memcpy_802eee50 = 0x802eee50;
w3d_auto_8001523c = 0x8001523c;
w3d_auto_80015264 = 0x80015264;
w3d_auto_800152ac = 0x800152ac;
w3d_auto_8001cb40 = 0x8001cb40;
w3d_cx7a_grid_layer_shift_8001d1d8 = 0x8001d1d8;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d30a_grid_add_region_8001d590 0x8001d590 : { *(.text.w3d_d30a_grid_add_region_8001d590) }
  .rodata 0x8036b738 : { *(.rodata) }
  .sdata 0x804aa788 (NOLOAD) : {
    . = 0x0; g_ready_804aa788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
