/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(reallocate_map__12W3dPtrDequeAUib)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memmove = 0x802eeef4;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.reallocate_map__12W3dPtrDequeAUib 0x803536d0 : { *(.text.reallocate_map__12W3dPtrDequeAUib) }
  .text.reallocate_map__12W3dPtrDequeBUib 0x8035ef1c : { *(.text.reallocate_map__12W3dPtrDequeBUib) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
