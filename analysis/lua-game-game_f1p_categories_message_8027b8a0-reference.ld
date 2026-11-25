/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_categories_message_8027b8a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc230 = 0x800fc230;
fn_800fc43c = 0x800fc43c;
fn_8010a8fc = 0x8010a8fc;
fn_8015f65c = 0x8015f65c;
fn_8016293c = 0x8016293c;
fn_8027bd04 = 0x8027bd04;
fn_8027be70 = 0x8027be70;
fn_8027c480 = 0x8027c480;
fn_8027cc20 = 0x8027cc20;
fn_8027ddc4 = 0x8027ddc4;
fn_8027e038 = 0x8027e038;
fn_8027e1ec = 0x8027e1ec;
fn_8027e390 = 0x8027e390;
fn_8027eb24 = 0x8027eb24;
fn_8027f9c0 = 0x8027f9c0;
fn_8027fb34 = 0x8027fb34;
fn_8027fca8 = 0x8027fca8;
fn_8027ffdc = 0x8027ffdc;
fn_80280124 = 0x80280124;
fn_802814c4 = 0x802814c4;
fn_80281d0c = 0x80281d0c;
fn_80281ff0 = 0x80281ff0;
fn_802ef234 = 0x802ef234;
str_803ce964 = 0x803ce964;
str_803ce970 = 0x803ce970;
str_803ce97c = 0x803ce97c;
str_803ce988 = 0x803ce988;
str_803ce990 = 0x803ce990;
str_803ce998 = 0x803ce998;
str_803ce9a0 = 0x803ce9a0;
str_803ce9b8 = 0x803ce9b8;
str_803ce9c0 = 0x803ce9c0;
str_803ce9c8 = 0x803ce9c8;
str_803ce9cc = 0x803ce9cc;
str_803ce9d4 = 0x803ce9d4;
str_803ce9dc = 0x803ce9dc;
str_803ce9f0 = 0x803ce9f0;
str_803cea04 = 0x803cea04;
str_803cea18 = 0x803cea18;
SECTIONS {
  .text.w3d_categories_message_8027b8a0 0x8027b8a0 : { *(.text.w3d_categories_message_8027b8a0) }
  .sdata 0x804b0b3c (NOLOAD) : {
    . = 0x0; cache_804b0b3c = .;
    . = 0x8; cache_804b0b44 = .;
    . = 0x10; cache_804b0b4c = .;
    . = 0x18; cache_804b0b54 = .;
    . = 0x20; cache_804b0b5c = .;
    . = 0x28; cache_804b0b64 = .;
    . = 0x30; cache_804b0b6c = .;
    . = 0x38; cache_804b0b74 = .;
    . = 0x40; cache_804b0b7c = .;
    . = 0x48; cache_804b0b84 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
