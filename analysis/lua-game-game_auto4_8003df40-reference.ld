/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003df40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8003E030 = 0x8003e030;
fn_8003E1F4 = 0x8003e1f4;
fn_8003E3A4 = 0x8003e3a4;
fn_8003E5F0 = 0x8003e5f0;
fn_8003EF88 = 0x8003ef88;
fn_8003EFD8 = 0x8003efd8;
fn_800438D4 = 0x800438d4;
fn_80043B74 = 0x80043b74;
fn_80043E38 = 0x80043e38;
fn_80043F00 = 0x80043f00;
fn_800441C0 = 0x800441c0;
fn_80049D48 = 0x80049d48;
fn_8004A38C = 0x8004a38c;
fn_8004B908 = 0x8004b908;
fn_8004CA00 = 0x8004ca00;
fn_8004CE38 = 0x8004ce38;
fn_8004D044 = 0x8004d044;
fn_8004D35C = 0x8004d35c;
fn_8004D428 = 0x8004d428;
fn_800A830C = 0x800a830c;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
SECTIONS {
  .text.w3d_auto_8003df40 0x8003df40 : { *(.text.w3d_auto_8003df40) }
  .text.w3d_auto_8003e314 0x8003e314 : { *(.text.w3d_auto_8003e314) }
  .text.w3d_auto_800433e0 0x800433e0 : { *(.text.w3d_auto_800433e0) }
  .text.w3d_auto_800499f0 0x800499f0 : { *(.text.w3d_auto_800499f0) }
  .sdata 0x804ad1b4 (NOLOAD) : {
    . = 0x0; lbl_804AD1B4 = .;
    . = 0x1bc; lbl_804AD370 = .;
    . = 0x1d4; lbl_804AD388 = .;
    . = 0x1dc; lbl_804AD390 = .;
    . = 0x1f4; lbl_804AD3A8 = .;
    . = 0x20c; lbl_804AD3C0 = .;
    . = 0x21c; lbl_804AD3D0 = .;
    . = 0x224; lbl_804AD3D8 = .;
    . = 0x22c; lbl_804AD3E0 = .;
    . = 0x234; lbl_804AD3E8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
