/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_text_list_remove_box)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_label_destroy_8025e0c4 = 0x8025e0c4;
w3d_list_apply_8029fc78 = 0x8029fc78;
w3d_scroll_destroy_80293528 = 0x80293528;
SECTIONS {
  .text.w3d_s4_text_list_remove_box 0x802a0664 : { *(.text.w3d_s4_text_list_remove_box) }
  .text.w3d_s4_text_list_clear_labels 0x802a0e20 : { *(.text.w3d_s4_text_list_clear_labels) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
