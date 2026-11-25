/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_table_page_draw_800990a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
lbl_8037ff00 = 0x8037ff00;
lbl_8037ff64 = 0x8037ff64;
lbl_8037ff6c = 0x8037ff6c;
lbl_8037ff70 = 0x8037ff70;
lbl_803f4b90 = 0x803f4b90;
lbl_803f4ba0 = 0x803f4ba0;
lbl_803f4bb8 = 0x803f4bb8;
w3d_line_lines_802cc0ac = 0x802cc0ac;
w3d_line_pos_802cd26c = 0x802cd26c;
w3d_line_text_802cbf2c = 0x802cbf2c;
w3d_sink_write_802cbdf8 = 0x802cbdf8;
w3d_string_append_8020bf2c = 0x8020bf2c;
w3d_string_append_range_8020c43c = 0x8020c43c;
w3d_string_assign_8020bd38 = 0x8020bd38;
w3d_string_assign_range_8020bdf4 = 0x8020bdf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_format_8020c510 = 0x8020c510;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
w3d_string_truncate_8020c3a0 = 0x8020c3a0;
SECTIONS {
  .text.w3d_d28b_table_page_draw_800990a4 0x800990a4 : { *(.text.w3d_d28b_table_page_draw_800990a4) }
  .sdata 0x804aabc4 (NOLOAD) : {
    . = 0x0; lbl_804aabc4 = .;
    . = 0x4; lbl_804aabc8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
