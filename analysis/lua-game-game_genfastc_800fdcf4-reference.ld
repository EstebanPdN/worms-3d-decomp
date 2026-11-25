/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_init_timed_fade_800fdcf4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803d83f8 = 0x803d83f8;
lbl_803d83fc = 0x803d83fc;
lbl_803d8400 = 0x803d8400;
lbl_803d8404 = 0x803d8404;
lbl_803d8408 = 0x803d8408;
SECTIONS {
  .text.w3d_init_timed_fade_800fdcf4 0x800fdcf4 : { *(.text.w3d_init_timed_fade_800fdcf4) }
  .text.w3d_inverse_ratio_802bf798 0x802bf798 : { *(.text.w3d_inverse_ratio_802bf798) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
