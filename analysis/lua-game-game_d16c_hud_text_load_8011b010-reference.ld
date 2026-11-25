/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16c_hud_text_load_8011b010)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d16c_String_8020bb54PCc = 0x8020bb54;
d16c_as_font_8034435c = 0x8034435c;
d16c_as_text_80343580 = 0x80343580;
d16c_backing_green_8039ae90 = 0x8039ae90;
d16c_font_name_8039ae88 = 0x8039ae88;
d16c_font_set_scale_8018bb28 = 0x8018bb28;
d16c_handle_load_8015adf4 = 0x8015adf4;
d16c_service_lookup_8015ae3c = 0x8015ae3c;
d16c_string_finish_8020c5c4 = 0x8020c5c4;
d16c_string_release_80341588 = 0x80341588;
d16c_text_set_font_8018dfa0 = 0x8018dfa0;
SECTIONS {
  .text.d16c_hud_text_load_8011b010 0x8011b010 : { *(.text.d16c_hud_text_load_8011b010) }
  .rodata 0x8039aea4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
