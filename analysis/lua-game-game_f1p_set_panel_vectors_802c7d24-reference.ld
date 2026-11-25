/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_panel_vectors_802c7d24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
value_803d8e1c = 0x803d8e1c;
value_803d8e20 = 0x803d8e20;
value_803d8e24 = 0x803d8e24;
SECTIONS {
  .text.w3d_set_panel_vectors_802c7d24 0x802c7d24 : { *(.text.w3d_set_panel_vectors_802c7d24) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
