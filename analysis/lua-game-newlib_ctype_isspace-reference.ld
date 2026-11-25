/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(isspace)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_ctype_ = 0x803db448;
SECTIONS {
  .text.isspace 0x802f31e4 : { *(.text.isspace) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
