/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_planner_distance_penalty_8000b5f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e82c0 = 0x802e82c0;
lbl_80369c5c = 0x80369c5c;
lbl_80369c60 = 0x80369c60;
SECTIONS {
  .text.cc23a_planner_distance_penalty_8000b5f4 0x8000b5f4 : { *(.text.cc23a_planner_distance_penalty_8000b5f4) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804aa6d8 = .;
    . = 0x78; lbl_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
