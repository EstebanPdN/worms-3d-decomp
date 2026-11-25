/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12a_apply_five_vectors_800246e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
read_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.w3d_cx12a_apply_five_vectors_800246e4 0x800246e4 : { *(.text.w3d_cx12a_apply_five_vectors_800246e4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
