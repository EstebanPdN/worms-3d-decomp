/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d47a_team_style_refs_8002107c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__15String_803426b8 = 0x803426b8;
handle_800fc82c = 0x800fc82c;
handle_800fcb80 = 0x800fcb80;
propagate_tag_801ea4c8 = 0x801ea4c8;
s_format_8036bd2c = 0x8036bd2c;
string_format_8020c510 = 0x8020c510;
team_entry_800fc6dc = 0x800fc6dc;
team_info_800fc7f8 = 0x800fc7f8;
w3d_auto_801797b4 = 0x801797b4;
w3d_empty_80341584 = 0x80341584;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d47a_team_style_refs_8002107c 0x8002107c : { *(.text.w3d_d47a_team_style_refs_8002107c) }
  .sdata 0x804aa7a0 (NOLOAD) : {
    . = 0x0; g_804aa7a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
