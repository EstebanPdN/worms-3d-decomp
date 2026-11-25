/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17a_refresh_label_80048fcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
dispatch_80164514 = 0x80164514;
lookup_80164fc8 = 0x80164fc8;
offset_8037673c = 0x8037673c;
publish_8011adf8 = 0x8011adf8;
service_8020b680 = 0x8020b680;
service_80410a10 = 0x80410a10;
SECTIONS {
  .text.w3d_cc17a_refresh_label_80048fcc 0x80048fcc : { *(.text.w3d_cc17a_refresh_label_80048fcc) }
  .sdata 0x804af3b4 (NOLOAD) : {
    . = 0x0; style_804af3b4 = .;
    . = 0x23d8; context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
