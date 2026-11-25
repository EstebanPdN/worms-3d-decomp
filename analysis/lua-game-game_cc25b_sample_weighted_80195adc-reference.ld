/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc25b_sample_weighted_80195adc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc25b_constant_803a847c = 0x803a847c;
cc25b_fn_80195ea8 = 0x80195ea8;
cc25b_fn_80196038 = 0x80196038;
cc25b_fn_801979fc = 0x801979fc;
SECTIONS {
  .text.w3d_cc25b_sample_weighted_80195adc 0x80195adc : { *(.text.w3d_cc25b_sample_weighted_80195adc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
