/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_descriptor_visit_array_80200620)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
descriptor_80200460 = 0x80200460;
SECTIONS {
  .text.w3d_cx10b_descriptor_visit_array_80200620 0x80200620 : { *(.text.w3d_cx10b_descriptor_visit_array_80200620) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
