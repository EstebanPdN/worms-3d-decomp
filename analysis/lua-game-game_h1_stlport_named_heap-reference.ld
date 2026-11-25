/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_push_heap_8034a400)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_auto_801ffea8 = 0x801ffea8;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_push_heap_8034a400 0x8034a400 : { *(.text.w3d_push_heap_8034a400) }
  .text.w3d_adjust_heap_8034a568 0x8034a568 : { *(.text.w3d_adjust_heap_8034a568) }
  .text.w3d_pop_heap_8034a7fc 0x8034a7fc : { *(.text.w3d_pop_heap_8034a7fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
