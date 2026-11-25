/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d42g_palette_cells_fill_8007bb54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memset = 0x802eefe0;
SECTIONS {
  .text.d42g_palette_cells_fill_8007bb54 0x8007bb54 : { *(.text.d42g_palette_cells_fill_8007bb54) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
