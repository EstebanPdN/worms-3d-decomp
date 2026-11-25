/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33f_editor_key_dispatch_80278e38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef380 = 0x801ef380;
fn_80271c94 = 0x80271c94;
fn_80272644 = 0x80272644;
fn_80272968 = 0x80272968;
fn_80272cc0 = 0x80272cc0;
fn_80272e28 = 0x80272e28;
fn_80273054 = 0x80273054;
fn_80273560 = 0x80273560;
fn_802737d8 = 0x802737d8;
fn_80273af0 = 0x80273af0;
fn_80273dc4 = 0x80273dc4;
fn_8027410c = 0x8027410c;
fn_80274328 = 0x80274328;
fn_80274724 = 0x80274724;
fn_80274a4c = 0x80274a4c;
fn_80274e4c = 0x80274e4c;
fn_80275320 = 0x80275320;
fn_802757c0 = 0x802757c0;
fn_80275b08 = 0x80275b08;
fn_802761b8 = 0x802761b8;
fn_8027aa3c = 0x8027aa3c;
fn_8027ae70 = 0x8027ae70;
lbl_80365b28 = 0x80365b28;
lbl_80365b78 = 0x80365b78;
lbl_80365bc8 = 0x80365bc8;
lbl_80365c18 = 0x80365c18;
lbl_80365c68 = 0x80365c68;
lbl_80365cb8 = 0x80365cb8;
lbl_80365d08 = 0x80365d08;
lbl_80365d58 = 0x80365d58;
lbl_80365da8 = 0x80365da8;
lbl_80365df8 = 0x80365df8;
lbl_80365e48 = 0x80365e48;
lbl_80365e98 = 0x80365e98;
lbl_80365ee8 = 0x80365ee8;
lbl_80365f38 = 0x80365f38;
lbl_80365f88 = 0x80365f88;
lbl_80365fd8 = 0x80365fd8;
lbl_80366028 = 0x80366028;
lbl_80366078 = 0x80366078;
strchr = 0x802ef198;
w3d_auto_8027a98c = 0x8027a98c;
SECTIONS {
  .text.d33f_editor_key_dispatch_80278e38 0x80278e38 : { *(.text.d33f_editor_key_dispatch_80278e38) }
  .sdata 0x804abb9c (NOLOAD) : {
    . = 0x0; lbl_804abb9c = .;
    . = 0x4; lbl_804abba0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
