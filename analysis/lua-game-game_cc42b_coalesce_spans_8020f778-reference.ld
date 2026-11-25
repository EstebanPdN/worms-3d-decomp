/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc42b_coalesce_spans_8020f778)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc42b_remove_span_8020f8ac = 0x8020f8ac;
SECTIONS {
  .text.cc42b_coalesce_spans_8020f778 0x8020f778 : { *(.text.cc42b_coalesce_spans_8020f778) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
