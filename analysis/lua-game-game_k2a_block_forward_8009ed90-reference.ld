/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_block_forward_8009ed90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8009ea38 = 0x8009ea38;
SECTIONS {
  .text.k2a_block_forward_8009ed90 0x8009ed90 : { *(.text.k2a_block_forward_8009ed90) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
