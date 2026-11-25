/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800d9f30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800d7818 = 0x800d7818;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_80360c60 = 0x80360c60;
lbl_80360e10 = 0x80360e10;
lbl_803895a8 = 0x803895a8;
lbl_803895bc = 0x803895bc;
lbl_803895cc = 0x803895cc;
lbl_803895dc = 0x803895dc;
lbl_803895f4 = 0x803895f4;
lbl_80389610 = 0x80389610;
lbl_80389630 = 0x80389630;
lbl_80389650 = 0x80389650;
lbl_80389664 = 0x80389664;
lbl_80389674 = 0x80389674;
lbl_80389690 = 0x80389690;
lbl_803896a4 = 0x803896a4;
lbl_803896b4 = 0x803896b4;
lbl_803896c4 = 0x803896c4;
lbl_803896d0 = 0x803896d0;
lbl_803896e4 = 0x803896e4;
lbl_803896f4 = 0x803896f4;
lbl_80389704 = 0x80389704;
lbl_80389718 = 0x80389718;
lbl_803e8140 = 0x803e8140;
SECTIONS {
  .text.s8_static_init_800d9f30 0x800d9f30 : { *(.text.s8_static_init_800d9f30) }
  .sdata 0x804aae74 (NOLOAD) : {
    . = 0x0; lbl_804aae74 = .;
    . = 0x3c58; lbl_804aeacc = .;
    . = 0x3c5c; lbl_804aead0 = .;
    . = 0x3c60; lbl_804aead4 = .;
    . = 0x3c64; lbl_804aead8 = .;
    . = 0x3c68; lbl_804aeadc = .;
    . = 0x3c6c; lbl_804aeae0 = .;
    . = 0x3c70; lbl_804aeae4 = .;
    . = 0x3c74; lbl_804aeae8 = .;
    . = 0x3c78; lbl_804aeaec = .;
    . = 0x3c7c; lbl_804aeaf0 = .;
    . = 0x3c84; lbl_804aeaf8 = .;
    . = 0x3c8c; lbl_804aeb00 = .;
    . = 0x3c94; lbl_804aeb08 = .;
    . = 0x3c9c; lbl_804aeb10 = .;
    . = 0x3ca4; lbl_804aeb18 = .;
    . = 0x3cac; lbl_804aeb20 = .;
    . = 0x3cb4; lbl_804aeb28 = .;
    . = 0x3cbc; lbl_804aeb30 = .;
    . = 0x3cc4; lbl_804aeb38 = .;
    . = 0x3ccc; lbl_804aeb40 = .;
    . = 0x3cd4; lbl_804aeb48 = .;
    . = 0x3cdc; lbl_804aeb50 = .;
    . = 0x3ce4; lbl_804aeb58 = .;
    . = 0x3cec; lbl_804aeb60 = .;
    . = 0x3cf4; lbl_804aeb68 = .;
    . = 0x3cfc; lbl_804aeb70 = .;
    . = 0x3d04; lbl_804aeb78 = .;
    . = 0x3d0c; lbl_804aeb80 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
