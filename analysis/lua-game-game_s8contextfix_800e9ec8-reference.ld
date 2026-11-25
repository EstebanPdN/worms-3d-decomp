/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_initialize_message_flags_800e9ec8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800E7D4C = 0x800e7d4c;
fn_8015F518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_80360DE0 = 0x80360de0;
lbl_803617D0 = 0x803617d0;
lbl_8038B2A8 = 0x8038b2a8;
lbl_8038B2B8 = 0x8038b2b8;
lbl_8038B2C4 = 0x8038b2c4;
lbl_8038B2D4 = 0x8038b2d4;
lbl_8038B2E4 = 0x8038b2e4;
lbl_8038B2F4 = 0x8038b2f4;
lbl_8038B304 = 0x8038b304;
lbl_8038B318 = 0x8038b318;
lbl_8038B330 = 0x8038b330;
lbl_8038B340 = 0x8038b340;
lbl_8038B350 = 0x8038b350;
lbl_8038B360 = 0x8038b360;
lbl_8038B37C = 0x8038b37c;
lbl_8038B390 = 0x8038b390;
lbl_803E8220 = 0x803e8220;
SECTIONS {
  .text.s8_initialize_message_flags_800e9ec8 0x800e9ec8 : { *(.text.s8_initialize_message_flags_800e9ec8) }
  .sdata 0x804aee50 (NOLOAD) : {
    . = 0x0; lbl_804AEE50 = .;
    . = 0x1; lbl_804AEE51 = .;
    . = 0x2; lbl_804AEE52 = .;
    . = 0x3; lbl_804AEE53 = .;
    . = 0x4; lbl_804AEE54 = .;
    . = 0x5; lbl_804AEE55 = .;
    . = 0x6; lbl_804AEE56 = .;
    . = 0x7; lbl_804AEE57 = .;
    . = 0x8; lbl_804AEE58 = .;
    . = 0x10; lbl_804AEE60 = .;
    . = 0x18; lbl_804AEE68 = .;
    . = 0x20; lbl_804AEE70 = .;
    . = 0x28; lbl_804AEE78 = .;
    . = 0x30; lbl_804AEE80 = .;
    . = 0x38; lbl_804AEE88 = .;
    . = 0x40; lbl_804AEE90 = .;
    . = 0x48; lbl_804AEE98 = .;
    . = 0x50; lbl_804AEEA0 = .;
    . = 0x58; lbl_804AEEA8 = .;
    . = 0x60; lbl_804AEEB0 = .;
    . = 0x68; lbl_804AEEB8 = .;
    . = 0x70; lbl_804AEEC0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
