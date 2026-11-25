/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800e265c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800e05a4 = 0x800e05a4;
fn_8015f518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_80360cf0 = 0x80360cf0;
lbl_803617d0 = 0x803617d0;
lbl_80389f18 = 0x80389f18;
lbl_80389f30 = 0x80389f30;
lbl_80389f48 = 0x80389f48;
lbl_80389f60 = 0x80389f60;
lbl_80389f7c = 0x80389f7c;
lbl_80389f8c = 0x80389f8c;
lbl_803e8194 = 0x803e8194;
SECTIONS {
  .text.s8_static_init_800e265c 0x800e265c : { *(.text.s8_static_init_800e265c) }
  .sdata 0x804aaea4 (NOLOAD) : {
    . = 0x0; lbl_804aaea4 = .;
    . = 0x3e18; lbl_804aecbc = .;
    . = 0x3e1c; lbl_804aecc0 = .;
    . = 0x3e20; lbl_804aecc4 = .;
    . = 0x3e24; lbl_804aecc8 = .;
    . = 0x3e28; lbl_804aeccc = .;
    . = 0x3e2c; lbl_804aecd0 = .;
    . = 0x3e30; lbl_804aecd4 = .;
    . = 0x3e34; lbl_804aecd8 = .;
    . = 0x3e38; lbl_804aecdc = .;
    . = 0x3e3c; lbl_804aece0 = .;
    . = 0x3e44; lbl_804aece8 = .;
    . = 0x3e4c; lbl_804aecf0 = .;
    . = 0x3e54; lbl_804aecf8 = .;
    . = 0x3e5c; lbl_804aed00 = .;
    . = 0x3e64; lbl_804aed08 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
