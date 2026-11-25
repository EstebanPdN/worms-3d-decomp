/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d35f_card_screen_update_80288564)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8018d35c = 0x8018d35c;
fn_8018d434 = 0x8018d434;
fn_801fe3b0 = 0x801fe3b0;
fn_80288c7c = 0x80288c7c;
fn_80289914 = 0x80289914;
fn_80289df8 = 0x80289df8;
fn_80289eec = 0x80289eec;
fn_802aba0c = 0x802aba0c;
fn_802aba68 = 0x802aba68;
fn_802b30c0 = 0x802b30c0;
fn_802e88ac = 0x802e88ac;
fn_80344278 = 0x80344278;
lbl_803cf924 = 0x803cf924;
SECTIONS {
  .text.d35f_card_screen_update_80288564 0x80288564 : { *(.text.d35f_card_screen_update_80288564) }
  .rodata 0x803cf928 : { *(.rodata) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; lbl_804abb5c = .;
    . = 0x84; lbl_804abbe0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
