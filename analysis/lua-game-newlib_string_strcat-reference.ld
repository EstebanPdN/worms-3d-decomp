/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(strcat)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcpy = 0x802ef2fc;
SECTIONS {
  .text.strcat 0x802ef108 : { *(.text.strcat) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
