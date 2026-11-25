/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d18f_progress_layout_8028c290)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13Text_803426b8 = 0x803426b8;
border_key_803cfdc0 = 0x803cfdc0;
percentage_format_803cfde4 = 0x803cfde4;
read_float_800fc270 = 0x800fc270;
string_base_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
text_assign_8018c5b0 = 0x8018c5b0;
text_cast_80343580 = 0x80343580;
text_format_8020c510 = 0x8020c510;
text_height_8018ca14 = 0x8018ca14;
text_width_8018c8bc = 0x8018c8bc;
update_box_8028c8e4 = 0x8028c8e4;
SECTIONS {
  .text.d18f_progress_layout_8028c290 0x8028c290 : { *(.text.d18f_progress_layout_8028c290) }
  .rodata 0x803cfdf0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
