/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_hud_text_start_8011ae58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_as_text_80343580 = 0x80343580;
d24i_cached_id_8015f5a0 = 0x8015f5a0;
d24i_five_8039ae84 = 0x8039ae84;
d24i_hud_properties_8011adf8 = 0x8011adf8;
d24i_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d24i_hud_text_start_8011ae58 0x8011ae58 : { *(.text.d24i_hud_text_start_8011ae58) }
  .sdata 0x804af3a8 (NOLOAD) : {
    . = 0x0; d24i_message_804af3a8 = .;
    . = 0x8; d24i_setting_804af3b0 = .;
    . = 0xc; d24i_setting_804af3b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
