/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_card_subscribe_navigation)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_auto_80162310 = 0x80162310;
w3d_cached_message_id = 0x8015f5a0;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.w3d_s4_card_subscribe_navigation 0x8028a3fc : { *(.text.w3d_s4_card_subscribe_navigation) }
  .text.w3d_s4_card_unsubscribe_navigation 0x8028a4a8 : { *(.text.w3d_s4_card_unsubscribe_navigation) }
  .text.w3d_s4_card_clear_resource 0x8028aab0 : { *(.text.w3d_s4_card_clear_resource) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; w3d_resource_count_804abb60 = .;
    . = 0x50b4; w3d_cache_804b0c14 = .;
    . = 0x50bc; w3d_cache_804b0c1c = .;
    . = 0x50c4; w3d_cache_804b0c24 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
