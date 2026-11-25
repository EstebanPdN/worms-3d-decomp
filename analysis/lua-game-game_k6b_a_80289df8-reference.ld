/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_card_saver_save_80289df8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80288bc8 = 0x80288bc8;
fn_802fb7ac = 0x802fb7ac;
lbl_803cfa48 = 0x803cfa48;
w3d_auto_802aba18 = 0x802aba18;
w3d_s4_card_unsubscribe_navigation = 0x8028a4a8;
SECTIONS {
  .text.w3d_k6b_card_saver_save_80289df8 0x80289df8 : { *(.text.w3d_k6b_card_saver_save_80289df8) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; lbl_804abb5c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
