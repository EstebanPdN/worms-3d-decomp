/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_panel_stop_8011f2e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
format_803442b4 = 0x803442b4;
text_8039b40c = 0x8039b40c;
SECTIONS {
  .text.d27i_panel_stop_8011f2e8 0x8011f2e8 : { *(.text.d27i_panel_stop_8011f2e8) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; game_804b1788 = .;
    . = 0x64; sys_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
