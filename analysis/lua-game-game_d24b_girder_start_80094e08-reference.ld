/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_girder_start_80094e08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_created_message_800c1620 = 0x800c1620;
w3d_float_read_800fc270 = 0x800fc270;
w3d_handle_construct_801261bc = 0x801261bc;
w3d_handle_member_query_80126308 = 0x80126308;
w3d_heap_allocate_802098d8 = 0x802098d8;
w3d_identity_803426b4 = 0x803426b4;
w3d_message_post_8016239c = 0x8016239c;
w3d_named_slot_select_800a7e14 = 0x800a7e14;
w3d_planar_heading_80095450 = 0x80095450;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8037ea14 = 0x8037ea14;
w3d_string_8037ea8c = 0x8037ea8c;
w3d_string_8037ea9c = 0x8037ea9c;
w3d_string_8037eaac = 0x8037eaac;
w3d_string_8037eac4 = 0x8037eac4;
w3d_string_8037eae0 = 0x8037eae0;
w3d_string_8037eaec = 0x8037eaec;
w3d_string_8037eb04 = 0x8037eb04;
w3d_subscribe_80162024 = 0x80162024;
w3d_transform_points_80095b58 = 0x80095b58;
w3d_update_value_80178c54 = 0x80178c54;
SECTIONS {
  .text.w3d_d24b_girder_start_80094e08 0x80094e08 : { *(.text.w3d_d24b_girder_start_80094e08) }
  .rodata 0x8037eb20 : { *(.rodata) }
  .sdata 0x804ade50 (NOLOAD) : {
    . = 0x0; w3d_message_804ade50 = .;
    . = 0x8; w3d_message_804ade58 = .;
    . = 0x10; w3d_message_804ade60 = .;
    . = 0x18; w3d_message_804ade68 = .;
    . = 0x20; w3d_message_804ade70 = .;
    . = 0x28; w3d_message_804ade78 = .;
    . = 0x30; w3d_message_804ade80 = .;
    . = 0x38; w3d_message_804ade88 = .;
    . = 0x40; w3d_message_804ade90 = .;
    . = 0x48; w3d_message_804ade98 = .;
    . = 0x50; w3d_message_804adea0 = .;
    . = 0x58; w3d_message_804adea8 = .;
    . = 0x60; w3d_message_804adeb0 = .;
    . = 0x68; w3d_message_804adeb8 = .;
    . = 0x70; w3d_message_804adec0 = .;
    . = 0x78; w3d_message_804adec8 = .;
    . = 0x80; w3d_message_804aded0 = .;
    . = 0x88; w3d_message_804aded8 = .;
    . = 0x90; w3d_message_804adee0 = .;
    . = 0x98; w3d_message_804adee8 = .;
    . = 0xa0; w3d_message_804adef0 = .;
    . = 0xa8; w3d_message_804adef8 = .;
    . = 0xb0; w3d_message_804adf00 = .;
    . = 0xe0; w3d_message_804adf30 = .;
    . = 0xe8; w3d_message_804adf38 = .;
    . = 0xf0; w3d_message_804adf40 = .;
    . = 0x176c; w3d_pool_804af5bc = .;
    . = 0x3904; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
