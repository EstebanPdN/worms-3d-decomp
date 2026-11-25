/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s11_reset_vectors_802bc020)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8045E788 = 0x8045e788;
SECTIONS {
  .text.s11_reset_vectors_802bc020 0x802bc020 : { *(.text.s11_reset_vectors_802bc020) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
