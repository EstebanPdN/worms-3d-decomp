/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc41a_import_records_8017c9f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc41a_copy_80174274 = 0x80174274;
cc41a_definitions_80456f14 = 0x80456f14;
cc41a_insert_8017c464 = 0x8017c464;
cc41a_key_80412110 = 0x80412110;
cc41a_service_8020b680 = 0x8020b680;
SECTIONS {
  .text.cc41a_import_records_8017c9f4 0x8017c9f4 : { *(.text.cc41a_import_records_8017c9f4) }
  .sdata 0x804ab5e8 (NOLOAD) : {
    . = 0x0; cc41a_peak_804ab5e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
