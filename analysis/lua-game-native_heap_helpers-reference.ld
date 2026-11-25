/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_heap_system_allocate)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_storage_release = 0x802134fc;
w3d_heap_errno = 0x802eafc4;
w3d_heap_initialize = 0x80212d90;
w3d_heap_morecore = 0x801fdfc8;
SECTIONS {
  .text.w3d_heap_system_allocate 0x80212de8 : { *(.text.w3d_heap_system_allocate) }
  .text.w3d_heap_consolidate 0x80213624 : { *(.text.w3d_heap_consolidate) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
