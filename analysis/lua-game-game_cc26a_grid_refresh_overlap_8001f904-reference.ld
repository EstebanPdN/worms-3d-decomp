/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc26a_grid_refresh_overlap_8001f904)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_apply_8001f4f4 = 0x8001f4f4;
cc26a_remove_8001f6fc = 0x8001f6fc;
SECTIONS {
  .text.cc26a_grid_refresh_overlap_8001f904 0x8001f904 : { *(.text.cc26a_grid_refresh_overlap_8001f904) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
