/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27i_panel_fade_message_8011ddb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fb34 = 0x8015fb34;
ctx_80165254 = 0x80165254;
same_8015f65c = 0x8015f65c;
start_8011e4fc = 0x8011e4fc;
stop_8011f2e8 = 0x8011f2e8;
SECTIONS {
  .text.d27i_panel_fade_message_8011ddb0 0x8011ddb0 : { *(.text.d27i_panel_fade_message_8011ddb0) }
  .rodata 0x8039b348 : { *(.rodata) }
  .sdata 0x804af474 (NOLOAD) : {
    . = 0x0; msg_804af474 = .;
    . = 0x2314; game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
