/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_adjust_heap_803515ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_803515a0 = 0x803515a0;
w3d_auto_803518f8 = 0x803518f8;
SECTIONS {
  .text.w3d_adjust_heap_803515ac 0x803515ac : { *(.text.w3d_adjust_heap_803515ac) }
  .text.w3d_make_heap_80351710 0x80351710 : { *(.text.w3d_make_heap_80351710) }
  .text.w3d_pop_heap_803517a4 0x803517a4 : { *(.text.w3d_pop_heap_803517a4) }
  .text.w3d_partial_sort_80351804 0x80351804 : { *(.text.w3d_partial_sort_80351804) }
  .text.w3d_unguarded_partition_80351928 0x80351928 : { *(.text.w3d_unguarded_partition_80351928) }
  .text.w3d_introsort_loop_803519dc 0x803519dc : { *(.text.w3d_introsort_loop_803519dc) }
  .text.w3d_unguarded_linear_insert_80351b34 0x80351b34 : { *(.text.w3d_unguarded_linear_insert_80351b34) }
  .text.w3d_insertion_sort_80351b9c 0x80351b9c : { *(.text.w3d_insertion_sort_80351b9c) }
  .text.w3d_unguarded_insertion_sort_80351c74 0x80351c74 : { *(.text.w3d_unguarded_insertion_sort_80351c74) }
  .text.w3d_final_insertion_sort_80351cdc 0x80351cdc : { *(.text.w3d_final_insertion_sort_80351cdc) }
  .text.w3d_sort_80351d58 0x80351d58 : { *(.text.w3d_sort_80351d58) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
