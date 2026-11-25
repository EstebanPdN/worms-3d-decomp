/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_vec_offset_8001bbb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_8036b074 = 0x8036b074;
w3d_f32_8036b078 = 0x8036b078;
SECTIONS {
  .text.k5a_vec_offset_8001bbb0 0x8001bbb0 : { *(.text.k5a_vec_offset_8001bbb0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
