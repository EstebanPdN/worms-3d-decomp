/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f7a_menu_message_8028e224)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16F7aText_8020bb54PCc = 0x8020bb54;
fn_8010a8fc = 0x8010a8fc;
fn_8015f65c = 0x8015f65c;
fn_8016293c = 0x8016293c;
fn_8028e444 = 0x8028e444;
fn_8028e4f4 = 0x8028e4f4;
fn_8028e624 = 0x8028e624;
fn_8028e630 = 0x8028e630;
fn_8028e7e0 = 0x8028e7e0;
fn_8028e8ec = 0x8028e8ec;
fn_8028e9c0 = 0x8028e9c0;
fn_8028eb54 = 0x8028eb54;
fn_8028ebe0 = 0x8028ebe0;
SECTIONS {
  .text.w3d_f7a_menu_message_8028e224 0x8028e224 : { *(.text.w3d_f7a_menu_message_8028e224) }
  .sdata 0x804abb5c (NOLOAD) : {
    . = 0x0; depth_804abb5c = .;
    . = 0x5148; cache_804b0ca4 = .;
    . = 0x5150; cache_804b0cac = .;
    . = 0x5158; cache_804b0cb4 = .;
    . = 0x5160; cache_804b0cbc = .;
    . = 0x5168; cache_804b0cc4 = .;
    . = 0x5170; cache_804b0ccc = .;
    . = 0x5178; cache_804b0cd4 = .;
    . = 0x5188; cache_804b0ce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
