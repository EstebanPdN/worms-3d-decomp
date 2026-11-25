/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_release_four_80051748)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_release_four_80051748 0x80051748 : { *(.text.s19_release_four_80051748) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
