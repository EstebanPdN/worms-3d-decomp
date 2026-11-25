/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12a_sample_grid_8001e224)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
height_8001e07c = 0x8001e07c;
SECTIONS {
  .text.w3d_cx12a_sample_grid_8001e224 0x8001e224 : { *(.text.w3d_cx12a_sample_grid_8001e224) }
  .rodata 0x8036b820 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
