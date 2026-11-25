/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21a_level_load_8006d610)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_arena_alloc_801613f0 = 0x801613f0;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_colour_property_800fc370 = 0x800fc370;
w3d_float_property_800fc270 = 0x800fc270;
w3d_level_lookup_800fc330 = 0x800fc330;
w3d_message_post_8016239c = 0x8016239c;
w3d_message_string_init_8010a8e0 = 0x8010a8e0;
w3d_string_8037bb64 = 0x8037bb64;
w3d_string_8037bbbc = 0x8037bbbc;
w3d_string_8037c0d4 = 0x8037c0d4;
w3d_string_8037c0e0 = 0x8037c0e0;
w3d_string_8037c110 = 0x8037c110;
w3d_string_8037c178 = 0x8037c178;
w3d_string_8037c188 = 0x8037c188;
w3d_string_8037c198 = 0x8037c198;
w3d_string_base_finish_8020c5c4 = 0x8020c5c4;
w3d_string_base_init_8020c5c0 = 0x8020c5c0;
w3d_string_header_80341884 = 0x80341884;
w3d_string_property_800fc2b0 = 0x800fc2b0;
w3d_string_property_write_800fc550 = 0x800fc550;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d21a_level_load_8006d610 0x8006d610 : { *(.text.w3d_d21a_level_load_8006d610) }
  .sdata 0x804aa78c (NOLOAD) : {
    . = 0x0; w3d_fog_range_804aa78c = .;
    . = 0x2fd0; w3d_message_804ad75c = .;
    . = 0x2fd8; w3d_message_804ad764 = .;
    . = 0x2fe8; w3d_message_804ad774 = .;
    . = 0x6fc8; w3d_message_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
