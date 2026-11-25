/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_check_step)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcpy = 0x802ef2fc;
w3d_card_delete_80318680 = 0x80318680;
w3d_card_free_8031499c = 0x8031499c;
w3d_card_open_803177b0 = 0x803177b0;
w3d_card_rename_80318d8c = 0x80318d8c;
w3d_card_status_803188c0 = 0x803188c0;
w3d_fn_802ae2dc = 0x802ae2dc;
w3d_format_802ec254 = 0x802ec254;
w3d_panic_802fb82c = 0x802fb82c;
w3d_report_802fb7ac = 0x802fb7ac;
w3d_str_803d74e4 = 0x803d74e4;
w3d_str_803d74fc = 0x803d74fc;
w3d_str_803d7524 = 0x803d7524;
w3d_str_803d752c = 0x803d752c;
w3d_str_803d7540 = 0x803d7540;
w3d_str_803d7558 = 0x803d7558;
w3d_str_803d7570 = 0x803d7570;
w3d_str_803d7588 = 0x803d7588;
w3d_str_803d759c = 0x803d759c;
w3d_str_803d75b4 = 0x803d75b4;
w3d_str_803d75dc = 0x803d75dc;
w3d_str_803d7604 = 0x803d7604;
SECTIONS {
  .text.w3d_s4_card_check_step 0x802ada18 : { *(.text.w3d_s4_card_check_step) }
  .text.w3d_s4_card_check_begin 0x802adbf8 : { *(.text.w3d_s4_card_check_begin) }
  .text.w3d_s4_card_check_open_old 0x802adc54 : { *(.text.w3d_s4_card_check_open_old) }
  .text.w3d_s4_card_check_open_temp 0x802add04 : { *(.text.w3d_s4_card_check_open_temp) }
  .text.w3d_s4_card_check_status 0x802addd8 : { *(.text.w3d_s4_card_check_status) }
  .text.w3d_s4_card_check_delete_old 0x802ade80 : { *(.text.w3d_s4_card_check_delete_old) }
  .text.w3d_s4_card_check_restore 0x802adf1c : { *(.text.w3d_s4_card_check_restore) }
  .text.w3d_s4_card_check_delete_temp 0x802adfc8 : { *(.text.w3d_s4_card_check_delete_temp) }
  .text.w3d_s4_card_check_space 0x802ae064 : { *(.text.w3d_s4_card_check_space) }
  .text.w3d_s4_card_check_delete_message 0x802ae148 : { *(.text.w3d_s4_card_check_delete_message) }
  .text.w3d_s4_card_check_space_message 0x802ae1ac : { *(.text.w3d_s4_card_check_space_message) }
  .text.w3d_s4_card_check_initial_space_message 0x802ae244 : { *(.text.w3d_s4_card_check_initial_space_message) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
