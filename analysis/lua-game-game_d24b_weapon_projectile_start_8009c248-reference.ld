/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_weapon_projectile_start_8009c248)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_active_team_value_80020834 = 0x80020834;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_as_weapon_801797b4 = 0x801797b4;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_float_write_800fc4c8 = 0x800fc4c8;
w3d_handle_construct_801261bc = 0x801261bc;
w3d_handle_member_query_80126308 = 0x80126308;
w3d_heap_allocate_802098d8 = 0x802098d8;
w3d_helper_construct_8009daa4 = 0x8009daa4;
w3d_identity_80341584 = 0x80341584;
w3d_int_read_800fc1f0 = 0x800fc1f0;
w3d_int_read_800fc230 = 0x800fc230;
w3d_int_write_800fc3b0 = 0x800fc3b0;
w3d_int_write_800fc43c = 0x800fc43c;
w3d_message_post_8016239c = 0x8016239c;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80380078 = 0x80380078;
w3d_string_803800a0 = 0x803800a0;
w3d_string_80380180 = 0x80380180;
w3d_string_80380190 = 0x80380190;
w3d_string_803801a4 = 0x803801a4;
w3d_string_803801b0 = 0x803801b0;
w3d_string_803801c4 = 0x803801c4;
w3d_string_803801d8 = 0x803801d8;
w3d_string_803801ec = 0x803801ec;
w3d_subscribe_80162024 = 0x80162024;
w3d_target_message_801190b4 = 0x801190b4;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d24b_weapon_projectile_start_8009c248 0x8009c248 : { *(.text.w3d_d24b_weapon_projectile_start_8009c248) }
  .rodata 0x803801f8 : { *(.rodata) }
  .sdata 0x804ae000 (NOLOAD) : {
    . = 0x0; w3d_message_804ae000 = .;
    . = 0x8; w3d_message_804ae008 = .;
    . = 0x18; w3d_message_804ae018 = .;
    . = 0x40; w3d_message_804ae040 = .;
    . = 0x48; w3d_message_804ae048 = .;
    . = 0xa8; w3d_message_804ae0a8 = .;
    . = 0x15bc; w3d_pool_804af5bc = .;
    . = 0x1798; w3d_message_804af798 = .;
    . = 0x3754; w3d_message_arena_804b1754 = .;
    . = 0x3760; w3d_game_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
