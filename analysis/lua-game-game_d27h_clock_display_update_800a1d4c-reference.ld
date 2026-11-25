/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_clock_display_update_800a1d4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
as_enum_80342a78 = 0x80342a78;
as_int_803426b4 = 0x803426b4;
as_text_8034380c = 0x8034380c;
clamp_seconds_800a2098 = 0x800a2098;
get_colour_80178f54 = 0x80178f54;
get_enum_80178d1c = 0x80178d1c;
get_int_80178c48 = 0x80178c48;
layout_800a30bc = 0x800a30bc;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
strip_800a34f4 = 0x800a34f4;
text_colours_80189760 = 0x80189760;
text_data_80189828 = 0x80189828;
vtable_8040db38 = 0x8040db38;
warn_800a2e78 = 0x800a2e78;
SECTIONS {
  .text.d27h_clock_display_update_800a1d4c 0x800a1d4c : { *(.text.d27h_clock_display_update_800a1d4c) }
  .sdata 0x804ae174 (NOLOAD) : {
    . = 0x0; id_804ae174 = .;
    . = 0x8; id_804ae17c = .;
    . = 0x35e0; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
