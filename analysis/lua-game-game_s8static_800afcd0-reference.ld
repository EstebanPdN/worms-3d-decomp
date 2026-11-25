/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800afcd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800af380 = 0x800af380;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_803608a0 = 0x803608a0;
lbl_80360c60 = 0x80360c60;
lbl_803822dc = 0x803822dc;
lbl_803822ec = 0x803822ec;
lbl_80382300 = 0x80382300;
lbl_803e7f10 = 0x803e7f10;
SECTIONS {
  .text.s8_static_init_800afcd0 0x800afcd0 : { *(.text.s8_static_init_800afcd0) }
  .sdata 0x804aaca4 (NOLOAD) : {
    . = 0x0; lbl_804aaca4 = .;
    . = 0x375c; lbl_804ae400 = .;
    . = 0x3760; lbl_804ae404 = .;
    . = 0x3764; lbl_804ae408 = .;
    . = 0x3768; lbl_804ae40c = .;
    . = 0x376c; lbl_804ae410 = .;
    . = 0x3770; lbl_804ae414 = .;
    . = 0x3774; lbl_804ae418 = .;
    . = 0x3778; lbl_804ae41c = .;
    . = 0x377c; lbl_804ae420 = .;
    . = 0x3780; lbl_804ae424 = .;
    . = 0x3788; lbl_804ae42c = .;
    . = 0x3790; lbl_804ae434 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
