/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43n_mesh_clone_object_setup_801851e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eee50 = 0x802eee50;
lbl_804144f8 = 0x804144f8;
lbl_80414600 = 0x80414600;
lbl_80414940 = 0x80414940;
w3d_auto_80179aec = 0x80179aec;
w3d_empty_8034cc34 = 0x8034cc34;
w3d_k5b_array_ref_lock_801ef048 = 0x801ef048;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s21_fetch_801ea470 = 0x801ea470;
SECTIONS {
  .text.w3d_d43n_mesh_clone_object_setup_801851e0 0x801851e0 : { *(.text.w3d_d43n_mesh_clone_object_setup_801851e0) }
  .rodata 0x803a7a7c : { *(.rodata) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . = 0x74; lbl_804ab670 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
