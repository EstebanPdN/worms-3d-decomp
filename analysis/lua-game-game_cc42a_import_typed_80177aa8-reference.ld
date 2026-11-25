/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc42a_import_typed_80177aa8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc42a_insert_80178108 = 0x80178108;
cc42a_requiredType_80361f08 = 0x80361f08;
SECTIONS {
  .text.cc42a_import_typed_80177aa8 0x80177aa8 : { *(.text.cc42a_import_typed_80177aa8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
