/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_reset_vectors_80092ed4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
read_80178ec4 = 0x80178ec4;
refresh_800d2f64 = 0x800d2f64;
zero_8037e90c = 0x8037e90c;
SECTIONS {
  .text.w3d_cx14a_reset_vectors_80092ed4 0x80092ed4 : { *(.text.w3d_cx14a_reset_vectors_80092ed4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
