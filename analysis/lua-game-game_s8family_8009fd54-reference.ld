/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_initialize_8009fd54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8009EF38 = 0x8009ef38;
fn_8015F518 = 0x8015f518;
fn_8016115C = 0x8016115c;
lbl_80360690 = 0x80360690;
lbl_80360E10 = 0x80360e10;
lbl_8038079C = 0x8038079c;
lbl_803807B0 = 0x803807b0;
lbl_803807C4 = 0x803807c4;
lbl_803807DC = 0x803807dc;
lbl_803E7DDC = 0x803e7ddc;
SECTIONS {
  .text.s8_initialize_8009fd54 0x8009fd54 : { *(.text.s8_initialize_8009fd54) }
  .sdata 0x804aac0c (NOLOAD) : {
    . = 0x0; lbl_804AAC0C = .;
    . = 0x34d8; lbl_804AE0E4 = .;
    . = 0x34dc; lbl_804AE0E8 = .;
    . = 0x34e0; lbl_804AE0EC = .;
    . = 0x34e4; lbl_804AE0F0 = .;
    . = 0x34e8; lbl_804AE0F4 = .;
    . = 0x34ec; lbl_804AE0F8 = .;
    . = 0x34f0; lbl_804AE0FC = .;
    . = 0x34f4; lbl_804AE100 = .;
    . = 0x34f8; lbl_804AE104 = .;
    . = 0x34fc; lbl_804AE108 = .;
    . = 0x3504; lbl_804AE110 = .;
    . = 0x350c; lbl_804AE118 = .;
    . = 0x3514; lbl_804AE120 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
