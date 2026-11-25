/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r23b_ratio_802bfa40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
r23b_ratio_limit_803d8414 = 0x803d8414;
SECTIONS {
  .text.w3d_r23b_ratio_802bfa40 0x802bfa40 : { *(.text.w3d_r23b_ratio_802bfa40) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
