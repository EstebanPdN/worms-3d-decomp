/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f6a_open_menu_8028e630)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Cache_8015f704PCc = 0x8015f704;
change_803cfff0 = 0x803cfff0;
factory_8041c890 = 0x8041c890;
fn_800a7e14 = 0x800a7e14;
fn_800fde38 = 0x800fde38;
fn_8010a8e0 = 0x8010a8e0;
fn_80129878 = 0x80129878;
fn_8015f558 = 0x8015f558;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80164514 = 0x80164514;
fn_8020b680 = 0x8020b680;
fn_8020bb2c = 0x8020bb2c;
fn_8020bd38 = 0x8020bd38;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802c1bd8 = 0x802c1bd8;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
menu_803d0000 = 0x803d0000;
SECTIONS {
  .text.w3d_f6a_open_menu_8028e630 0x8028e630 : { *(.text.w3d_f6a_open_menu_8028e630) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; global_804aaabc = .;
    . = 0x10a0; depth_804abb5c = .;
    . = 0x10a4; count_804abb60 = .;
    . = 0x6c98; queue_804b1754 = .;
    . = 0x6ccc; app_804b1788 = .;
    . = 0x6cd0; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
