/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__srget)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__srefill = 0x802ec088;
SECTIONS {
  .text.__srget 0x802ec1fc : { *(.text.__srget) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
