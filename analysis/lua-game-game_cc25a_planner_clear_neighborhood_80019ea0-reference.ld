/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc25a_planner_clear_neighborhood_80019ea0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc25a_grid_coords_8001e328 = 0x8001e328;
cc25a_origin_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.cc25a_planner_clear_neighborhood_80019ea0 0x80019ea0 : { *(.text.cc25a_planner_clear_neighborhood_80019ea0) }
  .rodata 0x8036a95c : { *(.rodata) }
  .sdata 0x804aa758 (NOLOAD) : {
    . = 0x0; cc25a_scores_804aa758 = .;
    . = 0x7000; cc25a_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
