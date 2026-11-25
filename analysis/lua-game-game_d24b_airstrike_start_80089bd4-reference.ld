/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_airstrike_start_80089bd4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_assign_interface_8002f6dc = 0x8002f6dc;
w3d_copy_802eee50 = 0x802eee50;
w3d_cosf_802e86d4 = 0x802e86d4;
w3d_float_read_800fc270 = 0x800fc270;
w3d_register_80164514 = 0x80164514;
w3d_release_802134fc = 0x802134fc;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_service_forward_8020b680 = 0x8020b680;
w3d_sinf_802e88ac = 0x802e88ac;
w3d_strcmp_802ef234 = 0x802ef234;
w3d_string_8037d898 = 0x8037d898;
w3d_string_8037d8b0 = 0x8037d8b0;
w3d_string_8037d8c8 = 0x8037d8c8;
w3d_string_8037d8e4 = 0x8037d8e4;
w3d_string_8037d8f8 = 0x8037d8f8;
w3d_string_8037d90c = 0x8037d90c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_read_800fc2b0 = 0x800fc2b0;
w3d_string_release_80341588 = 0x80341588;
w3d_teams_8043bb64 = 0x8043bb64;
w3d_type_8040e4a8 = 0x8040e4a8;
w3d_vector_write_800fc5dc = 0x800fc5dc;
SECTIONS {
  .text.w3d_d24b_airstrike_start_80089bd4 0x80089bd4 : { *(.text.w3d_d24b_airstrike_start_80089bd4) }
  .rodata 0x8037d928 : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_manager_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
