/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_derived_pointers_8003b7f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_80160038PvN21ii = 0x80160038;
__16W3dType_8016115cPvN21ii = 0x8016115c;
fn_8003a850 = 0x8003a850;
fn_80066dfc = 0x80066dfc;
fn_800bed88 = 0x800bed88;
fn_800c3fa4 = 0x800c3fa4;
fn_8015f518 = 0x8015f518;
lbl_8035ff70 = 0x8035ff70;
lbl_80360390 = 0x80360390;
lbl_80360930 = 0x80360930;
lbl_80360a50 = 0x80360a50;
lbl_803617d0 = 0x803617d0;
lbl_80361860 = 0x80361860;
lbl_8037432c = 0x8037432c;
lbl_8037a0f4 = 0x8037a0f4;
lbl_80382e70 = 0x80382e70;
lbl_80383570 = 0x80383570;
lbl_803e79b4 = 0x803e79b4;
lbl_803e7c1c = 0x803e7c1c;
lbl_803e7f64 = 0x803e7f64;
lbl_803e800c = 0x803e800c;
SECTIONS {
  .text.w3d_sinit_derived_pointers_8003b7f8 0x8003b7f8 : { *(.text.w3d_sinit_derived_pointers_8003b7f8) }
  .text.w3d_sinit_derived_pointers_80067894 0x80067894 : { *(.text.w3d_sinit_derived_pointers_80067894) }
  .text.w3d_sinit_derived_pointers_800bfdac 0x800bfdac : { *(.text.w3d_sinit_derived_pointers_800bfdac) }
  .text.w3d_sinit_derived_pointers_800c44b4 0x800c44b4 : { *(.text.w3d_sinit_derived_pointers_800c44b4) }
  .sdata 0x804aa91c (NOLOAD) : {
    . = 0x0; lbl_804aa91c = .;
    . = 0x15c; lbl_804aaa78 = .;
    . = 0x480; lbl_804aad9c = .;
    . = 0x4c8; lbl_804aade4 = .;
    . = 0x27ec; lbl_804ad108 = .;
    . = 0x27f0; lbl_804ad10c = .;
    . = 0x27f4; lbl_804ad110 = .;
    . = 0x27f8; lbl_804ad114 = .;
    . = 0x27fc; lbl_804ad118 = .;
    . = 0x2800; lbl_804ad11c = .;
    . = 0x2804; lbl_804ad120 = .;
    . = 0x2808; lbl_804ad124 = .;
    . = 0x280c; lbl_804ad128 = .;
    . = 0x2810; lbl_804ad12c = .;
    . = 0x2c94; lbl_804ad5b0 = .;
    . = 0x2c98; lbl_804ad5b4 = .;
    . = 0x2c9c; lbl_804ad5b8 = .;
    . = 0x2ca0; lbl_804ad5bc = .;
    . = 0x2ca4; lbl_804ad5c0 = .;
    . = 0x2ca8; lbl_804ad5c4 = .;
    . = 0x2cac; lbl_804ad5c8 = .;
    . = 0x2cb0; lbl_804ad5cc = .;
    . = 0x2cb4; lbl_804ad5d0 = .;
    . = 0x2cb8; lbl_804ad5d4 = .;
    . = 0x3ccc; lbl_804ae5e8 = .;
    . = 0x3cd0; lbl_804ae5ec = .;
    . = 0x3cd4; lbl_804ae5f0 = .;
    . = 0x3cd8; lbl_804ae5f4 = .;
    . = 0x3cdc; lbl_804ae5f8 = .;
    . = 0x3ce0; lbl_804ae5fc = .;
    . = 0x3ce4; lbl_804ae600 = .;
    . = 0x3ce8; lbl_804ae604 = .;
    . = 0x3cec; lbl_804ae608 = .;
    . = 0x3cf0; lbl_804ae60c = .;
    . = 0x3e4c; lbl_804ae768 = .;
    . = 0x3e50; lbl_804ae76c = .;
    . = 0x3e54; lbl_804ae770 = .;
    . = 0x3e58; lbl_804ae774 = .;
    . = 0x3e5c; lbl_804ae778 = .;
    . = 0x3e60; lbl_804ae77c = .;
    . = 0x3e64; lbl_804ae780 = .;
    . = 0x3e68; lbl_804ae784 = .;
    . = 0x3e6c; lbl_804ae788 = .;
    . = 0x3e70; lbl_804ae78c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
