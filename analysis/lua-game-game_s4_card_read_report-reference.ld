/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_read_report)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_panic_802fb82c = 0x802fb82c;
w3d_report_802fb7ac = 0x802fb7ac;
w3d_str_803d6cc4 = 0x803d6cc4;
w3d_str_803d6e4c = 0x803d6e4c;
w3d_str_803d6e6c = 0x803d6e6c;
w3d_str_803d6e88 = 0x803d6e88;
w3d_str_803d6ea8 = 0x803d6ea8;
w3d_str_803d6ecc = 0x803d6ecc;
w3d_str_803d6ee8 = 0x803d6ee8;
w3d_str_803d6f0c = 0x803d6f0c;
w3d_str_803d6f2c = 0x803d6f2c;
w3d_str_803d6f4c = 0x803d6f4c;
w3d_str_803d6f64 = 0x803d6f64;
w3d_str_803d6f80 = 0x803d6f80;
w3d_str_803d6f9c = 0x803d6f9c;
w3d_str_803d6fb4 = 0x803d6fb4;
w3d_str_803d6fd8 = 0x803d6fd8;
w3d_str_803d6ff8 = 0x803d6ff8;
w3d_str_803d7014 = 0x803d7014;
w3d_str_803d7034 = 0x803d7034;
SECTIONS {
  .text.w3d_s4_card_read_report 0x802ac814 : { *(.text.w3d_s4_card_read_report) }
  .sdata 0x804abc40 (NOLOAD) : {
    . = 0x0; w3d_last_state_804abc40 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
