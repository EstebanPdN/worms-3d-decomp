/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_grid_scan_reverse_8010ca34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_edge_8010bd74 = 0x8010bd74;
d24i_triangle_8010b318 = 0x8010b318;
SECTIONS {
  .text.d24i_grid_scan_reverse_8010ca34 0x8010ca34 : { *(.text.d24i_grid_scan_reverse_8010ca34) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
