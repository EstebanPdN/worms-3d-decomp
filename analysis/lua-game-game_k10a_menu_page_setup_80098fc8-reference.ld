/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_menu_page_setup_80098fc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800990a4 = 0x800990a4;
fn_800994b4 = 0x800994b4;
w3d_auto_802cbf2c = 0x802cbf2c;
w3d_auto_802cd128 = 0x802cd128;
w3d_pieces_803f4b90 = 0x803f4b90;
w3d_s21_repeat_request_802cd220 = 0x802cd220;
w3d_s21_sink_write_indexed_802cbdf8 = 0x802cbdf8;
w3d_show_options_line_80099998 = 0x80099998;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k10a_menu_page_setup_80098fc8 0x80098fc8 : { *(.text.w3d_k10a_menu_page_setup_80098fc8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
