/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_grid_scan_alt_8010d0a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_edge_8010bda0 = 0x8010bda0;
d24i_triangle_8010b43c = 0x8010b43c;
SECTIONS {
  .text.d24i_grid_scan_alt_8010d0a0 0x8010d0a0 : { *(.text.d24i_grid_scan_alt_8010d0a0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
