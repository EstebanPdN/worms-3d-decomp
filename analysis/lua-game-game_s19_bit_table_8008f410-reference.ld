/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_build_bit_table_8008f410)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_build_bit_table_8008f410 0x8008f410 : { *(.text.s19_build_bit_table_8008f410) }
  .sdata 0x804b1800 (NOLOAD) : {
    . = 0x0; lbl_804b1800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
