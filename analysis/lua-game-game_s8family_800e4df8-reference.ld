/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800e4df8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800e3528 = 0x800e3528;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_80360d50 = 0x80360d50;
lbl_80361860 = 0x80361860;
lbl_8038a134 = 0x8038a134;
lbl_8038a14c = 0x8038a14c;
lbl_8038a15c = 0x8038a15c;
lbl_8038a170 = 0x8038a170;
lbl_8038a17c = 0x8038a17c;
lbl_8038a18c = 0x8038a18c;
lbl_8038a1a4 = 0x8038a1a4;
lbl_803e81cc = 0x803e81cc;
SECTIONS {
  .text.s8_static_init_800e4df8 0x800e4df8 : { *(.text.s8_static_init_800e4df8) }
  .sdata 0x804aaeb4 (NOLOAD) : {
    . = 0x0; lbl_804aaeb4 = .;
    . = 0x3e6c; lbl_804aed20 = .;
    . = 0x3e70; lbl_804aed24 = .;
    . = 0x3e74; lbl_804aed28 = .;
    . = 0x3e78; lbl_804aed2c = .;
    . = 0x3e7c; lbl_804aed30 = .;
    . = 0x3e80; lbl_804aed34 = .;
    . = 0x3e84; lbl_804aed38 = .;
    . = 0x3e88; lbl_804aed3c = .;
    . = 0x3e8c; lbl_804aed40 = .;
    . = 0x3e90; lbl_804aed44 = .;
    . = 0x3e98; lbl_804aed4c = .;
    . = 0x3ea0; lbl_804aed54 = .;
    . = 0x3ea8; lbl_804aed5c = .;
    . = 0x3eb0; lbl_804aed64 = .;
    . = 0x3eb8; lbl_804aed6c = .;
    . = 0x3ec0; lbl_804aed74 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
