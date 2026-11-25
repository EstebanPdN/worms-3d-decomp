/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_resize_names_801920b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d24d_String_803426b8 = 0x803426b8;
d24d_fill_insert_8034cc3c = 0x8034cc3c;
d24d_string_finish_8020c5c4 = 0x8020c5c4;
d24d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d24d_resize_names_801920b8 0x801920b8 : { *(.text.d24d_resize_names_801920b8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
