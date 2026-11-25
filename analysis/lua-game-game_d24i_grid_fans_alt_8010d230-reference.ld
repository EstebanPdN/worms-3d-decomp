/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_grid_fans_alt_8010d230)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_cell_high_8010b57c = 0x8010b57c;
d24i_triangle_8010b43c = 0x8010b43c;
SECTIONS {
  .text.d24i_grid_fans_alt_8010d230 0x8010d230 : { *(.text.d24i_grid_fans_alt_8010d230) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
