/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(zcalloc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
calloc = 0x80213c30;
free = 0x802134fc;
SECTIONS {
  .text.zcalloc 0x802c8a10 : { *(.text.zcalloc) }
  .text.zcfree 0x802c8a38 : { *(.text.zcfree) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
