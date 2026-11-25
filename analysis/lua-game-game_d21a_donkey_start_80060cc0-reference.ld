/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21a_donkey_start_80060cc0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_donkey_800eb6e4 = 0x800eb6e4;
w3d_float_property_800fc270 = 0x800fc270;
w3d_identity_80341584 = 0x80341584;
w3d_identity_80342a74 = 0x80342a74;
w3d_model_query_801797b4 = 0x801797b4;
w3d_play_sound_pair_800edc28 = 0x800edc28;
w3d_post_object_events_800ed090 = 0x800ed090;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_803791f4 = 0x803791f4;
w3d_string_80379204 = 0x80379204;
w3d_string_8037921c = 0x8037921c;
w3d_string_80379234 = 0x80379234;
w3d_string_80379248 = 0x80379248;
w3d_string_8037925c = 0x8037925c;
w3d_string_8037926c = 0x8037926c;
w3d_string_8037927c = 0x8037927c;
w3d_string_8037928c = 0x8037928c;
w3d_vector_property_800fc2f0 = 0x800fc2f0;
w3d_zero_vector_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d21a_donkey_start_80060cc0 0x80060cc0 : { *(.text.w3d_d21a_donkey_start_80060cc0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
