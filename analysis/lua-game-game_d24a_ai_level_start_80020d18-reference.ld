/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_ai_level_start_80020d18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
w3d_apply_801ea4c8 = 0x801ea4c8;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_create_80164514 = 0x80164514;
w3d_identity_80341584 = 0x80341584;
w3d_player_800fcb80 = 0x800fcb80;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8036bcf8 = 0x8036bcf8;
w3d_string_8036bd08 = 0x8036bd08;
w3d_string_8036bd1c = 0x8036bd1c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
w3d_tag_destroy_80178474 = 0x80178474;
w3d_type_8040dab8 = 0x8040dab8;
w3d_type_8040dda8 = 0x8040dda8;
w3d_type_lookup_8020b680 = 0x8020b680;
w3d_value_801797b4 = 0x801797b4;
SECTIONS {
  .text.w3d_d24a_ai_level_start_80020d18 0x80020d18 : { *(.text.w3d_d24a_ai_level_start_80020d18) }
  .sdata 0x804ac950 (NOLOAD) : {
    . = 0x0; w3d_message_804ac950 = .;
    . = 0x8; w3d_message_804ac958 = .;
    . = 0x10; w3d_message_804ac960 = .;
    . = 0x18; w3d_message_804ac968 = .;
    . = 0x20; w3d_message_804ac970 = .;
    . = 0x28; w3d_message_804ac978 = .;
    . = 0x30; w3d_message_804ac980 = .;
    . = 0x38; w3d_message_804ac988 = .;
    . = 0x40; w3d_message_804ac990 = .;
    . = 0x48; w3d_message_804ac998 = .;
    . = 0x50; w3d_message_804ac9a0 = .;
    . = 0x58; w3d_message_804ac9a8 = .;
    . = 0x60; w3d_message_804ac9b0 = .;
    . = 0x68; w3d_message_804ac9b8 = .;
    . = 0x70; w3d_message_804ac9c0 = .;
    . = 0x4e38; w3d_game_state_804b1788 = .;
    . = 0x4e3c; w3d_service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
