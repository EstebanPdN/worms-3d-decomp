/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35f_word_vector_assign_80350ca8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35f_allocate_801907a8 = 0x801907a8;
sol35f_free_801907d0 = 0x801907d0;
sol35f_memmove_802eeef4 = 0x802eeef4;
SECTIONS {
  .text.sol35f_word_vector_assign_80350ca8 0x80350ca8 : { *(.text.sol35f_word_vector_assign_80350ca8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
