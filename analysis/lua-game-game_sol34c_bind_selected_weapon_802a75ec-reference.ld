/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol34c_bind_selected_weapon_802a75ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol34c_weapon_bind_800fd62c = 0x800fd62c;
sol34c_weapon_callback_802a75a0 = 0x802a75a0;
sol34c_weapon_error_803d6188 = 0x803d6188;
sol34c_weapon_format_8020c510 = 0x8020c510;
sol34c_weapon_identity_80341584 = 0x80341584;
sol34c_weapon_lookup_800fc1b0 = 0x800fc1b0;
sol34c_weapon_resource_801797b4 = 0x801797b4;
sol34c_weapon_string_finish_8020c5c4 = 0x8020c5c4;
sol34c_weapon_string_header_80341884 = 0x80341884;
sol34c_weapon_string_init_8020c5c0 = 0x8020c5c0;
sol34c_weapon_string_release_80341588 = 0x80341588;
sol34c_weapon_type_80366578 = 0x80366578;
SECTIONS {
  .text.sol34c_bind_selected_weapon_802a75ec 0x802a75ec : { *(.text.sol34c_bind_selected_weapon_802a75ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
