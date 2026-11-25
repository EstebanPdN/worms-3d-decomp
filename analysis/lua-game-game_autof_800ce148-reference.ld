/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800ce148)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80035714 = 0x80035714;
fn_80069A28 = 0x80069a28;
fn_800CE48C = 0x800ce48c;
fn_800CEF44 = 0x800cef44;
fn_800CF010 = 0x800cf010;
fn_800CF028 = 0x800cf028;
fn_800D0D6C = 0x800d0d6c;
fn_800D0FA0 = 0x800d0fa0;
fn_800DC604 = 0x800dc604;
fn_8015F65C = 0x8015f65c;
fn_8015FB34 = 0x8015fb34;
fn_8015FD1C = 0x8015fd1c;
fn_80178D1C = 0x80178d1c;
fn_801FE1F8 = 0x801fe1f8;
lbl_80387EF4 = 0x80387ef4;
lbl_80387EF8 = 0x80387ef8;
lbl_80387EFC = 0x80387efc;
lbl_80388140 = 0x80388140;
lbl_80389144 = 0x80389144;
lbl_8038914C = 0x8038914c;
lbl_80389898 = 0x80389898;
lbl_8040FD60 = 0x8040fd60;
lbl_8040FE70 = 0x8040fe70;
SECTIONS {
  .text.w3d_auto_800ce148 0x800ce148 : { *(.text.w3d_auto_800ce148) }
  .text.w3d_auto_800d00f0 0x800d00f0 : { *(.text.w3d_auto_800d00f0) }
  .text.w3d_auto_800d72b4 0x800d72b4 : { *(.text.w3d_auto_800d72b4) }
  .text.w3d_auto_800d75bc 0x800d75bc : { *(.text.w3d_auto_800d75bc) }
  .text.w3d_auto_800dbd58 0x800dbd58 : { *(.text.w3d_auto_800dbd58) }
  .text.w3d_auto_800dc674 0x800dc674 : { *(.text.w3d_auto_800dc674) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804AA8C8 = .;
    . = 0x3fe8; lbl_804AE8B0 = .;
    . = 0x3ff0; lbl_804AE8B8 = .;
    . = 0x4000; lbl_804AE8C8 = .;
    . = 0x4010; lbl_804AE8D8 = .;
    . = 0x4018; lbl_804AE8E0 = .;
    . = 0x4020; lbl_804AE8E8 = .;
    . = 0x4028; lbl_804AE8F0 = .;
    . = 0x4030; lbl_804AE8F8 = .;
    . = 0x4038; lbl_804AE900 = .;
    . = 0x4040; lbl_804AE908 = .;
    . = 0x4048; lbl_804AE910 = .;
    . = 0x4050; lbl_804AE918 = .;
    . = 0x4058; lbl_804AE920 = .;
    . = 0x4060; lbl_804AE928 = .;
    . = 0x4068; lbl_804AE930 = .;
    . = 0x40b8; lbl_804AE980 = .;
    . = 0x40c0; lbl_804AE988 = .;
    . = 0x41f8; lbl_804AEAC0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
