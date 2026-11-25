/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc40a_pattern_table_8017c12c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.cc40a_pattern_table_8017c12c 0x8017c12c : { *(.text.cc40a_pattern_table_8017c12c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
