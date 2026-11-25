/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d42i_strike_begin_80119794)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
act_80020834 = 0x80020834;
alloc_801613f0 = 0x801613f0;
cond_80119aa8 = 0x80119aa8;
hand_800fc710 = 0x800fc710;
id_8015f5a0 = 0x8015f5a0;
info_800fc6dc = 0x800fc6dc;
msgi_80125fdc = 0x80125fdc;
msgp_800a82f0 = 0x800a82f0;
msgv_80126000 = 0x80126000;
place_800e5ca4 = 0x800e5ca4;
post_8016239c = 0x8016239c;
readv_800fc2f0 = 0x800fc2f0;
s_8039ab14 = 0x8039ab14;
s_8039ab2c = 0x8039ab2c;
s_8039ab90 = 0x8039ab90;
s_8039abb0 = 0x8039abb0;
val_80178c48 = 0x80178c48;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d42i_strike_begin_80119794 0x80119794 : { *(.text.d42i_strike_begin_80119794) }
  .rodata 0x8039abc0 : { *(.rodata) }
  .sdata 0x804af334 (NOLOAD) : {
    . = 0x0; c_804af334 = .;
    . = 0x18; c_804af34c = .;
    . = 0x30; c_804af364 = .;
    . = 0x38; c_804af36c = .;
    . = 0x40; c_804af374 = .;
    . = 0x58; c_804af38c = .;
    . = 0x2420; arena_804b1754 = .;
    . = 0x242c; ai_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
