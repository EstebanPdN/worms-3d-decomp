/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_adjust_heap_803539f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_adjust_heap_803539f8 0x803539f8 : { *(.text.w3d_adjust_heap_803539f8) }
  .text.w3d_make_heap_80353ad0 0x80353ad0 : { *(.text.w3d_make_heap_80353ad0) }
  .text.w3d_pop_heap_80353b54 0x80353b54 : { *(.text.w3d_pop_heap_80353b54) }
  .text.w3d_partial_sort_80353b9c 0x80353b9c : { *(.text.w3d_partial_sort_80353b9c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
