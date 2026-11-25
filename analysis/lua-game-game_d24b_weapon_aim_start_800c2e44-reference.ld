/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_weapon_aim_start_800c2e44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_active_actor_80156f88 = 0x80156f88;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_as_weapon_801797b4 = 0x801797b4;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_copy_802eee50 = 0x802eee50;
w3d_float_write_800fc4c8 = 0x800fc4c8;
w3d_handle_construct_801261bc = 0x801261bc;
w3d_handle_member_query_80126308 = 0x80126308;
w3d_heap_allocate_802098d8 = 0x802098d8;
w3d_identity_80341584 = 0x80341584;
w3d_int_read_800fc1f0 = 0x800fc1f0;
w3d_int_write_800fc3b0 = 0x800fc3b0;
w3d_message_post_8016239c = 0x8016239c;
w3d_release_802134fc = 0x802134fc;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_803831dc = 0x803831dc;
w3d_string_803831ec = 0x803831ec;
w3d_string_80383200 = 0x80383200;
w3d_string_80383214 = 0x80383214;
w3d_string_80383228 = 0x80383228;
w3d_subscribe_80162024 = 0x80162024;
w3d_target_message_801190b4 = 0x801190b4;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d24b_weapon_aim_start_800c2e44 0x800c2e44 : { *(.text.w3d_d24b_weapon_aim_start_800c2e44) }
  .rodata 0x80383234 : { *(.rodata) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; w3d_turns_804ab400 = .;
    . = 0x32dc; w3d_message_804ae6dc = .;
    . = 0x32fc; w3d_message_804ae6fc = .;
    . = 0x3324; w3d_message_804ae724 = .;
    . = 0x3354; w3d_message_804ae754 = .;
    . = 0x335c; w3d_message_804ae75c = .;
    . = 0x41bc; w3d_pool_804af5bc = .;
    . = 0x6354; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
