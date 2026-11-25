/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__17Mx16oaRenderState)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_vt.15Mx16oaStateRoot = 0x80411c88;
_vt.17Mx16oaRenderState = 0x80411c10;
w3d_matrix_8045e708 = 0x8045e708;
SECTIONS {
  .text.__17Mx16oaRenderState 0x80166d8c : { *(.text.__17Mx16oaRenderState) }
  .rodata 0x803a4d28 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
