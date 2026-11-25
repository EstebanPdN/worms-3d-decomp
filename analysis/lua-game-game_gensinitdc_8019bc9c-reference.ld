/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_8019bc9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_801629f8PvN21ii = 0x801629f8;
__16W3dType_801e8a88PvN21iT1 = 0x801e8a88;
fn_8015f518 = 0x8015f518;
fn_8019acd8 = 0x8019acd8;
fn_8019aeb8 = 0x8019aeb8;
fn_8019b034 = 0x8019b034;
fn_8019b1fc = 0x8019b1fc;
fn_8019b378 = 0x8019b378;
fn_8019b510 = 0x8019b510;
fn_8019b644 = 0x8019b644;
fn_8019b870 = 0x8019b870;
fn_8019bb08 = 0x8019bb08;
fn_8019bc4c = 0x8019bc4c;
fn_8021a3cc = 0x8021a3cc;
lbl_80362018 = 0x80362018;
lbl_80362068 = 0x80362068;
lbl_803620b8 = 0x803620b8;
lbl_80362108 = 0x80362108;
lbl_80362158 = 0x80362158;
lbl_80365788 = 0x80365788;
lbl_80365a78 = 0x80365a78;
lbl_80365aa8 = 0x80365aa8;
lbl_803b40bc = 0x803b40bc;
lbl_803b40dc = 0x803b40dc;
lbl_803b40f4 = 0x803b40f4;
lbl_803b4104 = 0x803b4104;
lbl_803b4120 = 0x803b4120;
lbl_803b412c = 0x803b412c;
lbl_803b413c = 0x803b413c;
lbl_803b4150 = 0x803b4150;
lbl_803b415c = 0x803b415c;
lbl_803b4170 = 0x803b4170;
lbl_803b4184 = 0x803b4184;
lbl_803b41a0 = 0x803b41a0;
lbl_803b41b4 = 0x803b41b4;
lbl_803b41cc = 0x803b41cc;
lbl_803b41dc = 0x803b41dc;
lbl_803b41ec = 0x803b41ec;
lbl_803b41fc = 0x803b41fc;
lbl_803b4214 = 0x803b4214;
lbl_803b4230 = 0x803b4230;
lbl_803b424c = 0x803b424c;
lbl_803b4260 = 0x803b4260;
lbl_803b4270 = 0x803b4270;
lbl_803b4280 = 0x803b4280;
lbl_803b4290 = 0x803b4290;
lbl_803e8c30 = 0x803e8c30;
lbl_803e8c4c = 0x803e8c4c;
lbl_803e8c68 = 0x803e8c68;
lbl_803e8c84 = 0x803e8c84;
lbl_803e8ca0 = 0x803e8ca0;
lbl_803ea2d4 = 0x803ea2d4;
SECTIONS {
  .text.w3d_sinit_8019bc9c 0x8019bc9c : { *(.text.w3d_sinit_8019bc9c) }
  .text.w3d_sinit_8021c884 0x8021c884 : { *(.text.w3d_sinit_8021c884) }
  .sdata 0x804b06cc (NOLOAD) : {
    . = 0x0; lbl_804b06cc = .;
    . = 0x8; lbl_804b06d4 = .;
    . = 0x10; lbl_804b06dc = .;
    . = 0x18; lbl_804b06e4 = .;
    . = 0x20; lbl_804b06ec = .;
    . = 0x28; lbl_804b06f4 = .;
    . = 0x30; lbl_804b06fc = .;
    . = 0x38; lbl_804b0704 = .;
    . = 0x40; lbl_804b070c = .;
    . = 0x48; lbl_804b0714 = .;
    . = 0x50; lbl_804b071c = .;
    . = 0x58; lbl_804b0724 = .;
    . = 0x60; lbl_804b072c = .;
    . = 0x68; lbl_804b0734 = .;
    . = 0x70; lbl_804b073c = .;
    . = 0x78; lbl_804b0744 = .;
    . = 0x80; lbl_804b074c = .;
    . = 0x88; lbl_804b0754 = .;
    . = 0x90; lbl_804b075c = .;
    . = 0x98; lbl_804b0764 = .;
    . = 0xa0; lbl_804b076c = .;
    . = 0xa8; lbl_804b0774 = .;
    . = 0xb0; lbl_804b077c = .;
    . = 0xb8; lbl_804b0784 = .;
    . = 0xc0; lbl_804b078c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
