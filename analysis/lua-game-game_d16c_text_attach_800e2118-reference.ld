/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16c_text_attach_800e2118)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d16c_String_8020bb54PCc = 0x8020bb54;
d16c_handle_load_8015adf4 = 0x8015adf4;
d16c_null_text_80389efc = 0x80389efc;
d16c_string_finish_8020c5c4 = 0x8020c5c4;
d16c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d16c_text_attach_800e2118 0x800e2118 : { *(.text.d16c_text_attach_800e2118) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
