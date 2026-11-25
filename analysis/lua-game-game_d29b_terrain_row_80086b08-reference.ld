/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29b_row_80086b08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_draw_80086660 = 0x80086660;
SECTIONS {
  .text.w3d_d29b_row_80086b08 0x80086b08 : { *(.text.w3d_d29b_row_80086b08) }
  .rodata 0x8037d0b8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
