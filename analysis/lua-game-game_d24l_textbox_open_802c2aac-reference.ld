/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_textbox_open_802c2aac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__19D24lString_8020bb54PCc = 0x8020bb54;
w3d_as_mesh_8034357c = 0x8034357c;
w3d_cx12b_focus_dispatch_802c3ff0 = 0x802c3ff0;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_mesh_set_colour_80173df0 = 0x80173df0;
w3d_setup_cursor_802c4840 = 0x802c4840;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_textbox_caption_802c459c = 0x802c459c;
w3d_textbox_layout_802c2dc4 = 0x802c2dc4;
w3d_textbox_reset_802c2c10 = 0x802c2c10;
SECTIONS {
  .text.d24l_textbox_open_802c2aac 0x802c2aac : { *(.text.d24l_textbox_open_802c2aac) }
  .rodata 0x803d85c8 : { *(.rodata) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; w3d_resource_base_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
