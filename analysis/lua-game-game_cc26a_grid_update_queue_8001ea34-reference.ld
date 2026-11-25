/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc26a_grid_update_queue_8001ea34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_find_8001df1c = 0x8001df1c;
cc26a_finish_8001eee8 = 0x8001eee8;
cc26a_prepare_8001f2cc = 0x8001f2cc;
cc26a_update_8001e590 = 0x8001e590;
SECTIONS {
  .text.cc26a_grid_update_queue_8001ea34 0x8001ea34 : { *(.text.cc26a_grid_update_queue_8001ea34) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
