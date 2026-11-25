/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc25a_vector_scaled_offsets_8001c134)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.cc25a_vector_scaled_offsets_8001c134 0x8001c134 : { *(.text.cc25a_vector_scaled_offsets_8001c134) }
  .rodata 0x8036b0a4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
