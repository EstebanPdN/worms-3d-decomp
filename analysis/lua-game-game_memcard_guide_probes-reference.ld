/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_card_guide_probe)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_card_check_80316150 = 0x80316150;
w3d_card_format_80317438 = 0x80317438;
w3d_card_guide_80368bd8 = 0x80368bd8;
w3d_card_mount_80316b0c = 0x80316b0c;
w3d_card_probe_ex_803162a8 = 0x803162a8;
w3d_card_unformat_80316bf0 = 0x80316bf0;
w3d_os_report_802fb7ac = 0x802fb7ac;
w3d_str_card_check_803d8900 = 0x803d8900;
w3d_str_card_format_803d8914 = 0x803d8914;
w3d_str_card_mount_803d88ec = 0x803d88ec;
w3d_str_card_probe_ex_803d88c0 = 0x803d88c0;
w3d_str_card_unformat_803d8928 = 0x803d8928;
w3d_str_unexpected_error_803d88d4 = 0x803d88d4;
SECTIONS {
  .text.w3d_card_guide_probe 0x802c5238 : { *(.text.w3d_card_guide_probe) }
  .text.w3d_card_guide_mount 0x802c5314 : { *(.text.w3d_card_guide_mount) }
  .text.w3d_card_guide_check 0x802c5404 : { *(.text.w3d_card_guide_check) }
  .text.w3d_card_guide_format 0x802c54d4 : { *(.text.w3d_card_guide_format) }
  .text.w3d_card_guide_unformat 0x802c556c : { *(.text.w3d_card_guide_unformat) }
  .text.w3d_card_guide_get 0x802c5c18 : { *(.text.w3d_card_guide_get) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
