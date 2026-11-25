/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_initialize_800dc418)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800DA958 = 0x800da958;
fn_8015F518 = 0x8015f518;
fn_8016115C = 0x8016115c;
lbl_80360CC0 = 0x80360cc0;
lbl_80361860 = 0x80361860;
lbl_80389900 = 0x80389900;
lbl_80389918 = 0x80389918;
lbl_80389930 = 0x80389930;
lbl_80389948 = 0x80389948;
lbl_80389960 = 0x80389960;
lbl_80389978 = 0x80389978;
lbl_80389988 = 0x80389988;
lbl_8038999C = 0x8038999c;
lbl_803899B0 = 0x803899b0;
lbl_803899C8 = 0x803899c8;
lbl_803899E0 = 0x803899e0;
lbl_80389A00 = 0x80389a00;
lbl_80389A14 = 0x80389a14;
lbl_803E8178 = 0x803e8178;
SECTIONS {
  .text.s8_initialize_800dc418 0x800dc418 : { *(.text.s8_initialize_800dc418) }
  .sdata 0x804aae84 (NOLOAD) : {
    . = 0x0; lbl_804AAE84 = .;
    . = 0x3d1c; lbl_804AEBA0 = .;
    . = 0x3d20; lbl_804AEBA4 = .;
    . = 0x3d24; lbl_804AEBA8 = .;
    . = 0x3d28; lbl_804AEBAC = .;
    . = 0x3d2c; lbl_804AEBB0 = .;
    . = 0x3d30; lbl_804AEBB4 = .;
    . = 0x3d34; lbl_804AEBB8 = .;
    . = 0x3d38; lbl_804AEBBC = .;
    . = 0x3d3c; lbl_804AEBC0 = .;
    . = 0x3d40; lbl_804AEBC4 = .;
    . = 0x3d48; lbl_804AEBCC = .;
    . = 0x3d50; lbl_804AEBD4 = .;
    . = 0x3d58; lbl_804AEBDC = .;
    . = 0x3d60; lbl_804AEBE4 = .;
    . = 0x3d68; lbl_804AEBEC = .;
    . = 0x3d70; lbl_804AEBF4 = .;
    . = 0x3d78; lbl_804AEBFC = .;
    . = 0x3d80; lbl_804AEC04 = .;
    . = 0x3d88; lbl_804AEC0C = .;
    . = 0x3d90; lbl_804AEC14 = .;
    . = 0x3d98; lbl_804AEC1C = .;
    . = 0x3da0; lbl_804AEC24 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
