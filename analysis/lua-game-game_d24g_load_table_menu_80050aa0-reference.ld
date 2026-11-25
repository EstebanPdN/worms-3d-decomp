/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_load_table_menu_80050aa0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Text = 0x803426b8;
labels_803fcc90 = 0x803fcc90;
s_80377fdc = 0x80377fdc;
s_80377fe0 = 0x80377fe0;
s_80378020 = 0x80378020;
s_80378064 = 0x80378064;
s_803780b4 = 0x803780b4;
s_803780d4 = 0x803780d4;
s_803780f4 = 0x803780f4;
sink_write_802cbdf8 = 0x802cbdf8;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
text_append_802cbf2c = 0x802cbf2c;
text_clear_802cd128 = 0x802cd128;
text_format_8020c510 = 0x8020c510;
text_lines_802cc0ac = 0x802cc0ac;
text_position_802cd26c = 0x802cd26c;
text_reset_802cd220 = 0x802cd220;
SECTIONS {
  .text.w3d_d24g_load_table_menu_80050aa0 0x80050aa0 : { *(.text.w3d_d24g_load_table_menu_80050aa0) }
  .sdata 0x804aa9fc (NOLOAD) : {
    . = 0x0; keys_804aa9fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
