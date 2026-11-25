/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_slot_table_resize_8015cf14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_allocate_entry_b = 0x801fe220;
w3d_slot_table_reset_8015cfa0 = 0x8015cfa0;
w3d_task_array_release = 0x801fe240;
SECTIONS {
  .text.w3d_k2b_slot_table_resize_8015cf14 0x8015cf14 : { *(.text.w3d_k2b_slot_table_resize_8015cf14) }
  .rodata 0x803a4418 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
