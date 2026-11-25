/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_frontend_register)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_control_activate_802b0990 = 0x802b0990;
w3d_control_reset_802b0fec = 0x802b0fec;
w3d_descriptor_8040e5c8 = 0x8040e5c8;
w3d_panel_refresh_802a520c = 0x802a520c;
w3d_register_80200a70 = 0x80200a70;
w3d_registry_80471144 = 0x80471144;
w3d_sound_play_802b1258 = 0x802b1258;
w3d_storage_80471140 = 0x80471140;
w3d_str_803d2e60 = 0x803d2e60;
SECTIONS {
  .text.w3d_s4_frontend_register 0x802a3d64 : { *(.text.w3d_s4_frontend_register) }
  .text.w3d_s4_panel_clear_container 0x802a4f98 : { *(.text.w3d_s4_panel_clear_container) }
  .text.w3d_s4_panel_set_active 0x802a511c : { *(.text.w3d_s4_panel_set_active) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
