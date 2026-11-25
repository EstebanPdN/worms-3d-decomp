/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol32b_erase_entry_801af48c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
finish_string_8020c5c4 = 0x8020c5c4;
release_header_8020bb2c = 0x8020bb2c;
release_string_80341588 = 0x80341588;
SECTIONS {
  .text.sol32b_erase_entry_801af48c 0x801af48c : { *(.text.sol32b_erase_entry_801af48c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
