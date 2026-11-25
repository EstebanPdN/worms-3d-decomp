/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800a5394)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a4fd4 = 0x800a4fd4;
fn_8015f518 = 0x8015f518;
fn_8016115c = 0x8016115c;
lbl_803607b0 = 0x803607b0;
lbl_80361860 = 0x80361860;
lbl_80381028 = 0x80381028;
lbl_8038103c = 0x8038103c;
lbl_80381048 = 0x80381048;
lbl_80381054 = 0x80381054;
lbl_80381068 = 0x80381068;
lbl_8038107c = 0x8038107c;
lbl_80381098 = 0x80381098;
lbl_803e7e84 = 0x803e7e84;
SECTIONS {
  .text.s8_static_init_800a5394 0x800a5394 : { *(.text.s8_static_init_800a5394) }
  .sdata 0x804aac48 (NOLOAD) : {
    . = 0x0; lbl_804aac48 = .;
    . = 0x35d4; lbl_804ae21c = .;
    . = 0x35d8; lbl_804ae220 = .;
    . = 0x35dc; lbl_804ae224 = .;
    . = 0x35e0; lbl_804ae228 = .;
    . = 0x35e4; lbl_804ae22c = .;
    . = 0x35e8; lbl_804ae230 = .;
    . = 0x35ec; lbl_804ae234 = .;
    . = 0x35f0; lbl_804ae238 = .;
    . = 0x35f4; lbl_804ae23c = .;
    . = 0x35f8; lbl_804ae240 = .;
    . = 0x3600; lbl_804ae248 = .;
    . = 0x3608; lbl_804ae250 = .;
    . = 0x3610; lbl_804ae258 = .;
    . = 0x3618; lbl_804ae260 = .;
    . = 0x3620; lbl_804ae268 = .;
    . = 0x3628; lbl_804ae270 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
