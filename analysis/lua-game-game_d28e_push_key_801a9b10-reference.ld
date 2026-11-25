/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_push_key_801a9b10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
free_802134fc = 0x802134fc;
w3d_handle_storage_fallback_803413d8 = 0x803413d8;
SECTIONS {
  .text.w3d_d28e_push_key_801a9b10 0x801a9b10 : { *(.text.w3d_d28e_push_key_801a9b10) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
