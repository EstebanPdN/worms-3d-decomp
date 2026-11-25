/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_planner_inventory_delays_80007a28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_800fc6dc = 0x800fc6dc;
fn_800fcec8 = 0x800fcec8;
fn_801797b4 = 0x801797b4;
fn_8025c3a8 = 0x8025c3a8;
fn_80341584 = 0x80341584;
lbl_80369550 = 0x80369550;
lbl_80369568 = 0x80369568;
SECTIONS {
  .text.cc23a_planner_inventory_delays_80007a28 0x80007a28 : { *(.text.cc23a_planner_inventory_delays_80007a28) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; lbl_804aa570 = .;
    . = 0x30; lbl_804aa5a0 = .;
    . = 0x38; lbl_804aa5a8 = .;
    . = 0x150; lbl_804aa6c0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
