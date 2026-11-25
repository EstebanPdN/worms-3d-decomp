/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_card_guide_step)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_card_guide_check = 0x802c5404;
w3d_card_guide_format = 0x802c54d4;
w3d_card_guide_message_177 = 0x802c522c;
w3d_card_guide_message_by_encoding = 0x802c52f0;
w3d_card_guide_message_corrupt = 0x802c5768;
w3d_card_guide_message_damaged = 0x802c55e8;
w3d_card_guide_message_encoding = 0x802c5868;
w3d_card_guide_message_encoding_retry = 0x802c5900;
w3d_card_guide_message_format_failed = 0x802c5984;
w3d_card_guide_message_nocard = 0x802c56e8;
w3d_card_guide_message_nosupport = 0x802c5668;
w3d_card_guide_message_wrong_device = 0x802c57e8;
w3d_card_guide_mount = 0x802c5314;
w3d_card_guide_probe = 0x802c5238;
w3d_card_guide_show_message_802c59e8 = 0x802c59e8;
w3d_card_guide_unformat = 0x802c556c;
w3d_os_panic_802fb82c = 0x802fb82c;
w3d_str_illegal_state_803d88a0 = 0x803d88a0;
w3d_str_memguidefig2_803d8888 = 0x803d8888;
SECTIONS {
  .text.w3d_card_guide_step 0x802c501c : { *(.text.w3d_card_guide_step) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
