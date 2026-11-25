/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_save_step)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcpy = 0x802ef2fc;
w3d_cache_flush_802fa988 = 0x802fa988;
w3d_card_close_803178cc = 0x803178cc;
w3d_card_create_80317c78 = 0x80317c78;
w3d_card_delete_80318680 = 0x80318680;
w3d_card_open_803177b0 = 0x803177b0;
w3d_card_rename_80318d8c = 0x80318d8c;
w3d_card_status_803188c0 = 0x803188c0;
w3d_card_write_80318468 = 0x80318468;
w3d_checksum_802ad978 = 0x802ad978;
w3d_fn_802ad0d4 = 0x802ad0d4;
w3d_fn_802ad6b8 = 0x802ad6b8;
w3d_format_802ec254 = 0x802ec254;
w3d_panic_802fb82c = 0x802fb82c;
w3d_report_802fb7ac = 0x802fb7ac;
w3d_str_803d7054 = 0x803d7054;
w3d_str_803d706c = 0x803d706c;
w3d_str_803d70b8 = 0x803d70b8;
w3d_str_803d70c0 = 0x803d70c0;
w3d_str_803d70d4 = 0x803d70d4;
w3d_str_803d70ec = 0x803d70ec;
w3d_str_803d7100 = 0x803d7100;
w3d_str_803d7118 = 0x803d7118;
w3d_str_803d712c = 0x803d712c;
w3d_str_803d7140 = 0x803d7140;
w3d_str_803d7154 = 0x803d7154;
w3d_str_803d7180 = 0x803d7180;
w3d_str_803d71a8 = 0x803d71a8;
w3d_str_803d71d0 = 0x803d71d0;
w3d_str_803d71f8 = 0x803d71f8;
SECTIONS {
  .text.w3d_s4_card_save_step 0x802aca28 : { *(.text.w3d_s4_card_save_step) }
  .text.w3d_s4_card_save_begin 0x802acc68 : { *(.text.w3d_s4_card_save_begin) }
  .text.w3d_s4_card_save_open 0x802acd20 : { *(.text.w3d_s4_card_save_open) }
  .text.w3d_s4_card_save_create 0x802acde8 : { *(.text.w3d_s4_card_save_create) }
  .text.w3d_s4_card_save_status 0x802aceb8 : { *(.text.w3d_s4_card_save_status) }
  .text.w3d_s4_card_save_write_new 0x802acf74 : { *(.text.w3d_s4_card_save_write_new) }
  .text.w3d_s4_card_save_write_old 0x802ad024 : { *(.text.w3d_s4_card_save_write_old) }
  .text.w3d_s4_card_save_close_new 0x802ad254 : { *(.text.w3d_s4_card_save_close_new) }
  .text.w3d_s4_card_save_delete_old 0x802ad2dc : { *(.text.w3d_s4_card_save_delete_old) }
  .text.w3d_s4_card_save_rename 0x802ad360 : { *(.text.w3d_s4_card_save_rename) }
  .text.w3d_s4_card_save_close_old 0x802ad3f0 : { *(.text.w3d_s4_card_save_close_old) }
  .text.w3d_s4_card_save_overwrite_message 0x802ad48c : { *(.text.w3d_s4_card_save_overwrite_message) }
  .text.w3d_s4_card_save_done_message 0x802ad510 : { *(.text.w3d_s4_card_save_done_message) }
  .text.w3d_s4_card_save_ready_message 0x802ad570 : { *(.text.w3d_s4_card_save_ready_message) }
  .text.w3d_s4_card_save_failed_message 0x802ad5d4 : { *(.text.w3d_s4_card_save_failed_message) }
  .text.w3d_s4_card_save_damaged_message 0x802ad638 : { *(.text.w3d_s4_card_save_damaged_message) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
