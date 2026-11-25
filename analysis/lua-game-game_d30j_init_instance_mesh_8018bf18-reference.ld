/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_init_instance_mesh_8018bf18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eee50 = 0x802eee50;
lbl_804144f8 = 0x804144f8;
lbl_80414940 = 0x80414940;
lbl_80414b30 = 0x80414b30;
lbl_804b06a0 = 0x804b06a0;
w3d_auto_80179aec = 0x80179aec;
w3d_empty_8034435c = 0x8034435c;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s21_fetch_801ea470 = 0x801ea470;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d30j_init_instance_mesh_8018bf18 0x8018bf18 : { *(.text.d30j_init_instance_mesh_8018bf18) }
  .rodata 0x803a7e20 : { *(.rodata) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . = 0xb4; lbl_804ab6b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
