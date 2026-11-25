/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f4b_planar_offset_800cb868)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_80387d04 = 0x80387d04;
range_80387d08 = 0x80387d08;
scale_80387d0c = 0x80387d0c;
sqrt_802e82c0 = 0x802e82c0;
zero_80387d00 = 0x80387d00;
SECTIONS {
  .text.f4b_planar_offset_800cb868 0x800cb868 : { *(.text.f4b_planar_offset_800cb868) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
