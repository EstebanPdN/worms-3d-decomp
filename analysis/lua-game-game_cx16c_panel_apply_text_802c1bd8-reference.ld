/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_panel_apply_text_802c1bd8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_notify_802c14fc = 0x802c14fc;
cx16c_refresh_802c17bc = 0x802c17bc;
cx16c_set_text_802c196c = 0x802c196c;
cx16c_string_finish_8020c5c4 = 0x8020c5c4;
cx16c_string_header_80341884 = 0x80341884;
cx16c_string_init_8020c5c0 = 0x8020c5c0;
cx16c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_cx16c_panel_apply_text_802c1bd8 0x802c1bd8 : { *(.text.w3d_cx16c_panel_apply_text_802c1bd8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
