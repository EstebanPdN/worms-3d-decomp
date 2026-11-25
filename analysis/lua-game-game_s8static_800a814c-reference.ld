/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800a814c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a5f08 = 0x800a5f08;
fn_8015f518 = 0x8015f518;
fn_801629f8 = 0x801629f8;
fn_802097ec = 0x802097ec;
lbl_80360810 = 0x80360810;
lbl_803618f0 = 0x803618f0;
lbl_80381540 = 0x80381540;
lbl_8038154c = 0x8038154c;
lbl_8038155c = 0x8038155c;
lbl_8038156c = 0x8038156c;
lbl_80381580 = 0x80381580;
lbl_80381594 = 0x80381594;
lbl_803815a8 = 0x803815a8;
lbl_803815c0 = 0x803815c0;
lbl_803815dc = 0x803815dc;
lbl_803815f8 = 0x803815f8;
lbl_80381618 = 0x80381618;
lbl_8038162c = 0x8038162c;
lbl_80381640 = 0x80381640;
lbl_80381654 = 0x80381654;
lbl_80381668 = 0x80381668;
lbl_80381680 = 0x80381680;
lbl_8038169c = 0x8038169c;
lbl_803e7ebc = 0x803e7ebc;
SECTIONS {
  .text.s8_static_init_800a814c 0x800a814c : { *(.text.s8_static_init_800a814c) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; lbl_804ae280 = .;
    . = 0x8; lbl_804ae288 = .;
    . = 0x10; lbl_804ae290 = .;
    . = 0x18; lbl_804ae298 = .;
    . = 0x20; lbl_804ae2a0 = .;
    . = 0x28; lbl_804ae2a8 = .;
    . = 0x30; lbl_804ae2b0 = .;
    . = 0x38; lbl_804ae2b8 = .;
    . = 0x40; lbl_804ae2c0 = .;
    . = 0x48; lbl_804ae2c8 = .;
    . = 0x50; lbl_804ae2d0 = .;
    . = 0x58; lbl_804ae2d8 = .;
    . = 0x60; lbl_804ae2e0 = .;
    . = 0x68; lbl_804ae2e8 = .;
    . = 0x70; lbl_804ae2f0 = .;
    . = 0x78; lbl_804ae2f8 = .;
    . = 0x80; lbl_804ae300 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
