/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d42e_ref_array_resize_801f282c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_allocate_801fe220 = 0x801fe220;
w3d_task_array_release_801fe240 = 0x801fe240;
SECTIONS {
  .text.w3d_d42e_ref_array_resize_801f282c 0x801f282c : { *(.text.w3d_d42e_ref_array_resize_801f282c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
