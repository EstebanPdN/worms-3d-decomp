/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_descriptor_write_array_80200714)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
descriptor_80200460 = 0x80200460;
prepare_80200884 = 0x80200884;
SECTIONS {
  .text.w3d_cx11b_descriptor_write_array_80200714 0x80200714 : { *(.text.w3d_cx11b_descriptor_write_array_80200714) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
