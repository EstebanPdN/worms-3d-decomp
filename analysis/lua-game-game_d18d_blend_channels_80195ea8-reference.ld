/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d18d_blend_channels_80195ea8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_blend_evaluate_801961a8 = 0x801961a8;
SECTIONS {
  .text.d18d_blend_channels_80195ea8 0x80195ea8 : { *(.text.d18d_blend_channels_80195ea8) }
  .rodata 0x803a84a0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
