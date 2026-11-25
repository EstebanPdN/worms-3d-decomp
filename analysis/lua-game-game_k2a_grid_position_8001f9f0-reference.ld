/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_grid_position_8001f9f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8001e224 = 0x8001e224;
FUN_8001e328 = 0x8001e328;
SECTIONS {
  .text.k2a_grid_position_8001f9f0 0x8001f9f0 : { *(.text.k2a_grid_position_8001f9f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
