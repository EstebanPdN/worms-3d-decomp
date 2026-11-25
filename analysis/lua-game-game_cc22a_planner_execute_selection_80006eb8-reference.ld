/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc22a_planner_execute_selection_80006eb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80006694 = 0x80006694;
fn_800068a8 = 0x800068a8;
fn_80007080 = 0x80007080;
fn_800071ec = 0x800071ec;
fn_800075b0 = 0x800075b0;
fn_80015f38 = 0x80015f38;
lbl_80369514 = 0x80369514;
lbl_8041d3a0 = 0x8041d3a0;
lbl_8041d3ac = 0x8041d3ac;
SECTIONS {
  .text.cc22a_planner_execute_selection_80006eb8 0x80006eb8 : { *(.text.cc22a_planner_execute_selection_80006eb8) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; lbl_804aa558 = .;
    . = 0x20; lbl_804aa578 = .;
    . = 0x40; lbl_804aa598 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
