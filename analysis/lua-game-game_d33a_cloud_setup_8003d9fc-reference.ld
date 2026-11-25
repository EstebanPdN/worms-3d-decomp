/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33a_cloud_setup_8003d9fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
d29j_resize_mesh_arrays_8018920c = 0x8018920c;
g_items_804273d4 = 0x804273d4;
g_key_804143e0 = 0x804143e0;
w3d_auto_8020b648 = 0x8020b648;
w3d_empty_8034380c = 0x8034380c;
w3d_handle_set_name = 0x8015adf4;
w3d_k5b_array_ref_lock_801ef048 = 0x801ef048;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d33a_cloud_setup_8003d9fc 0x8003d9fc : { *(.text.w3d_d33a_cloud_setup_8003d9fc) }
  .rodata 0x803745d8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
