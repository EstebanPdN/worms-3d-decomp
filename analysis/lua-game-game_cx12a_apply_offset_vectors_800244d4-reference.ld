/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12a_apply_offset_vectors_800244d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
read_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.w3d_cx12a_apply_offset_vectors_800244d4 0x800244d4 : { *(.text.w3d_cx12a_apply_offset_vectors_800244d4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
