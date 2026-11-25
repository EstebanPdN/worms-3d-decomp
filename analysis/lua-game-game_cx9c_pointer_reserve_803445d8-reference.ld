/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_pointer_reserve_803445d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_allocate_80212fd4 = 0x80212fd4;
cx9c_fallback_803413d8 = 0x803413d8;
cx9c_free_802134fc = 0x802134fc;
cx9c_memmove_802eeef4 = 0x802eeef4;
SECTIONS {
  .text.w3d_cx9c_pointer_reserve_803445d8 0x803445d8 : { *(.text.w3d_cx9c_pointer_reserve_803445d8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
