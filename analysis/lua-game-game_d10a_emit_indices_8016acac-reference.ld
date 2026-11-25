/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10a_emit_indices_8016acac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10a_fifo_cc008000 = 0xcc008000;
SECTIONS {
  .text.d10a_emit_indices_8016acac 0x8016acac : { *(.text.d10a_emit_indices_8016acac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
