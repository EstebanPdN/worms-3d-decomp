/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_recovered_8009e750)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80052154 = 0x80052154;
fn_8009E58C = 0x8009e58c;
fn_8010A8E0 = 0x8010a8e0;
fn_8015A6B8 = 0x8015a6b8;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80181640 = 0x80181640;
fn_8018179C = 0x8018179c;
fn_80209920 = 0x80209920;
fn_8020C5C4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
lbl_803805C4 = 0x803805c4;
lbl_803805DC = 0x803805dc;
lbl_803805E4 = 0x803805e4;
lbl_803805F4 = 0x803805f4;
lbl_80380604 = 0x80380604;
lbl_80380610 = 0x80380610;
lbl_8038061C = 0x8038061c;
lbl_80380628 = 0x80380628;
lbl_80382264 = 0x80382264;
lbl_80382270 = 0x80382270;
lbl_8038B23C = 0x8038b23c;
lbl_8038B240 = 0x8038b240;
SECTIONS {
  .text.s8_recovered_8009e750 0x8009e750 : { *(.text.s8_recovered_8009e750) }
  .text.s8_recovered_800af220 0x800af220 : { *(.text.s8_recovered_800af220) }
  .text.s8_recovered_800afe58 0x800afe58 : { *(.text.s8_recovered_800afe58) }
  .text.s8_recovered_800e8f40 0x800e8f40 : { *(.text.s8_recovered_800e8f40) }
  .sdata 0x804aacac (NOLOAD) : {
    . = 0x0; lbl_804AACAC = .;
    . = 0x774; lbl_804AB420 = .;
    . = 0x3414; lbl_804AE0C0 = .;
    . = 0x341c; lbl_804AE0C8 = .;
    . = 0x3740; lbl_804AE3EC = .;
    . = 0x3748; lbl_804AE3F4 = .;
    . = 0x5398; lbl_804B0044 = .;
    . = 0x6aa8; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
