/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33f_card_slot_display_80288c7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80289290 = 0x80289290;
fn_802fb7ac = 0x802fb7ac;
lbl_803cf960 = 0x803cf960;
lbl_803cf970 = 0x803cf970;
lbl_803cf980 = 0x803cf980;
lbl_803cf98c = 0x803cf98c;
lbl_803cf990 = 0x803cf990;
lbl_803cf994 = 0x803cf994;
lbl_803cf9a8 = 0x803cf9a8;
lbl_803cf9c0 = 0x803cf9c0;
s9_fill_values_8018d434 = 0x8018d434;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_cc29b_fill_text_8018d35c = 0x8018d35c;
w3d_format_into_8035eb0c = 0x8035eb0c;
w3d_s4_card_set_name = 0x80289d70;
w3d_table_find_record_8028924c = 0x8028924c;
SECTIONS {
  .text.d33f_card_slot_display_80288c7c 0x80288c7c : { *(.text.d33f_card_slot_display_80288c7c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
