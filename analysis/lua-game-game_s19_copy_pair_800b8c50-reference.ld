/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_copy_pair_800b8c50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_copy_pair_800b8c50 0x800b8c50 : { *(.text.s19_copy_pair_800b8c50) }
  .text.s19_copy_pair_800b8ca0 0x800b8ca0 : { *(.text.s19_copy_pair_800b8ca0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
