/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc40b_apply_channels_80195fb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc40b_default_803a84a4 = 0x803a84a4;
SECTIONS {
  .text.cc40b_apply_channels_80195fb0 0x80195fb0 : { *(.text.cc40b_apply_channels_80195fb0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
