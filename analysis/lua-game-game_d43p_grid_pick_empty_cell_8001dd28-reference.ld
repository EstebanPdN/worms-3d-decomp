/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43p_grid_pick_empty_cell_8001dd28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s19_random_unit_80015810 = 0x80015810;
w3d_auto_80015860 = 0x80015860;
SECTIONS {
  .text.w3d_d43p_grid_pick_empty_cell_8001dd28 0x8001dd28 : { *(.text.w3d_d43p_grid_pick_empty_cell_8001dd28) }
  .rodata 0x8036b800 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
