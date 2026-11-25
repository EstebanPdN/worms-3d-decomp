/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24f_word_vector_fill_insert_80344380)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memmove = 0x802eeef4;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.d24f_word_vector_fill_insert_80344380 0x80344380 : { *(.text.d24f_word_vector_fill_insert_80344380) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
