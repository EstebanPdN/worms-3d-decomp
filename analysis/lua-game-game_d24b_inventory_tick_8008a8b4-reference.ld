/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_inventory_tick_8008a8b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_as_inventory_80179598 = 0x80179598;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_identity_80341584 = 0x80341584;
w3d_int_read_800fc230 = 0x800fc230;
w3d_int_write_800fc43c = 0x800fc43c;
w3d_message_post_8016239c = 0x8016239c;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8037dbc0 = 0x8037dbc0;
w3d_string_8037dbd4 = 0x8037dbd4;
w3d_vtable_8040db38 = 0x8040db38;
w3d_weapon_count_8025c3a8 = 0x8025c3a8;
w3d_weapon_count_set_8025c71c = 0x8025c71c;
SECTIONS {
  .text.w3d_d24b_inventory_tick_8008a8b4 0x8008a8b4 : { *(.text.w3d_d24b_inventory_tick_8008a8b4) }
  .sdata 0x804adcf4 (NOLOAD) : {
    . = 0x0; w3d_message_804adcf4 = .;
    . = 0xa8; w3d_message_804add9c = .;
    . = 0x3a60; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
