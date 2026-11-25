/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_planner_create_choices_800077f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80006360 = 0x80006360;
fn_80007514 = 0x80007514;
fn_8001523c = 0x8001523c;
lbl_8040d780 = 0x8040d780;
lbl_8040d7b8 = 0x8040d7b8;
lbl_8040d7f0 = 0x8040d7f0;
lbl_8040da88 = 0x8040da88;
lbl_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.cc23a_planner_create_choices_800077f4 0x800077f4 : { *(.text.cc23a_planner_create_choices_800077f4) }
  .rodata 0x80369548 : { *(.rodata) }
  .sdata 0x804aa5a0 (NOLOAD) : {
    . = 0x0; lbl_804aa5a0 = .;
    . = 0x1b0; lbl_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
