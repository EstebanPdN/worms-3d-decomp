/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k11b_checked_index_801f9fbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_k11b_checked_index_801f9fbc 0x801f9fbc : { *(.text.w3d_k11b_checked_index_801f9fbc) }
  .text.w3d_k11b_reverse_bits_8021d7b0 0x8021d7b0 : { *(.text.w3d_k11b_reverse_bits_8021d7b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
