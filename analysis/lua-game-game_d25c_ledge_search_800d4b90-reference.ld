/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_ledge_search_800d4b90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
prepare_800d4e3c = 0x800d4e3c;
quarter_pi_80388d38 = 0x80388d38;
test_800d4cec = 0x800d4cec;
SECTIONS {
  .text.d25c_ledge_search_800d4b90 0x800d4b90 : { *(.text.d25c_ledge_search_800d4b90) }
  .rodata 0x80388d40 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
