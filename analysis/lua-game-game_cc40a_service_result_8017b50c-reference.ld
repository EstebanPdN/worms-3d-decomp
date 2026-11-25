/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc40a_service_result_8017b50c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc40a_lookupService_8020b680 = 0x8020b680;
cc40a_serviceKey_804164c0 = 0x804164c0;
SECTIONS {
  .text.cc40a_service_result_8017b50c 0x8017b50c : { *(.text.cc40a_service_result_8017b50c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
