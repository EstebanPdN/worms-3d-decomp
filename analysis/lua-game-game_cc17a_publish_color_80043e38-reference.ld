/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17a_publish_color_80043e38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
apply_8011adf8 = 0x8011adf8;
lookup_80164fc8 = 0x80164fc8;
scale_80374e28 = 0x80374e28;
SECTIONS {
  .text.w3d_cc17a_publish_color_80043e38 0x80043e38 : { *(.text.w3d_cc17a_publish_color_80043e38) }
  .sdata 0x804af3b4 (NOLOAD) : {
    . = 0x0; text_804af3b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
