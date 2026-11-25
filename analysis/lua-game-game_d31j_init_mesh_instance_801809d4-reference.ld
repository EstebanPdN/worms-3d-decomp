/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31j_init_mesh_instance_801809d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801804c8 = 0x801804c8;
fn_80180804 = 0x80180804;
lbl_80362984 = 0x80362984;
lbl_80413368 = 0x80413368;
lbl_80413418 = 0x80413418;
lbl_80413b28 = 0x80413b28;
lbl_804144f8 = 0x804144f8;
lbl_80414850 = 0x80414850;
lbl_80414940 = 0x80414940;
lbl_80414970 = 0x80414970;
lbl_80414ae0 = 0x80414ae0;
lbl_80417000 = 0x80417000;
w3d_auto_80179aec = 0x80179aec;
w3d_auto_801f2798 = 0x801f2798;
w3d_empty_80341348 = 0x80341348;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_mesh_descriptor_get_clip = 0x80180404;
w3d_mesh_instance_collect = 0x80182274;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_format = 0x8020c510;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d31j_init_mesh_instance_801809d4 0x801809d4 : { *(.text.d31j_init_mesh_instance_801809d4) }
  .rodata 0x803a783c : { *(.rodata) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . = 0x2c; lbl_804ab628 = .;
    . = 0x4bc8; lbl_804b01c4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
