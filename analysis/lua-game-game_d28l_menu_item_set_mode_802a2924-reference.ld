/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_menu_item_set_mode_802a2924)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80164514 = 0x80164514;
fn_8020b680 = 0x8020b680;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c0 = 0x8020c5c0;
fn_802a0cc0 = 0x802a0cc0;
fn_802b1258 = 0x802b1258;
fn_802b1880 = 0x802b1880;
fn_802c2aac = 0x802c2aac;
fn_802c4498 = 0x802c4498;
fn_802c4a60 = 0x802c4a60;
fn_802c4a70 = 0x802c4a70;
fn_802c4d34 = 0x802c4d34;
fn_802c4d3c = 0x802c4d3c;
fn_802c4eb0 = 0x802c4eb0;
fn_802c4f28 = 0x802c4f28;
fn_80341884 = 0x80341884;
service_8041c8d0 = 0x8041c8d0;
SECTIONS {
  .text.d28l_menu_item_set_mode_802a2924 0x802a2924 : { *(.text.d28l_menu_item_set_mode_802a2924) }
  .rodata 0x803d1fd8 : { *(.rodata) }
  .sdata 0x804abc68 (NOLOAD) : {
    . = 0x0; active_804abc68 = .;
    . = 0x5b20; settings_804b1788 = .;
    . = 0x5b24; manager_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
