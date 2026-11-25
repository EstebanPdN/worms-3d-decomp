/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_aim_arrow_start_80028708)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_identity_803426b4 = 0x803426b4;
w3d_identity_80342a74 = 0x80342a74;
w3d_identity_80342fa4 = 0x80342fa4;
w3d_object_float_80178df0 = 0x80178df0;
w3d_object_vector_80178ec4 = 0x80178ec4;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8036cd7c = 0x8036cd7c;
w3d_string_8036cd8c = 0x8036cd8c;
w3d_string_8036cd98 = 0x8036cd98;
w3d_string_8036cda8 = 0x8036cda8;
w3d_string_8036cdc4 = 0x8036cdc4;
w3d_string_8036cde0 = 0x8036cde0;
w3d_string_8036cdf8 = 0x8036cdf8;
w3d_string_8036ce14 = 0x8036ce14;
w3d_string_8036ce30 = 0x8036ce30;
w3d_string_8036ce4c = 0x8036ce4c;
w3d_string_8036ce68 = 0x8036ce68;
w3d_string_8036ce80 = 0x8036ce80;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
w3d_vector_property_800fc2f0 = 0x800fc2f0;
SECTIONS {
  .text.w3d_d32a_aim_arrow_start_80028708 0x80028708 : { *(.text.w3d_d32a_aim_arrow_start_80028708) }
  .rodata 0x8036ce9c : { *(.rodata) }
  .sdata 0x804acbec (NOLOAD) : {
    . = 0x0; w3d_message_804acbec = .;
    . = 0x8; w3d_message_804acbf4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
