/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800b06d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
lbl_80382384 = 0x80382384;
SECTIONS {
  .text.s8_static_init_800b06d8 0x800b06d8 : { *(.text.s8_static_init_800b06d8) }
  .sdata 0x804aacb4 (NOLOAD) : {
    . = 0x0; lbl_804aacb4 = .;
    . = 0x3788; lbl_804ae43c = .;
    . = 0x378c; lbl_804ae440 = .;
    . = 0x3790; lbl_804ae444 = .;
    . = 0x3794; lbl_804ae448 = .;
    . = 0x3798; lbl_804ae44c = .;
    . = 0x379c; lbl_804ae450 = .;
    . = 0x37a0; lbl_804ae454 = .;
    . = 0x37a4; lbl_804ae458 = .;
    . = 0x37a8; lbl_804ae45c = .;
    . = 0x37ac; lbl_804ae460 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
