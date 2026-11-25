/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_transfer_swapped16_80201a14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_transfer_swapped16_80201a14 0x80201a14 : { *(.text.w3d_transfer_swapped16_80201a14) }
  .text.w3d_transfer_swapped16_80201abc 0x80201abc : { *(.text.w3d_transfer_swapped16_80201abc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
