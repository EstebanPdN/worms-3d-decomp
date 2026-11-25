/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10b_filter_property_text_80271348)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10b_edit_color_80279f54 = 0x80279f54;
d10b_edit_float_8027a2c4 = 0x8027a2c4;
d10b_edit_integer_8027a248 = 0x8027a248;
d10b_edit_name_8027a8a4 = 0x8027a8a4;
d10b_edit_string_802796d4 = 0x802796d4;
d10b_edit_vector_80279dc0 = 0x80279dc0;
SECTIONS {
  .text.d10b_filter_property_text_80271348 0x80271348 : { *(.text.d10b_filter_property_text_80271348) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
