/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800bef64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800BF018 = 0x800bf018;
fn_800BF2D4 = 0x800bf2d4;
fn_800BF320 = 0x800bf320;
fn_800C6640 = 0x800c6640;
fn_800C6698 = 0x800c6698;
fn_800C67F0 = 0x800c67f0;
fn_800C6A20 = 0x800c6a20;
fn_800C6B50 = 0x800c6b50;
fn_800F18BC = 0x800f18bc;
fn_800F1A6C = 0x800f1a6c;
fn_800F1C60 = 0x800f1c60;
fn_8010A8FC = 0x8010a8fc;
fn_8015F620 = 0x8015f620;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8016293C = 0x8016293c;
fn_8020BD38 = 0x8020bd38;
fn_8020C5C0 = 0x8020c5c0;
fn_8020C5C4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
SECTIONS {
  .text.w3d_auto_800bef64 0x800bef64 : { *(.text.w3d_auto_800bef64) }
  .text.w3d_auto_800c647c 0x800c647c : { *(.text.w3d_auto_800c647c) }
  .text.w3d_auto_800f1814 0x800f1814 : { *(.text.w3d_auto_800f1814) }
  .sdata 0x804ae60c (NOLOAD) : {
    . = 0x0; lbl_804AE60C = .;
    . = 0x188; lbl_804AE794 = .;
    . = 0x190; lbl_804AE79C = .;
    . = 0x198; lbl_804AE7A4 = .;
    . = 0x1a0; lbl_804AE7AC = .;
    . = 0x1a8; lbl_804AE7B4 = .;
    . = 0x1c8; lbl_804AE7D4 = .;
    . = 0x1e0; lbl_804AE7EC = .;
    . = 0xa8c; lbl_804AF098 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
