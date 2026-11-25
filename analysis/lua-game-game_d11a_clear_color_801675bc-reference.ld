/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11a_clear_color_801675bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d11a_channel_scale_803a4e14 = 0x803a4e14;
d11a_set_copy_clear_80308fc0 = 0x80308fc0;
SECTIONS {
  .text.d11a_clear_color_801675bc 0x801675bc : { *(.text.d11a_clear_color_801675bc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
