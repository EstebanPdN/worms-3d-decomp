/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10b_clear_controls_80265fb4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10b_clear_base_802b0fec = 0x802b0fec;
SECTIONS {
  .text.d10b_clear_controls_80265fb4 0x80265fb4 : { *(.text.d10b_clear_controls_80265fb4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
