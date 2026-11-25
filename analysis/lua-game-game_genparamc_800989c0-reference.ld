/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_derived_only_800989c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_80160038PvN21ii = 0x80160038;
__16W3dType_8016115cPvN21ii = 0x8016115c;
fn_80097fd8 = 0x80097fd8;
fn_800f1d58 = 0x800f1d58;
lbl_80360000 = 0x80360000;
lbl_803605d0 = 0x803605d0;
lbl_80360f30 = 0x80360f30;
lbl_803617d0 = 0x803617d0;
lbl_803e7d6c = 0x803e7d6c;
lbl_803e82e4 = 0x803e82e4;
SECTIONS {
  .text.w3d_sinit_derived_only_800989c0 0x800989c0 : { *(.text.w3d_sinit_derived_only_800989c0) }
  .text.w3d_sinit_derived_only_800f28d8 0x800f28d8 : { *(.text.w3d_sinit_derived_only_800f28d8) }
  .sdata 0x804aabbc (NOLOAD) : {
    . = 0x0; lbl_804aabbc = .;
    . = 0x364; lbl_804aaf20 = .;
    . = 0x33dc; lbl_804adf98 = .;
    . = 0x33e0; lbl_804adf9c = .;
    . = 0x33e4; lbl_804adfa0 = .;
    . = 0x33e8; lbl_804adfa4 = .;
    . = 0x33ec; lbl_804adfa8 = .;
    . = 0x33f0; lbl_804adfac = .;
    . = 0x33f4; lbl_804adfb0 = .;
    . = 0x33f8; lbl_804adfb4 = .;
    . = 0x33fc; lbl_804adfb8 = .;
    . = 0x44e4; lbl_804af0a0 = .;
    . = 0x44e8; lbl_804af0a4 = .;
    . = 0x44ec; lbl_804af0a8 = .;
    . = 0x44f0; lbl_804af0ac = .;
    . = 0x44f4; lbl_804af0b0 = .;
    . = 0x44f8; lbl_804af0b4 = .;
    . = 0x44fc; lbl_804af0b8 = .;
    . = 0x4500; lbl_804af0bc = .;
    . = 0x4504; lbl_804af0c0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
