/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16c_payload_attach_800e9b88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d16c_String_8020bb54PCc = 0x8020bb54;
d16c_as_owner_80341584 = 0x80341584;
d16c_handle_load_8015adf4 = 0x8015adf4;
d16c_label_create_801222cc = 0x801222cc;
d16c_label_service_80410b08 = 0x80410b08;
d16c_manager_attach_80164514 = 0x80164514;
d16c_null_text_8038b2a0 = 0x8038b2a0;
d16c_owner_team_801797b4 = 0x801797b4;
d16c_service_forward_8020b680 = 0x8020b680;
d16c_string_finish_8020c5c4 = 0x8020c5c4;
d16c_string_header_80341884 = 0x80341884;
d16c_string_init_8020c5c0 = 0x8020c5c0;
d16c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d16c_payload_attach_800e9b88 0x800e9b88 : { *(.text.d16c_payload_attach_800e9b88) }
  .sdata 0x804aaba4 (NOLOAD) : {
    . = 0x0; d16c_config_804aaba4 = .;
    . = 0x6be8; d16c_manager_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
