/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_read_open)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cache_invalidate_802fa95c = 0x802fa95c;
w3d_card_close_803178cc = 0x803178cc;
w3d_card_delete_80318680 = 0x80318680;
w3d_card_open_803177b0 = 0x803177b0;
w3d_card_read_803180ec = 0x803180ec;
w3d_card_status_803188c0 = 0x803188c0;
w3d_crc_check_802ad9c0 = 0x802ad9c0;
w3d_panic_802fb82c = 0x802fb82c;
w3d_report_802fb7ac = 0x802fb7ac;
w3d_str_803d6cc4 = 0x803d6cc4;
w3d_str_803d6d04 = 0x803d6d04;
w3d_str_803d6d18 = 0x803d6d18;
w3d_str_803d6d30 = 0x803d6d30;
w3d_str_803d6d48 = 0x803d6d48;
w3d_str_803d6d5c = 0x803d6d5c;
w3d_str_803d6d70 = 0x803d6d70;
w3d_str_803d6d88 = 0x803d6d88;
w3d_str_803d6db4 = 0x803d6db4;
w3d_str_803d6ddc = 0x803d6ddc;
w3d_str_803d6e00 = 0x803d6e00;
w3d_str_803d6e28 = 0x803d6e28;
SECTIONS {
  .text.w3d_s4_card_read_open 0x802ac224 : { *(.text.w3d_s4_card_read_open) }
  .text.w3d_s4_card_read_status 0x802ac2ec : { *(.text.w3d_s4_card_read_status) }
  .text.w3d_s4_card_read_transfer 0x802ac37c : { *(.text.w3d_s4_card_read_transfer) }
  .text.w3d_s4_card_read_crc 0x802ac438 : { *(.text.w3d_s4_card_read_crc) }
  .text.w3d_s4_card_read_close 0x802ac4bc : { *(.text.w3d_s4_card_read_close) }
  .text.w3d_s4_card_read_delete 0x802ac564 : { *(.text.w3d_s4_card_read_delete) }
  .text.w3d_s4_card_read_corrupt_message 0x802ac600 : { *(.text.w3d_s4_card_read_corrupt_message) }
  .text.w3d_s4_card_read_missing_message 0x802ac668 : { *(.text.w3d_s4_card_read_missing_message) }
  .text.w3d_s4_card_read_done_message 0x802ac6ec : { *(.text.w3d_s4_card_read_done_message) }
  .text.w3d_s4_card_read_failed_message 0x802ac74c : { *(.text.w3d_s4_card_read_failed_message) }
  .text.w3d_s4_card_read_ready_message 0x802ac7b0 : { *(.text.w3d_s4_card_read_ready_message) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
