/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f6a_change_menu_8028e7e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__14Cache_8015f704PCc = 0x8015f704;
change_803cfff0 = 0x803cfff0;
fn_800a7e14 = 0x800a7e14;
fn_800fde38 = 0x800fde38;
fn_8010a8e0 = 0x8010a8e0;
fn_80129878 = 0x80129878;
fn_8015f558 = 0x8015f558;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
menu_803d0000 = 0x803d0000;
SECTIONS {
  .text.w3d_f6a_change_menu_8028e7e0 0x8028e7e0 : { *(.text.w3d_f6a_change_menu_8028e7e0) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; global_804aaabc = .;
    . = 0x10a0; depth_804abb5c = .;
    . = 0x10a4; count_804abb60 = .;
    . = 0x6c98; queue_804b1754 = .;
    . = 0x6ccc; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
