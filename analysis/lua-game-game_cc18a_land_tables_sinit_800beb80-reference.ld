/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18a_land_tables_sinit_800beb80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800ba7b0 = 0x800ba7b0;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_80360900 = 0x80360900;
lbl_80361860 = 0x80361860;
lbl_80382d44 = 0x80382d44;
lbl_80382d50 = 0x80382d50;
lbl_80382d5c = 0x80382d5c;
lbl_80382d6c = 0x80382d6c;
lbl_80382d7c = 0x80382d7c;
lbl_80382d8c = 0x80382d8c;
lbl_80382d98 = 0x80382d98;
lbl_80382dac = 0x80382dac;
lbl_80382db0 = 0x80382db0;
lbl_80382dc0 = 0x80382dc0;
lbl_80382dd4 = 0x80382dd4;
lbl_803e7f48 = 0x803e7f48;
lbl_8043bb64 = 0x8043bb64;
SECTIONS {
  .text.w3d_cc18a_land_tables_sinit_800beb80 0x800beb80 : { *(.text.w3d_cc18a_land_tables_sinit_800beb80) }
  .sdata 0x804aad3c (NOLOAD) : {
    . = 0x0; lbl_804aad3c = .;
    . = 0x3820; lbl_804ae55c = .;
    . = 0x3824; lbl_804ae560 = .;
    . = 0x3828; lbl_804ae564 = .;
    . = 0x382c; lbl_804ae568 = .;
    . = 0x3830; lbl_804ae56c = .;
    . = 0x3834; lbl_804ae570 = .;
    . = 0x3838; lbl_804ae574 = .;
    . = 0x383c; lbl_804ae578 = .;
    . = 0x3840; lbl_804ae57c = .;
    . = 0x3844; lbl_804ae580 = .;
    . = 0x384c; lbl_804ae588 = .;
    . = 0x3854; lbl_804ae590 = .;
    . = 0x385c; lbl_804ae598 = .;
    . = 0x3864; lbl_804ae5a0 = .;
    . = 0x386c; lbl_804ae5a8 = .;
    . = 0x3874; lbl_804ae5b0 = .;
    . = 0x387c; lbl_804ae5b8 = .;
    . = 0x3884; lbl_804ae5c0 = .;
    . = 0x388c; lbl_804ae5c8 = .;
    . = 0x3894; lbl_804ae5d0 = .;
    . = 0x389c; lbl_804ae5d8 = .;
    . = 0x38a0; lbl_804ae5dc = .;
    . = 0x38a4; lbl_804ae5e0 = .;
    . = 0x38a8; lbl_804ae5e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
