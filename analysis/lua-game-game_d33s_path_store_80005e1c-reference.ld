/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(store_path__14D33sPathSearch)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
free = 0x802134fc;
malloc = 0x80212fd4;
memmove = 0x802eeef4;
w3d_path_table_erase = 0x8000553c;
w3d_path_table_find = 0x800052d4;
SECTIONS {
  .text.store_path__14D33sPathSearch 0x80005e1c : { *(.text.store_path__14D33sPathSearch) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
