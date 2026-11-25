/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxa2_grid_storage_8002c2f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801fe220 = 0x801fe220;
fill_802eefe0 = 0x802eefe0;
SECTIONS {
  .text.cxa2_grid_storage_8002c2f8 0x8002c2f8 : { *(.text.cxa2_grid_storage_8002c2f8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
