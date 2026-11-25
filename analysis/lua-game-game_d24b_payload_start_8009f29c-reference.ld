/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_payload_start_8009f29c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_active_team_value_80020834 = 0x80020834;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_as_weapon_801797b4 = 0x801797b4;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_identity_80341584 = 0x80341584;
w3d_message_post_8016239c = 0x8016239c;
w3d_payload_begin_800eb6e4 = 0x800eb6e4;
w3d_post_events_800ed090 = 0x800ed090;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_803806f8 = 0x803806f8;
w3d_string_80380704 = 0x80380704;
w3d_string_80380714 = 0x80380714;
w3d_update_span_800ecee8 = 0x800ecee8;
w3d_vector_property_800fc2f0 = 0x800fc2f0;
w3d_vtable_8040db38 = 0x8040db38;
w3d_zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d24b_payload_start_8009f29c 0x8009f29c : { *(.text.w3d_d24b_payload_start_8009f29c) }
  .sdata 0x804ae118 (NOLOAD) : {
    . = 0x0; w3d_message_804ae118 = .;
    . = 0x363c; w3d_message_arena_804b1754 = .;
    . = 0x3648; w3d_game_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
