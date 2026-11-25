/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_planner_tick_800064d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80006360 = 0x80006360;
fn_8000666c = 0x8000666c;
fn_800067a8 = 0x800067a8;
fn_800068a8 = 0x800068a8;
fn_80006b78 = 0x80006b78;
fn_80006cc0 = 0x80006cc0;
fn_80006eb8 = 0x80006eb8;
fn_800075c4 = 0x800075c4;
fn_80007a28 = 0x80007a28;
fn_8001523c = 0x8001523c;
fn_800160fc = 0x800160fc;
fn_800166bc = 0x800166bc;
fn_800169e0 = 0x800169e0;
fn_800181e8 = 0x800181e8;
fn_80019988 = 0x80019988;
lbl_803694d8 = 0x803694d8;
lbl_803694dc = 0x803694dc;
lbl_803694e0 = 0x803694e0;
lbl_8040cb70 = 0x8040cb70;
SECTIONS {
  .text.cc23a_planner_tick_800064d4 0x800064d4 : { *(.text.cc23a_planner_tick_800064d4) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; lbl_804aa558 = .;
    . = 0x10; lbl_804aa568 = .;
    . = 0x14; lbl_804aa56c = .;
    . = 0x18; lbl_804aa570 = .;
    . = 0x20; lbl_804aa578 = .;
    . = 0x184; lbl_804aa6dc = .;
    . = 0x188; lbl_804aa6e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
