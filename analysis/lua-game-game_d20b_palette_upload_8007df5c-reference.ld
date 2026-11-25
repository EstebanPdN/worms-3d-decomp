/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20b_palette_upload_8007df5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d20b_array_reserve_801ef048 = 0x801ef048;
d20b_as_value_80342fa4 = 0x80342fa4;
d20b_set_vector_80178fa4 = 0x80178fa4;
SECTIONS {
  .text.d20b_palette_upload_8007df5c 0x8007df5c : { *(.text.d20b_palette_upload_8007df5c) }
  .rodata 0x8037ce98 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
