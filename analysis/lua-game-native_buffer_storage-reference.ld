/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_buffer_storage_allocate)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_buffer_heap_dispatch_802098fc = 0x802098fc;
w3d_buffer_heap_dispatch_80209968 = 0x80209968;
w3d_buffer_heap_dispatch_80209a20 = 0x80209a20;
w3d_heap_release = 0x80209920;
SECTIONS {
  .text.w3d_buffer_storage_allocate 0x801981d0 : { *(.text.w3d_buffer_storage_allocate) }
  .text.w3d_buffer_storage_available 0x801981f8 : { *(.text.w3d_buffer_storage_available) }
  .text.w3d_buffer_storage_release 0x8019821c : { *(.text.w3d_buffer_storage_release) }
  .sdata 0x804ab6cc (NOLOAD) : {
    . = 0x0; w3d_buffer_heap = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
