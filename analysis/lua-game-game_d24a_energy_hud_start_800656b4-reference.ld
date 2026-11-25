/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_energy_hud_start_800656b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_create_part_80164514 = 0x80164514;
w3d_identity_803426b4 = 0x803426b4;
w3d_identity_80342a74 = 0x80342a74;
w3d_identity_80342a78 = 0x80342a78;
w3d_lookup_80164fc8 = 0x80164fc8;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_set_label_80064384 = 0x80064384;
w3d_set_mode_80064190 = 0x80064190;
w3d_stamp_800664c4 = 0x800664c4;
w3d_string_80379e18 = 0x80379e18;
w3d_string_80379e28 = 0x80379e28;
w3d_string_80379e40 = 0x80379e40;
w3d_string_80379e5c = 0x80379e5c;
w3d_string_80379e68 = 0x80379e68;
w3d_subscribe_80162024 = 0x80162024;
w3d_type_8040edb0 = 0x8040edb0;
w3d_type_lookup_8020b680 = 0x8020b680;
w3d_update_80065ce0 = 0x80065ce0;
SECTIONS {
  .text.w3d_d24a_energy_hud_start_800656b4 0x800656b4 : { *(.text.w3d_d24a_energy_hud_start_800656b4) }
  .sdata 0x804ad558 (NOLOAD) : {
    . = 0x0; w3d_message_804ad558 = .;
    . = 0x8; w3d_message_804ad560 = .;
    . = 0x10; w3d_message_804ad568 = .;
    . = 0x18; w3d_message_804ad570 = .;
    . = 0x20; w3d_message_804ad578 = .;
    . = 0x28; w3d_message_804ad580 = .;
    . = 0x30; w3d_message_804ad588 = .;
    . = 0x38; w3d_message_804ad590 = .;
    . = 0x40; w3d_message_804ad598 = .;
    . = 0x48; w3d_message_804ad5a0 = .;
    . = 0x4234; w3d_service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
