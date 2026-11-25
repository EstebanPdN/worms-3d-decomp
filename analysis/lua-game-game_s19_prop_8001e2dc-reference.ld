/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_hop_test_height_8001e2dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc270 = 0x800fc270;
SECTIONS {
  .text.s19_hop_test_height_8001e2dc 0x8001e2dc : { *(.text.s19_hop_test_height_8001e2dc) }
  .rodata 0x8036b828 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
