/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_planner_sum_weighted_costs_8000b4c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8000b344 = 0x8000b344;
fn_8000b418 = 0x8000b418;
lbl_8041d3a0 = 0x8041d3a0;
lbl_8041d3ac = 0x8041d3ac;
SECTIONS {
  .text.cc23a_planner_sum_weighted_costs_8000b4c4 0x8000b4c4 : { *(.text.cc23a_planner_sum_weighted_costs_8000b4c4) }
  .rodata 0x80369c58 : { *(.rodata) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; lbl_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
