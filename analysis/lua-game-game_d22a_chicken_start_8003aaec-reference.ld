/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d22a_chicken_start_8003aaec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_created_message_init_800c1620 = 0x800c1620;
w3d_find_spawn_point_8003ad14 = 0x8003ad14;
w3d_identity_80342a74 = 0x80342a74;
w3d_int_property_800fc1f0 = 0x800fc1f0;
w3d_message_post_8016239c = 0x8016239c;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80374270 = 0x80374270;
w3d_string_80374280 = 0x80374280;
w3d_string_80374294 = 0x80374294;
w3d_string_8037429c = 0x8037429c;
w3d_string_803742b4 = 0x803742b4;
w3d_string_property_800fc2b0 = 0x800fc2b0;
w3d_zero_vector_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d22a_chicken_start_8003aaec 0x8003aaec : { *(.text.w3d_d22a_chicken_start_8003aaec) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
