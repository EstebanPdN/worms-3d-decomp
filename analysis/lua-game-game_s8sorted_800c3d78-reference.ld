/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800c3d78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800c26a4 = 0x800c26a4;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_80360a20 = 0x80360a20;
lbl_80361860 = 0x80361860;
lbl_803832c0 = 0x803832c0;
lbl_803832d0 = 0x803832d0;
lbl_803832e4 = 0x803832e4;
lbl_803832f8 = 0x803832f8;
lbl_80383310 = 0x80383310;
lbl_80383324 = 0x80383324;
lbl_80383340 = 0x80383340;
lbl_80383350 = 0x80383350;
lbl_8038336c = 0x8038336c;
lbl_80383388 = 0x80383388;
lbl_80383398 = 0x80383398;
lbl_803833b8 = 0x803833b8;
lbl_803833cc = 0x803833cc;
lbl_803833e0 = 0x803833e0;
lbl_803833f4 = 0x803833f4;
lbl_80383404 = 0x80383404;
lbl_80383420 = 0x80383420;
lbl_803e7ff0 = 0x803e7ff0;
SECTIONS {
  .text.s8_static_init_800c3d78 0x800c3d78 : { *(.text.s8_static_init_800c3d78) }
  .sdata 0x804aaddc (NOLOAD) : {
    . = 0x0; lbl_804aaddc = .;
    . = 0x38dc; lbl_804ae6b8 = .;
    . = 0x38e0; lbl_804ae6bc = .;
    . = 0x38e4; lbl_804ae6c0 = .;
    . = 0x38e8; lbl_804ae6c4 = .;
    . = 0x38ec; lbl_804ae6c8 = .;
    . = 0x38f0; lbl_804ae6cc = .;
    . = 0x38f4; lbl_804ae6d0 = .;
    . = 0x38f8; lbl_804ae6d4 = .;
    . = 0x38fc; lbl_804ae6d8 = .;
    . = 0x3900; lbl_804ae6dc = .;
    . = 0x3908; lbl_804ae6e4 = .;
    . = 0x3910; lbl_804ae6ec = .;
    . = 0x3918; lbl_804ae6f4 = .;
    . = 0x3920; lbl_804ae6fc = .;
    . = 0x3928; lbl_804ae704 = .;
    . = 0x3930; lbl_804ae70c = .;
    . = 0x3938; lbl_804ae714 = .;
    . = 0x3940; lbl_804ae71c = .;
    . = 0x3948; lbl_804ae724 = .;
    . = 0x3950; lbl_804ae72c = .;
    . = 0x3958; lbl_804ae734 = .;
    . = 0x3960; lbl_804ae73c = .;
    . = 0x3968; lbl_804ae744 = .;
    . = 0x3970; lbl_804ae74c = .;
    . = 0x3978; lbl_804ae754 = .;
    . = 0x3980; lbl_804ae75c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
