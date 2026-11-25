/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(initialize_map__16W3dPtrDequeBaseAUi)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_h1_fill_allocated_blocks_80353454 = 0x80353454;
w3d_h1_fill_allocated_blocks_8035ec0c = 0x8035ec0c;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
SECTIONS {
  .text.initialize_map__16W3dPtrDequeBaseAUi 0x803534b0 : { *(.text.initialize_map__16W3dPtrDequeBaseAUi) }
  .text.initialize_map__16W3dPtrDequeBaseBUi 0x8035ec68 : { *(.text.initialize_map__16W3dPtrDequeBaseBUi) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
