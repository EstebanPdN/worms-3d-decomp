/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_card_guide_message_177)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_os_panic_802fb82c = 0x802fb82c;
w3d_str_memguidefig2_803d8888 = 0x803d8888;
w3d_str_mesg_corrupt_803d89c0 = 0x803d89c0;
w3d_str_mesg_damaged_803d8940 = 0x803d8940;
w3d_str_mesg_encoding_803d8a20 = 0x803d8a20;
w3d_str_mesg_format_failed_803d8a4c = 0x803d8a4c;
w3d_str_mesg_nocard_803d8998 = 0x803d8998;
w3d_str_mesg_nosupport_803d896c = 0x803d896c;
w3d_str_mesg_wrongdevice_803d89ec = 0x803d89ec;
SECTIONS {
  .text.w3d_card_guide_message_177 0x802c522c : { *(.text.w3d_card_guide_message_177) }
  .text.w3d_card_guide_message_by_encoding 0x802c52f0 : { *(.text.w3d_card_guide_message_by_encoding) }
  .text.w3d_card_guide_message_damaged 0x802c55e8 : { *(.text.w3d_card_guide_message_damaged) }
  .text.w3d_card_guide_message_nosupport 0x802c5668 : { *(.text.w3d_card_guide_message_nosupport) }
  .text.w3d_card_guide_message_nocard 0x802c56e8 : { *(.text.w3d_card_guide_message_nocard) }
  .text.w3d_card_guide_message_corrupt 0x802c5768 : { *(.text.w3d_card_guide_message_corrupt) }
  .text.w3d_card_guide_message_wrong_device 0x802c57e8 : { *(.text.w3d_card_guide_message_wrong_device) }
  .text.w3d_card_guide_message_encoding 0x802c5868 : { *(.text.w3d_card_guide_message_encoding) }
  .text.w3d_card_guide_message_encoding_retry 0x802c5900 : { *(.text.w3d_card_guide_message_encoding_retry) }
  .text.w3d_card_guide_message_format_failed 0x802c5984 : { *(.text.w3d_card_guide_message_format_failed) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
