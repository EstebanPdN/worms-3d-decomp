/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_text_list_reset)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_80179170 = 0x80179170;
w3d_auto_80296518 = 0x80296518;
w3d_empty_80343744 = 0x80343744;
w3d_list_apply_active_8029fc78 = 0x8029fc78;
w3d_list_flags_802a0e20 = 0x802a0e20;
w3d_list_reset_802b0fec = 0x802b0fec;
w3d_list_set_active_802b0990 = 0x802b0990;
w3d_text_list_clear_8029f48c = 0x8029f48c;
SECTIONS {
  .text.w3d_s4_text_list_reset 0x8029ea40 : { *(.text.w3d_s4_text_list_reset) }
  .text.w3d_s4_text_list_refresh_value 0x8029fbb8 : { *(.text.w3d_s4_text_list_refresh_value) }
  .text.w3d_s4_text_list_set_active 0x8029fc08 : { *(.text.w3d_s4_text_list_set_active) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
