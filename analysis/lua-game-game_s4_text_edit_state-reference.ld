/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_text_edit_set_active)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_editor_refresh_802a21ec = 0x802a21ec;
w3d_list_activate_8029fc08 = 0x8029fc08;
w3d_list_refresh_8029fbb8 = 0x8029fbb8;
w3d_sound_play_802b1258 = 0x802b1258;
SECTIONS {
  .text.w3d_s4_text_edit_set_active 0x802a26b4 : { *(.text.w3d_s4_text_edit_set_active) }
  .text.w3d_s4_text_edit_refresh_value 0x802a2768 : { *(.text.w3d_s4_text_edit_refresh_value) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
