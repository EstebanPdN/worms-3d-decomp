/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32f_scroll_bar_message_80294a60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80069a50 = 0x80069a50;
fn_8015f65c = 0x8015f65c;
fn_8015fb34 = 0x8015fb34;
fn_802950c8 = 0x802950c8;
fn_80295204 = 0x80295204;
fn_80296410 = 0x80296410;
fn_80296598 = 0x80296598;
fn_8029662c = 0x8029662c;
lbl_803d0778 = 0x803d0778;
lbl_803d077c = 0x803d077c;
lbl_803d0780 = 0x803d0780;
lbl_803d0784 = 0x803d0784;
lbl_803d0788 = 0x803d0788;
SECTIONS {
  .text.d32f_scroll_bar_message_80294a60 0x80294a60 : { *(.text.d32f_scroll_bar_message_80294a60) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; lbl_804aac54 = .;
    . = 0xef4; lbl_804abb48 = .;
    . = 0xf08; lbl_804abb5c = .;
    . = 0x6108; lbl_804b0d5c = .;
    . = 0x6110; lbl_804b0d64 = .;
    . = 0x6118; lbl_804b0d6c = .;
    . = 0x6120; lbl_804b0d74 = .;
    . = 0x6128; lbl_804b0d7c = .;
    . = 0x6130; lbl_804b0d84 = .;
    . = 0x6140; lbl_804b0d94 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
