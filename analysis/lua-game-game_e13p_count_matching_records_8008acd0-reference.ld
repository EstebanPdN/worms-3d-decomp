/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_count_matching_records_8008acd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_record_at_800fc7f8 = 0x800fc7f8;
SECTIONS {
  .text.w3d_count_matching_records_8008acd0 0x8008acd0 : { *(.text.w3d_count_matching_records_8008acd0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
