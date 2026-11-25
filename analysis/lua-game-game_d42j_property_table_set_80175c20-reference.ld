/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(property_table_set_80175c20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc42a_bind_typed_8017963c = 0x8017963c;
d24j_find_table_slot_80177eb0 = 0x80177eb0;
f3c_propagate_tag_801ea4c8 = 0x801ea4c8;
s9_beam_80179428 = 0x80179428;
w3d_auto_80179598 = 0x80179598;
w3d_auto_801797b4 = 0x801797b4;
w3d_auto_801fff3c = 0x801fff3c;
w3d_empty_80341584 = 0x80341584;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_s20_clear_target_80179770 = 0x80179770;
w3d_s20_destroy_owned_80178474 = 0x80178474;
w3d_s20_replace_target_801795d4 = 0x801795d4;
SECTIONS {
  .text.property_table_set_80175c20 0x80175c20 : { *(.text.property_table_set_80175c20) }
  .sdata 0x804ab5b0 (NOLOAD) : {
    . = 0x0; lbl_804ab5b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
