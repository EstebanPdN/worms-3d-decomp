/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b37_fade_800f1b58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8038c3f8 = 0x8038c3f8;
lbl_8038c3fc = 0x8038c3fc;
lbl_8038c400 = 0x8038c400;
SECTIONS {
  .text.tsonnet_b37_fade_800f1b58 0x800f1b58 : { *(.text.tsonnet_b37_fade_800f1b58) }
  .rodata 0x8038c3f0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
