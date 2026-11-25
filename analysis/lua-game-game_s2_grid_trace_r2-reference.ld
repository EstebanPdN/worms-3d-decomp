/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_grid_edge_8010bd74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_grid_edge_8010bd74 0x8010bd74 : { *(.text.w3d_grid_edge_8010bd74) }
  .text.w3d_grid_edge_8010bda0 0x8010bda0 : { *(.text.w3d_grid_edge_8010bda0) }
  .text.w3d_grid_prefer_columns_8010bdc8 0x8010bdc8 : { *(.text.w3d_grid_prefer_columns_8010bdc8) }
  .text.w3d_grid_prefer_columns_8010bebc 0x8010bebc : { *(.text.w3d_grid_prefer_columns_8010bebc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
