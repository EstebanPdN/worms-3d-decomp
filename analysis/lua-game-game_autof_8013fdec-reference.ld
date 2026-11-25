/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8013fdec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A830C = 0x800a830c;
fn_801359EC = 0x801359ec;
fn_8013BD0C = 0x8013bd0c;
fn_8013FECC = 0x8013fecc;
fn_8015C384 = 0x8015c384;
fn_8015CDEC = 0x8015cdec;
fn_8015EA78 = 0x8015ea78;
fn_8015F4CC = 0x8015f4cc;
fn_80162C20 = 0x80162c20;
fn_8020C5C0 = 0x8020c5c0;
fn_8020EE9C = 0x8020ee9c;
fn_8020FBD0 = 0x8020fbd0;
fn_80341884 = 0x80341884;
fn_80343584 = 0x80343584;
lbl_803616B0 = 0x803616b0;
lbl_803616E0 = 0x803616e0;
lbl_80361710 = 0x80361710;
lbl_8039EEC4 = 0x8039eec4;
lbl_8039EECC = 0x8039eecc;
lbl_8039FE2C = 0x8039fe2c;
lbl_8039FE30 = 0x8039fe30;
lbl_8039FE34 = 0x8039fe34;
lbl_803E8744 = 0x803e8744;
lbl_803E8760 = 0x803e8760;
lbl_803E877C = 0x803e877c;
lbl_80455170 = 0x80455170;
lbl_80455190 = 0x80455190;
lbl_804551D8 = 0x804551d8;
SECTIONS {
  .text.w3d_auto_8013fdec 0x8013fdec : { *(.text.w3d_auto_8013fdec) }
  .text.w3d_auto_8015bd38 0x8015bd38 : { *(.text.w3d_auto_8015bd38) }
  .text.w3d_auto_8015c300 0x8015c300 : { *(.text.w3d_auto_8015c300) }
  .text.w3d_auto_8015c3fc 0x8015c3fc : { *(.text.w3d_auto_8015c3fc) }
  .text.w3d_auto_8015cd64 0x8015cd64 : { *(.text.w3d_auto_8015cd64) }
  .text.w3d_auto_8015eae0 0x8015eae0 : { *(.text.w3d_auto_8015eae0) }
  .text.w3d_auto_8015f69c 0x8015f69c : { *(.text.w3d_auto_8015f69c) }
  .sdata 0x804ab304 (NOLOAD) : {
    . = 0x0; lbl_804AB304 = .;
    . = 0x4; lbl_804AB308 = .;
    . = 0x4d54; lbl_804B0058 = .;
    . = 0x4dbc; lbl_804B00C0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
