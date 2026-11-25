/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19b_register_properties_8023b0ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eb674 = 0x801eb674;
fn_801ebf38 = 0x801ebf38;
fn_801ec0f8 = 0x801ec0f8;
fn_801ecc6c = 0x801ecc6c;
fn_801eff8c = 0x801eff8c;
lbl_803bba80 = 0x803bba80;
lbl_803bbab0 = 0x803bbab0;
lbl_803bbae8 = 0x803bbae8;
lbl_803bbb20 = 0x803bbb20;
lbl_803bbb58 = 0x803bbb58;
lbl_803bbb7c = 0x803bbb7c;
lbl_803bbba4 = 0x803bbba4;
lbl_803bbbd4 = 0x803bbbd4;
lbl_803bbc10 = 0x803bbc10;
lbl_803bbc50 = 0x803bbc50;
lbl_803bbc8c = 0x803bbc8c;
lbl_803bbcc0 = 0x803bbcc0;
lbl_803bbcf4 = 0x803bbcf4;
lbl_803bbd2c = 0x803bbd2c;
lbl_80400c2c = 0x80400c2c;
lbl_8045e004 = 0x8045e004;
lbl_80464c34 = 0x80464c34;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc19b_register_properties_8023b0ec 0x8023b0ec : { *(.text.w3d_cc19b_register_properties_8023b0ec) }
  .sdata 0x804b0838 (NOLOAD) : {
    . = 0x0; lbl_804b0838 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
