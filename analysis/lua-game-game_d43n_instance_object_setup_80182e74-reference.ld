/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43n_instance_object_setup_80182e74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_8020bb54PCc = 0x8020bb54;
lbl_804144f8 = 0x804144f8;
lbl_80414940 = 0x80414940;
strcat = 0x802ef108;
w3d_auto_80179aec = 0x80179aec;
w3d_empty_8034cc30 = 0x8034cc30;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d43n_instance_object_setup_80182e74 0x80182e74 : { *(.text.w3d_d43n_instance_object_setup_80182e74) }
  .rodata 0x803a7928 : { *(.rodata) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . = 0x54; lbl_804ab650 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
