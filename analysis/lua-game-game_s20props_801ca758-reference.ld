/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801ca758)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ecc6c = 0x801ecc6c;
fn_801efd34 = 0x801efd34;
fn_801efd98 = 0x801efd98;
fn_801f2420 = 0x801f2420;
fn_801f25b0 = 0x801f25b0;
lbl_803adc88 = 0x803adc88;
lbl_803adc94 = 0x803adc94;
lbl_803adca8 = 0x803adca8;
lbl_803adccc = 0x803adccc;
lbl_803adcdc = 0x803adcdc;
lbl_803adcec = 0x803adcec;
lbl_8045d6c4 = 0x8045d6c4;
lbl_8045d6d8 = 0x8045d6d8;
lbl_8045d6ec = 0x8045d6ec;
lbl_8045d700 = 0x8045d700;
lbl_8045d714 = 0x8045d714;
lbl_8045e29c = 0x8045e29c;
lbl_8045e47c = 0x8045e47c;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed34 = 0x8045ed34;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801ca758 0x801ca758 : { *(.text.w3d_s20_register_properties_801ca758) }
  .sdata 0x804b04f8 (NOLOAD) : {
    . = 0x0; lbl_804b04f8 = .;
    . = 0x4; lbl_804b04fc = .;
    . = 0x8; lbl_804b0500 = .;
    . = 0xc; lbl_804b0504 = .;
    . = 0x10; lbl_804b0508 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
