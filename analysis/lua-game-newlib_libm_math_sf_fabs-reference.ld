/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(fabsf)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.fabsf 0x802e87b0 : { *(.text.fabsf) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
