/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_chat_indicator_start_80037d14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_chat_indicator_reset_80038240 = 0x80038240;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_identity_80342a74 = 0x80342a74;
w3d_identity_80342fa4 = 0x80342fa4;
w3d_identity_8034357c = 0x8034357c;
w3d_object_float_80178df0 = 0x80178df0;
w3d_object_value_80178ec4 = 0x80178ec4;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80373ed4 = 0x80373ed4;
w3d_string_80373eec = 0x80373eec;
w3d_string_80373f04 = 0x80373f04;
w3d_string_80373f20 = 0x80373f20;
w3d_string_80373f3c = 0x80373f3c;
w3d_string_80373f58 = 0x80373f58;
w3d_string_80373f70 = 0x80373f70;
w3d_string_80373f88 = 0x80373f88;
w3d_string_80373fa0 = 0x80373fa0;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d24a_chat_indicator_start_80037d14 0x80037d14 : { *(.text.w3d_d24a_chat_indicator_start_80037d14) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_game_state_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
