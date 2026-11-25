/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38p_resolve_import_full_80177be8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38p_insert_80178108 = 0x80178108;
cc38p_requiredType_80361f08 = 0x80361f08;
cc38p_resolve_8020b6e8 = 0x8020b6e8;
SECTIONS {
  .text.cc38p_resolve_import_full_80177be8 0x80177be8 : { *(.text.cc38p_resolve_import_full_80177be8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
