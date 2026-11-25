/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d15a_save_table_menu_8005097c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__17D15aText_803426b8 = 0x803426b8;
w3d_d15a_bank_labels_803fcc90 = 0x803fcc90;
w3d_d15a_intro_80377f98 = 0x80377f98;
w3d_d15a_line_format_80377fe0 = 0x80377fe0;
w3d_d15a_prompt_80377fe8 = 0x80377fe8;
w3d_d15a_separator_80377fdc = 0x80377fdc;
w3d_d15a_sink_write_802cbdf8 = 0x802cbdf8;
w3d_d15a_text_append_802cbf2c = 0x802cbf2c;
w3d_d15a_text_append_lines_802cc0ac = 0x802cc0ac;
w3d_d15a_text_clear_802cd128 = 0x802cd128;
w3d_d15a_text_format_8020c510 = 0x8020c510;
w3d_d15a_text_position_802cd26c = 0x802cd26c;
w3d_d15a_text_reset_802cd220 = 0x802cd220;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d15a_save_table_menu_8005097c 0x8005097c : { *(.text.w3d_d15a_save_table_menu_8005097c) }
  .sdata 0x804aa9fc (NOLOAD) : {
    . = 0x0; w3d_d15a_bank_keys_804aa9fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
