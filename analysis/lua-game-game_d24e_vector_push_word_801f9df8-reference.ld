/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24e_vector_push_word_801f9df8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memmove = 0x802eeef4;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d24e_vector_push_word_801f9df8 0x801f9df8 : { *(.text.w3d_d24e_vector_push_word_801f9df8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
