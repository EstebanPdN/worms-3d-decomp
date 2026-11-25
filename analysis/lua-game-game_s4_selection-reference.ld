/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_selection_reset)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178d1c = 0x80178d1c;
w3d_constructor_native_cast = 0x80342a78;
w3d_empty_803426b4 = 0x803426b4;
w3d_selection_activate_802b0990 = 0x802b0990;
w3d_selection_base_reset_802b0fec = 0x802b0fec;
w3d_selection_clear_80285ee0 = 0x80285ee0;
w3d_selection_edge_802b22b0 = 0x802b22b0;
w3d_selection_highlight_80286b40 = 0x80286b40;
w3d_selection_name_802b1258 = 0x802b1258;
w3d_selection_visibility_802870fc = 0x802870fc;
SECTIONS {
  .text.w3d_s4_selection_reset 0x80285c9c : { *(.text.w3d_s4_selection_reset) }
  .text.w3d_s4_selection_set_active 0x80286050 : { *(.text.w3d_s4_selection_set_active) }
  .text.w3d_s4_selection_value_changed 0x80286d14 : { *(.text.w3d_s4_selection_value_changed) }
  .text.w3d_s4_selection_navigate 0x80286da4 : { *(.text.w3d_s4_selection_navigate) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
