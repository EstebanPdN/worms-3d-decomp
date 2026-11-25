/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_choice_next)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178d1c = 0x80178d1c;
w3d_choice_apply_802a70fc = 0x802a70fc;
w3d_choice_cursor_802a73d4 = 0x802a73d4;
w3d_choice_edge_802b22b0 = 0x802b22b0;
w3d_choice_refresh_802a77a4 = 0x802a77a4;
w3d_choice_update_802a6ce8 = 0x802a6ce8;
w3d_constructor_native_cast = 0x80342a78;
w3d_empty_803426b4 = 0x803426b4;
w3d_f32_803d6180 = 0x803d6180;
w3d_f32_803d6184 = 0x803d6184;
SECTIONS {
  .text.w3d_s4_choice_next 0x802a6e3c : { *(.text.w3d_s4_choice_next) }
  .text.w3d_s4_choice_previous 0x802a6ee4 : { *(.text.w3d_s4_choice_previous) }
  .text.w3d_s4_choice_update_selection 0x802a7490 : { *(.text.w3d_s4_choice_update_selection) }
  .text.w3d_s4_choice_cursor_changed 0x802a7500 : { *(.text.w3d_s4_choice_cursor_changed) }
  .text.w3d_s4_choice_selection_changed 0x802a7550 : { *(.text.w3d_s4_choice_selection_changed) }
  .text.w3d_s4_choice_refresh_changed 0x802a75a0 : { *(.text.w3d_s4_choice_refresh_changed) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
