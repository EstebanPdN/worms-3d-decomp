/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40g_tweak_page_8004ff24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
__as__6StringPCc = 0x8020bd38;
as_float_80342a74 = 0x80342a74;
as_hex_80343858 = 0x80343858;
as_int_803426b4 = 0x803426b4;
as_ptr_80341584 = 0x80341584;
as_string_80343744 = 0x80343744;
as_uint_80342a78 = 0x80342a78;
as_vec_80342fa4 = 0x80342fa4;
closing_803f3fcc = 0x803f3fcc;
columns_803f3fd4 = 0x803f3fd4;
s_80377f3c = 0x80377f3c;
s_80377f40 = 0x80377f40;
s_80377f48 = 0x80377f48;
s_80377f4c = 0x80377f4c;
s_80377f54 = 0x80377f54;
s_80377f5c = 0x80377f5c;
s_80377f68 = 0x80377f68;
sink_write_802cbdf8 = 0x802cbdf8;
string_append_8020bf2c = 0x8020bf2c;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_pad_8020c43c = 0x8020c43c;
string_release_80341588 = 0x80341588;
string_release_header_8020bb2c = 0x8020bb2c;
string_truncate_8020c3a0 = 0x8020c3a0;
text_add_802cc0ac = 0x802cc0ac;
text_line_802cbf2c = 0x802cbf2c;
text_position_802cd26c = 0x802cd26c;
value_float_80178df0 = 0x80178df0;
value_hex_8017941c = 0x8017941c;
value_int_80178c48 = 0x80178c48;
value_ptr_801797b4 = 0x801797b4;
value_string_80179170 = 0x80179170;
value_uint_80178d1c = 0x80178d1c;
value_vec_80178ec4 = 0x80178ec4;
widths_803f3fe4 = 0x803f3fe4;
SECTIONS {
  .text.d40g_tweak_page_8004ff24 0x8004ff24 : { *(.text.d40g_tweak_page_8004ff24) }
  .sdata 0x804aaa00 (NOLOAD) : {
    . = 0x0; pad_804aaa00 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
