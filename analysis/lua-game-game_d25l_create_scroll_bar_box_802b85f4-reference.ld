/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25l_create_scroll_bar_box_802b85f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80164514 = 0x80164514;
fn_80295268 = 0x80295268;
fn_80295468 = 0x80295468;
fn_8029550c = 0x8029550c;
fn_8029623c = 0x8029623c;
fn_80296298 = 0x80296298;
fn_80296410 = 0x80296410;
fn_80296518 = 0x80296518;
fn_80296774 = 0x80296774;
fn_8029677c = 0x8029677c;
lbl_803d80c4 = 0x803d80c4;
lbl_8041c220 = 0x8041c220;
w3d_new_box_8020b680 = 0x8020b680;
w3d_s4_box_border_thickness_802966f8 = 0x802966f8;
SECTIONS {
  .text.d25l_create_scroll_bar_box_802b85f4 0x802b85f4 : { *(.text.d25l_create_scroll_bar_box_802b85f4) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
