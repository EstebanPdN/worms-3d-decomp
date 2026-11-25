/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc22a_planner_score_partition_80006cc0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800068a8 = 0x800068a8;
fn_800075b0 = 0x800075b0;
fn_800075c4 = 0x800075c4;
fn_800076c4 = 0x800076c4;
fn_800158b8 = 0x800158b8;
fn_8001644c = 0x8001644c;
fn_80016978 = 0x80016978;
lbl_80369504 = 0x80369504;
lbl_80369508 = 0x80369508;
lbl_8036950c = 0x8036950c;
lbl_80369510 = 0x80369510;
SECTIONS {
  .text.cc22a_planner_score_partition_80006cc0 0x80006cc0 : { *(.text.cc22a_planner_score_partition_80006cc0) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; lbl_804aa558 = .;
    . = 0x4; lbl_804aa55c = .;
    . = 0x8; lbl_804aa560 = .;
    . = 0x18; lbl_804aa570 = .;
    . = 0x24; lbl_804aa57c = .;
    . = 0x44; lbl_804aa59c = .;
    . = 0x180; lbl_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
