/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25l_panel_scroller_create_802b8430)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24f_select_item_802bc8b4 = 0x802bc8b4;
fn_80164514 = 0x80164514;
lbl_803d80b0 = 0x803d80b0;
lbl_803d80c0 = 0x803d80c0;
lbl_8041c850 = 0x8041c850;
tsonnet_c31_text_size_802b1880 = 0x802b1880;
w3d_auto_80296378 = 0x80296378;
w3d_auto_80296410 = 0x80296410;
w3d_auto_802bc570 = 0x802bc570;
w3d_auto_802bc778 = 0x802bc778;
w3d_clamp_802bcbd8 = 0x802bcbd8;
w3d_nested_802bc71c = 0x802bc71c;
w3d_new_box_8020b680 = 0x8020b680;
w3d_paired_802bc098 = 0x802bc098;
w3d_panel_activity_802b879c = 0x802b879c;
w3d_set_802bcb6c = 0x802bcb6c;
w3d_set_802bcc40 = 0x802bcc40;
w3d_set_802bcd10 = 0x802bcd10;
w3d_set_position_802bc180 = 0x802bc180;
SECTIONS {
  .text.d25l_panel_scroller_create_802b8430 0x802b8430 : { *(.text.d25l_panel_scroller_create_802b8430) }
  .rodata 0x803d80b8 : { *(.rodata) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; lbl_804abb4c = .;
    . = 0x5c40; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
