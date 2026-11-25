/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d23a_worm_select_start_8003c0f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_identity_803426b4 = 0x803426b4;
w3d_identity_80342a78 = 0x80342a78;
w3d_message_post_8016239c = 0x8016239c;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_80374408 = 0x80374408;
w3d_string_8037441c = 0x8037441c;
w3d_subscribe_80162024 = 0x80162024;
w3d_vtable_8040db38 = 0x8040db38;
w3d_worm_select_8003bf70 = 0x8003bf70;
w3d_worm_select_update_8003cdcc = 0x8003cdcc;
SECTIONS {
  .text.w3d_d23a_worm_select_start_8003c0f0 0x8003c0f0 : { *(.text.w3d_d23a_worm_select_start_8003c0f0) }
  .sdata 0x804ad138 (NOLOAD) : {
    . = 0x0; w3d_message_804ad138 = .;
    . = 0x8; w3d_message_804ad140 = .;
    . = 0x10; w3d_message_804ad148 = .;
    . = 0x18; w3d_message_804ad150 = .;
    . = 0x20; w3d_message_804ad158 = .;
    . = 0x28; w3d_message_804ad160 = .;
    . = 0x30; w3d_message_804ad168 = .;
    . = 0x38; w3d_message_804ad170 = .;
    . = 0x48; w3d_message_804ad180 = .;
    . = 0x461c; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
