/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_weapon_aim_start_80026288)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_handle_load_8015adf4 = 0x8015adf4;
w3d_identity_8034357c = 0x8034357c;
w3d_identity_80343584 = 0x80343584;
w3d_int_property_800fc230 = 0x800fc230;
w3d_message_post_8016239c = 0x8016239c;
w3d_refresh_800261d4 = 0x800261d4;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_8036c9b8 = 0x8036c9b8;
w3d_string_8036c9d8 = 0x8036c9d8;
w3d_string_8036c9e8 = 0x8036c9e8;
w3d_string_8036c9f8 = 0x8036c9f8;
w3d_string_8036ca10 = 0x8036ca10;
w3d_string_8036ca30 = 0x8036ca30;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
w3d_visibility_80026064 = 0x80026064;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d32a_weapon_aim_start_80026288 0x80026288 : { *(.text.w3d_d32a_weapon_aim_start_80026288) }
  .sdata 0x804aa7ec (NOLOAD) : {
    . = 0x0; w3d_attach_804aa7ec = .;
    . = 0x4; w3d_attach_804aa7f0 = .;
    . = 0x2308; w3d_message_804acaf4 = .;
    . = 0x2310; w3d_message_804acafc = .;
    . = 0x2318; w3d_message_804acb04 = .;
    . = 0x2328; w3d_message_804acb14 = .;
    . = 0x6f68; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
