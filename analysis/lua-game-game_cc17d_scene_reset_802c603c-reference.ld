/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17d_node_reset_802c603c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_803d8d18 = 0x803d8d18;
w3d_f32_803d8dec = 0x803d8dec;
w3d_handle_set_name = 0x8015adf4;
w3d_str_803d8d10 = 0x803d8d10;
w3d_str_803d8de4 = 0x803d8de4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_cc17d_node_reset_802c603c 0x802c603c : { *(.text.w3d_cc17d_node_reset_802c603c) }
  .text.w3d_cc17d_node_reset_802c6f64 0x802c6f64 : { *(.text.w3d_cc17d_node_reset_802c6f64) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
