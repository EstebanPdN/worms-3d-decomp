/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_bound_800d6a20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800d5818 = 0x800d5818;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_80360c30 = 0x80360c30;
lbl_80361860 = 0x80361860;
lbl_80388fcc = 0x80388fcc;
lbl_80388fd8 = 0x80388fd8;
lbl_80388fe8 = 0x80388fe8;
lbl_80388ff8 = 0x80388ff8;
lbl_80389008 = 0x80389008;
lbl_803e8124 = 0x803e8124;
SECTIONS {
  .text.s8_bound_800d6a20 0x800d6a20 : { *(.text.s8_bound_800d6a20) }
  .sdata 0x804aae5c (NOLOAD) : {
    . = 0x0; lbl_804aae5c = .;
    . = 0x3bd8; lbl_804aea34 = .;
    . = 0x3bdc; lbl_804aea38 = .;
    . = 0x3be0; lbl_804aea3c = .;
    . = 0x3be4; lbl_804aea40 = .;
    . = 0x3be8; lbl_804aea44 = .;
    . = 0x3bec; lbl_804aea48 = .;
    . = 0x3bf0; lbl_804aea4c = .;
    . = 0x3bf4; lbl_804aea50 = .;
    . = 0x3bf8; lbl_804aea54 = .;
    . = 0x3bfc; lbl_804aea58 = .;
    . = 0x3c04; lbl_804aea60 = .;
    . = 0x3c0c; lbl_804aea68 = .;
    . = 0x3c14; lbl_804aea70 = .;
    . = 0x3c1c; lbl_804aea78 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
