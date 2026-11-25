/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_landscape_services_clear_80269694)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
member_802b0fec = 0x802b0fec;
reset_8026c0d0 = 0x8026c0d0;
SECTIONS {
  .text.w3d_cx12b_landscape_services_clear_80269694 0x80269694 : { *(.text.w3d_cx12b_landscape_services_clear_80269694) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
