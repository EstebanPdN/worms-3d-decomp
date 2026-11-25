/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26e_read_records_802029b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
insert_fill__7RecordsP6RecordUiRC6Record = 0x8035ab00;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_d26e_read_records_802029b8 0x802029b8 : { *(.text.w3d_d26e_read_records_802029b8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
