/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc26a_grid_mark_disk_8001f4f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_cell_8001dff8 = 0x8001dff8;
cc26a_select_8001e328 = 0x8001e328;
SECTIONS {
  .text.cc26a_grid_mark_disk_8001f4f4 0x8001f4f4 : { *(.text.cc26a_grid_mark_disk_8001f4f4) }
  .rodata 0x8036b8b8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
