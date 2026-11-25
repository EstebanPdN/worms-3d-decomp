/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33b_item_info_80099dc0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
free = 0x802134fc;
lbl_8037ff9c = 0x8037ff9c;
lbl_803f4bd0 = 0x803f4bd0;
malloc = 0x80212fd4;
w3d_dtor_node_8020d36c = 0x8020d36c;
w3d_line_begin_802cd220 = 0x802cd220;
w3d_line_clear_802cd128 = 0x802cd128;
w3d_line_lines_802cc0ac = 0x802cc0ac;
w3d_line_pos_802cd26c = 0x802cd26c;
w3d_line_text_802cbf2c = 0x802cbf2c;
w3d_registry_retain_8020d2b8 = 0x8020d2b8;
w3d_sink_write_802cbdf8 = 0x802cbdf8;
w3d_strchr_802ef198 = 0x802ef198;
w3d_string_assign_range_8020bdf4 = 0x8020bdf4;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_format_8020c510 = 0x8020c510;
w3d_string_free_header_8020bb2c = 0x8020bb2c;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
w3d_string_truncate_8020c3a0 = 0x8020c3a0;
w3d_tagged_construct_8020d318 = 0x8020d318;
SECTIONS {
  .text.d33b_item_info_80099dc0 0x80099dc0 : { *(.text.d33b_item_info_80099dc0) }
  .sdata 0x804aabd0 (NOLOAD) : {
    . = 0x0; lbl_804aabd0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
