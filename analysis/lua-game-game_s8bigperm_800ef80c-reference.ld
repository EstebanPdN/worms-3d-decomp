/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_permuted_800ef80c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800EE1A0 = 0x800ee1a0;
fn_8015F518 = 0x8015f518;
fn_8016115C = 0x8016115c;
lbl_80360E40 = 0x80360e40;
lbl_80361860 = 0x80361860;
lbl_8038BEBC = 0x8038bebc;
lbl_8038BECC = 0x8038becc;
lbl_8038BEE4 = 0x8038bee4;
lbl_8038BEF8 = 0x8038bef8;
lbl_8038BF0C = 0x8038bf0c;
lbl_8038BF20 = 0x8038bf20;
lbl_8038BF38 = 0x8038bf38;
lbl_8038BF54 = 0x8038bf54;
lbl_8038BF70 = 0x8038bf70;
lbl_8038BF8C = 0x8038bf8c;
lbl_8038BFAC = 0x8038bfac;
lbl_8038BFCC = 0x8038bfcc;
lbl_8038BFE8 = 0x8038bfe8;
lbl_8038C000 = 0x8038c000;
lbl_8038C014 = 0x8038c014;
lbl_8038C034 = 0x8038c034;
lbl_8038C04C = 0x8038c04c;
lbl_8038C060 = 0x8038c060;
lbl_8038C070 = 0x8038c070;
lbl_8038C088 = 0x8038c088;
lbl_8038C0A0 = 0x8038c0a0;
lbl_8038C0B4 = 0x8038c0b4;
lbl_8038C0C8 = 0x8038c0c8;
lbl_8038C0DC = 0x8038c0dc;
lbl_8038C0F0 = 0x8038c0f0;
lbl_8038C104 = 0x8038c104;
lbl_8038C108 = 0x8038c108;
lbl_803E8258 = 0x803e8258;
lbl_804494B0 = 0x804494b0;
SECTIONS {
  .text.s8_permuted_800ef80c 0x800ef80c : { *(.text.s8_permuted_800ef80c) }
  .sdata 0x804aef5c (NOLOAD) : {
    . = 0x0; lbl_804AEF5C = .;
    . = 0x8; lbl_804AEF64 = .;
    . = 0x10; lbl_804AEF6C = .;
    . = 0x18; lbl_804AEF74 = .;
    . = 0x20; lbl_804AEF7C = .;
    . = 0x28; lbl_804AEF84 = .;
    . = 0x30; lbl_804AEF8C = .;
    . = 0x38; lbl_804AEF94 = .;
    . = 0x40; lbl_804AEF9C = .;
    . = 0x48; lbl_804AEFA4 = .;
    . = 0x50; lbl_804AEFAC = .;
    . = 0x58; lbl_804AEFB4 = .;
    . = 0x60; lbl_804AEFBC = .;
    . = 0x68; lbl_804AEFC4 = .;
    . = 0x70; lbl_804AEFCC = .;
    . = 0x78; lbl_804AEFD4 = .;
    . = 0x80; lbl_804AEFDC = .;
    . = 0x88; lbl_804AEFE4 = .;
    . = 0x90; lbl_804AEFEC = .;
    . = 0x98; lbl_804AEFF4 = .;
    . = 0xa0; lbl_804AEFFC = .;
    . = 0xa8; lbl_804AF004 = .;
    . = 0xb0; lbl_804AF00C = .;
    . = 0xb8; lbl_804AF014 = .;
    . = 0xc0; lbl_804AF01C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
