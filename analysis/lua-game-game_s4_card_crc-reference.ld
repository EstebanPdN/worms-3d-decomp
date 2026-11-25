/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_save_report)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_crc_table_80471980 = 0x80471980;
w3d_panic_802fb82c = 0x802fb82c;
w3d_report_802fb7ac = 0x802fb7ac;
w3d_str_803d7054 = 0x803d7054;
w3d_str_803d7224 = 0x803d7224;
w3d_str_803d7244 = 0x803d7244;
w3d_str_803d7268 = 0x803d7268;
w3d_str_803d728c = 0x803d728c;
w3d_str_803d72b0 = 0x803d72b0;
w3d_str_803d72d4 = 0x803d72d4;
w3d_str_803d72f8 = 0x803d72f8;
w3d_str_803d731c = 0x803d731c;
w3d_str_803d7340 = 0x803d7340;
w3d_str_803d7360 = 0x803d7360;
w3d_str_803d7384 = 0x803d7384;
w3d_str_803d73a8 = 0x803d73a8;
w3d_str_803d73c0 = 0x803d73c0;
w3d_str_803d73dc = 0x803d73dc;
w3d_str_803d73f4 = 0x803d73f4;
w3d_str_803d7418 = 0x803d7418;
w3d_str_803d7434 = 0x803d7434;
w3d_str_803d7454 = 0x803d7454;
w3d_str_803d7474 = 0x803d7474;
SECTIONS {
  .text.w3d_s4_card_save_report 0x802ad6b8 : { *(.text.w3d_s4_card_save_report) }
  .text.w3d_s4_crc_initialize 0x802ad924 : { *(.text.w3d_s4_crc_initialize) }
  .text.w3d_s4_crc_compute 0x802ad978 : { *(.text.w3d_s4_crc_compute) }
  .sdata 0x804abc48 (NOLOAD) : {
    . = 0x0; w3d_last_state_804abc48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
