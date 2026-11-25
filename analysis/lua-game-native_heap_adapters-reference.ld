/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_heap_allocate_entry_a)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_heap_allocation_file = 0x803b2e98;
SECTIONS {
  .text.w3d_heap_allocate_entry_a 0x801fe1d8 : { *(.text.w3d_heap_allocate_entry_a) }
  .text.w3d_heap_allocate_entry_b 0x801fe220 : { *(.text.w3d_heap_allocate_entry_b) }
  .text.w3d_heap_allocate_with_metadata 0x801fe268 : { *(.text.w3d_heap_allocate_with_metadata) }
  .text.w3d_heap_allocate_file_line 0x80209060 : { *(.text.w3d_heap_allocate_file_line) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
