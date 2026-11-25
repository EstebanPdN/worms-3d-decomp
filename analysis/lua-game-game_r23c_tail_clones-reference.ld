/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(r23c_indexed_entry_80349bc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.r23c_indexed_entry_80349bc8 0x80349bc8 : { *(.text.r23c_indexed_entry_80349bc8) }
  .text.r23c_row_entry_80349f58 0x80349f58 : { *(.text.r23c_row_entry_80349f58) }
  .text.r23c_row_value_8034a068 0x8034a068 : { *(.text.r23c_row_value_8034a068) }
  .text.r23c_set_high_flag_8034a110 0x8034a110 : { *(.text.r23c_set_high_flag_8034a110) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
