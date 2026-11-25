/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_screen_destroy_80036e68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040e5e8 = 0x8040e5e8;
w3d_auto_8025e0c4 = 0x8025e0c4;
w3d_s4_scroll_handle_destroy = 0x80293528;
w3d_service_destroy_801628ec = 0x801628ec;
SECTIONS {
  .text.s19_screen_destroy_80036e68 0x80036e68 : { *(.text.s19_screen_destroy_80036e68) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
