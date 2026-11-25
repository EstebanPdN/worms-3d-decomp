/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25l_text_list_scroll_box_802a047c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lString = 0x803426b8;
fn_80164514 = 0x80164514;
fn_80295268 = 0x80295268;
fn_80295468 = 0x80295468;
fn_8029550c = 0x8029550c;
fn_8029623c = 0x8029623c;
fn_80296378 = 0x80296378;
fn_80296518 = 0x80296518;
fn_80296774 = 0x80296774;
fn_8029677c = 0x8029677c;
fn_8029fc78 = 0x8029fc78;
fn_802b1880 = 0x802b1880;
fn_802e87d4 = 0x802e87d4;
lbl_8041c220 = 0x8041c220;
w3d_new_box_8020b680 = 0x8020b680;
w3d_remove_box_802a0664 = 0x802a0664;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d25l_text_list_scroll_box_802a047c 0x802a047c : { *(.text.d25l_text_list_scroll_box_802a047c) }
  .rodata 0x803d1e54 : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
