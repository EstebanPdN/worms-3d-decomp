/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_format_text)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
strcpy = 0x802ef2fc;
strlen = 0x802ef9c0;
strstr = 0x802efd14;
w3d_str_803cfacc = 0x803cfacc;
w3d_str_803cfae0 = 0x803cfae0;
w3d_str_803cfaf0 = 0x803cfaf0;
w3d_text_format_80343b0c = 0x80343b0c;
SECTIONS {
  .text.w3d_s4_card_format_text 0x8028a1c0 : { *(.text.w3d_s4_card_format_text) }
  .text.w3d_s4_card_replace_marker 0x8028a31c : { *(.text.w3d_s4_card_replace_marker) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
