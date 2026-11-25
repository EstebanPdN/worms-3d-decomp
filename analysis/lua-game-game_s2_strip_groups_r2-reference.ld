/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_grid_cell_low_8010b560)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_grid_cell_low_8010b560 0x8010b560 : { *(.text.w3d_grid_cell_low_8010b560) }
  .text.w3d_grid_cell_8010b57c 0x8010b57c : { *(.text.w3d_grid_cell_8010b57c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
