/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31j_load_mesh_resource_8018a8fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d26j_rebuild_sorted_edges_8018b638 = 0x8018b638;
lbl_8040e058 = 0x8040e058;
lbl_8040e118 = 0x8040e118;
lbl_804144f8 = 0x804144f8;
lbl_80414518 = 0x80414518;
lbl_80414940 = 0x80414940;
w3d_cx13b_sphere_bounds_801f5724 = 0x801f5724;
w3d_d29e_run_file_8020b6e8 = 0x8020b6e8;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_k8b_iface_add_801b14e8 = 0x801b14e8;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d31j_load_mesh_resource_8018a8fc 0x8018a8fc : { *(.text.d31j_load_mesh_resource_8018a8fc) }
  .rodata 0x803a7d18 : { *(.rodata) }
  .sdata 0x804b0240 (NOLOAD) : {
    . = 0x0; lbl_804b0240 = .;
    . = 0x4; lbl_804b0244 = .;
    . = 0x10; lbl_804b0250 = .;
    . = 0x1c; lbl_804b025c = .;
    . = 0x20; lbl_804b0260 = .;
    . = 0x24; lbl_804b0264 = .;
    . = 0x2c; lbl_804b026c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
