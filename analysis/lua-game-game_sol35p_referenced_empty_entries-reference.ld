/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35p_empty_8030af30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.sol35p_empty_8030af30 0x8030af30 : { *(.text.sol35p_empty_8030af30) }
  .text.sol35p_empty_80323714 0x80323714 : { *(.text.sol35p_empty_80323714) }
  .text.sol35p_empty_80331924 0x80331924 : { *(.text.sol35p_empty_80331924) }
  .text.sol35p_empty_803347bc 0x803347bc : { *(.text.sol35p_empty_803347bc) }
  .text.sol35p_empty_80334998 0x80334998 : { *(.text.sol35p_empty_80334998) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
