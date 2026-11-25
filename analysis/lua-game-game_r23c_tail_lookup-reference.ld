/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(r23c_indexed_entry_803486f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.r23c_indexed_entry_803486f0 0x803486f0 : { *(.text.r23c_indexed_entry_803486f0) }
  .text.r23c_row_entry_80348c64 0x80348c64 : { *(.text.r23c_row_entry_80348c64) }
  .text.r23c_row_value_80348d74 0x80348d74 : { *(.text.r23c_row_value_80348d74) }
  .text.r23c_lower_bound_8035c4d0 0x8035c4d0 : { *(.text.r23c_lower_bound_8035c4d0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
