/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_reset_range_800a5d6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a5e04 = 0x800a5e04;
SECTIONS {
  .text.s19_reset_range_800a5d6c 0x800a5d6c : { *(.text.s19_reset_range_800a5d6c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
