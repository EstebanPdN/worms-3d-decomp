/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_writer_reset_80204850)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8035b84c = 0x8035b84c;
w3d_auto_8035b8a4 = 0x8035b8a4;
SECTIONS {
  .text.w3d_d28e_writer_reset_80204850 0x80204850 : { *(.text.w3d_d28e_writer_reset_80204850) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
