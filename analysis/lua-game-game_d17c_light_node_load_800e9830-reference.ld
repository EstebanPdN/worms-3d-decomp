/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17c_light_node_load_800e9830)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d17c_String_8020bb54PCc = 0x8020bb54;
d17c_as_node_80343584 = 0x80343584;
d17c_as_owner_80341584 = 0x80341584;
d17c_handle_load_8015adf4 = 0x8015adf4;
d17c_heap_allocate_802098d8 = 0x802098d8;
d17c_member_attach_80126610 = 0x80126610;
d17c_member_destroy_801265a4 = 0x801265a4;
d17c_member_init_kind_8012656c = 0x8012656c;
d17c_owner_team_801797b4 = 0x801797b4;
d17c_string_finish_8020c5c4 = 0x8020c5c4;
d17c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d17c_light_node_load_800e9830 0x800e9830 : { *(.text.d17c_light_node_load_800e9830) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; d17c_member_heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
