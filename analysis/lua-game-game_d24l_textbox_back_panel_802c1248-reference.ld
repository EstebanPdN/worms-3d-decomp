/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_textbox_back_panel_802c1248)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lStringPCc = 0x8020bb54;
w3d_as_mesh_8034357c = 0x8034357c;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_mesh_set_colour_80173df0 = 0x80173df0;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d24l_textbox_back_panel_802c1248 0x802c1248 : { *(.text.d24l_textbox_back_panel_802c1248) }
  .rodata 0x803d84d4 : { *(.rodata) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; w3d_resource_base_804abb60 = .;
    . = 0x5508; w3d_message_804b1068 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
