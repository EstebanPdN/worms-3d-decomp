/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19b_register_properties_8024eb00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efcd0 = 0x801efcd0;
fn_801efdfc = 0x801efdfc;
fn_801eff8c = 0x801eff8c;
fn_801efff0 = 0x801efff0;
lbl_803c5140 = 0x803c5140;
lbl_803c553c = 0x803c553c;
lbl_803c5550 = 0x803c5550;
lbl_803c555c = 0x803c555c;
lbl_803fe4c4 = 0x803fe4c4;
lbl_8045e004 = 0x8045e004;
lbl_8045ed10 = 0x8045ed10;
lbl_8045ed4c = 0x8045ed4c;
lbl_8045ed94 = 0x8045ed94;
lbl_80464f7c = 0x80464f7c;
lbl_80464f90 = 0x80464f90;
lbl_80464fa4 = 0x80464fa4;
lbl_80464fb8 = 0x80464fb8;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc19b_register_properties_8024eb00 0x8024eb00 : { *(.text.w3d_cc19b_register_properties_8024eb00) }
  .sdata 0x804b08e0 (NOLOAD) : {
    . = 0x0; lbl_804b08e0 = .;
    . = 0x4; lbl_804b08e4 = .;
    . = 0x8; lbl_804b08e8 = .;
    . = 0xc; lbl_804b08ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
