/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc22a_planner_poll_requeue_80006b78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800068a8 = 0x800068a8;
fn_80006b64 = 0x80006b64;
fn_800071ec = 0x800071ec;
fn_800075b0 = 0x800075b0;
fn_800075c4 = 0x800075c4;
fn_800076c4 = 0x800076c4;
lbl_80369500 = 0x80369500;
SECTIONS {
  .text.cc22a_planner_poll_requeue_80006b78 0x80006b78 : { *(.text.cc22a_planner_poll_requeue_80006b78) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; lbl_804aa558 = .;
    . = 0x4; lbl_804aa55c = .;
    . = 0x18; lbl_804aa570 = .;
    . = 0x20; lbl_804aa578 = .;
    . = 0x24; lbl_804aa57c = .;
    . = 0x3c; lbl_804aa594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
