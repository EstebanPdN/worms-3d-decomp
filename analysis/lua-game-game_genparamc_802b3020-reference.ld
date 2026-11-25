/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_triple_802b3020)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_set_triple_802b3020 0x802b3020 : { *(.text.w3d_set_triple_802b3020) }
  .text.w3d_set_triple_802c61fc 0x802c61fc : { *(.text.w3d_set_triple_802c61fc) }
  .text.w3d_set_triple_802c71d8 0x802c71d8 : { *(.text.w3d_set_triple_802c71d8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
