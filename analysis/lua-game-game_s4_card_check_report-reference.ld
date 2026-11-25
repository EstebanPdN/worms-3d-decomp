/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_check_report)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_panic_802fb82c = 0x802fb82c;
w3d_report_802fb7ac = 0x802fb7ac;
w3d_str_803d74e4 = 0x803d74e4;
w3d_str_803d7630 = 0x803d7630;
w3d_str_803d7650 = 0x803d7650;
w3d_str_803d7674 = 0x803d7674;
w3d_str_803d7698 = 0x803d7698;
w3d_str_803d76bc = 0x803d76bc;
w3d_str_803d76e0 = 0x803d76e0;
w3d_str_803d7704 = 0x803d7704;
w3d_str_803d772c = 0x803d772c;
w3d_str_803d774c = 0x803d774c;
w3d_str_803d7768 = 0x803d7768;
w3d_str_803d7784 = 0x803d7784;
w3d_str_803d779c = 0x803d779c;
w3d_str_803d77b4 = 0x803d77b4;
w3d_str_803d77d4 = 0x803d77d4;
w3d_str_803d77f8 = 0x803d77f8;
w3d_str_803d7818 = 0x803d7818;
SECTIONS {
  .text.w3d_s4_card_check_report 0x802ae2dc : { *(.text.w3d_s4_card_check_report) }
  .sdata 0x804abc50 (NOLOAD) : {
    . = 0x0; w3d_last_state_804abc50 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
