/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40j_material_add_key_801720fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
box_from_sphere_801f5724 = 0x801f5724;
free = 0x802134fc;
malloc = 0x80212fd4;
memcpy_802eee50 = 0x802eee50;
t_804144f8 = 0x804144f8;
t_80414518 = 0x80414518;
t_80414940 = 0x80414940;
t_80414af0 = 0x80414af0;
t_80414b10 = 0x80414b10;
t_80414b20 = 0x80414b20;
w3d_cx11b_compact_vector_grow_80210d54 = 0x80210d54;
w3d_handle_storage_release = 0x802134fc;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_free_8020bb2c = 0x8020bb2c;
SECTIONS {
  .text.w3d_d40j_material_add_key_801720fc 0x801720fc : { *(.text.w3d_d40j_material_add_key_801720fc) }
  .rodata 0x803a66cc : { *(.rodata) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . = 0x4b4c; lbl_804b0148 = .;
    . = 0x4b50; lbl_804b014c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
