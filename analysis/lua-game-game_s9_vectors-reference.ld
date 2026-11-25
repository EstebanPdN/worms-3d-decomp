/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_set_vector_8017b040)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s9_set_vector_8017b040 0x8017b040 : { *(.text.s9_set_vector_8017b040) }
  .text.s9_set_vector_8017b07c 0x8017b07c : { *(.text.s9_set_vector_8017b07c) }
  .text.s9_set_vector_8017b120 0x8017b120 : { *(.text.s9_set_vector_8017b120) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
