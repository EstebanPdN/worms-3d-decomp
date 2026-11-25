/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k1a_popup_set_mode_8004eae4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_hud_properties_8011adf8 = 0x8011adf8;
SECTIONS {
  .text.k1a_popup_set_mode_8004eae4 0x8004eae4 : { *(.text.k1a_popup_set_mode_8004eae4) }
  .sdata 0x804af3b4 (NOLOAD) : {
    . = 0x0; w3d_color_804af3b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
