/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43n_mesh_clone_object_setup_typed_80188b38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eee50 = 0x802eee50;
lbl_80364234 = 0x80364234;
lbl_80364284 = 0x80364284;
lbl_804144f8 = 0x804144f8;
lbl_80414940 = 0x80414940;
lbl_80414af0 = 0x80414af0;
lbl_80414b10 = 0x80414b10;
lbl_80414b20 = 0x80414b20;
w3d_auto_80179aec = 0x80179aec;
w3d_empty_8034cc38 = 0x8034cc38;
w3d_k5b_array_ref_lock_801ef048 = 0x801ef048;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s21_fetch_801ea470 = 0x801ea470;
SECTIONS {
  .text.w3d_d43n_mesh_clone_object_setup_typed_80188b38 0x80188b38 : { *(.text.w3d_d43n_mesh_clone_object_setup_typed_80188b38) }
  .rodata 0x803a7be0 : { *(.rodata) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . = 0x9c; lbl_804ab698 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
