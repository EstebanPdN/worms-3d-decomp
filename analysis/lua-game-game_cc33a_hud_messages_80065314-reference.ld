/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc33a_hud_messages_80065314)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc33a_base_8015fb34 = 0x8015fb34;
cc33a_clear_800654bc = 0x800654bc;
cc33a_equal_8015f65c = 0x8015f65c;
cc33a_init_800656b4 = 0x800656b4;
cc33a_refresh_80065ce0 = 0x80065ce0;
cc33a_stamp_800664c4 = 0x800664c4;
cc33a_update_800664f8 = 0x800664f8;
SECTIONS {
  .text.cc33a_hud_messages_80065314 0x80065314 : { *(.text.cc33a_hud_messages_80065314) }
  .sdata 0x804ad558 (NOLOAD) : {
    . = 0x0; cc33a_cache_804ad558 = .;
    . = 0x8; cc33a_cache_804ad560 = .;
    . = 0x10; cc33a_cache_804ad568 = .;
    . = 0x18; cc33a_cache_804ad570 = .;
    . = 0x20; cc33a_cache_804ad578 = .;
    . = 0x28; cc33a_cache_804ad580 = .;
    . = 0x30; cc33a_cache_804ad588 = .;
    . = 0x38; cc33a_cache_804ad590 = .;
    . = 0x40; cc33a_cache_804ad598 = .;
    . = 0x48; cc33a_cache_804ad5a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
