/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18a_cursor_inline_sinit_8004e690)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8004da40 = 0x8004da40;
fn_8015f518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_803600f0 = 0x803600f0;
lbl_803617d0 = 0x803617d0;
lbl_803777d0 = 0x803777d0;
lbl_803777e4 = 0x803777e4;
lbl_803777fc = 0x803777fc;
lbl_8037781c = 0x8037781c;
lbl_80377834 = 0x80377834;
lbl_80377848 = 0x80377848;
lbl_803e7a94 = 0x803e7a94;
SECTIONS {
  .text.w3d_cc18a_cursor_inline_sinit_8004e690 0x8004e690 : { *(.text.w3d_cc18a_cursor_inline_sinit_8004e690) }
  .sdata 0x804ad424 (NOLOAD) : {
    . = 0x0; lbl_804ad424 = .;
    . = 0x8; lbl_804ad42c = .;
    . = 0x10; lbl_804ad434 = .;
    . = 0x18; lbl_804ad43c = .;
    . = 0x20; lbl_804ad444 = .;
    . = 0x28; lbl_804ad44c = .;
    . = 0x30; lbl_804ad454 = .;
    . = 0x34; lbl_804ad458 = .;
    . = 0x38; lbl_804ad45c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
