/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29s_ranked_insert_80005a98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
free = 0x802134fc;
malloc = 0x80212fd4;
memmove = 0x802eeef4;
SECTIONS {
  .text.d29s_ranked_insert_80005a98 0x80005a98 : { *(.text.d29s_ranked_insert_80005a98) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
