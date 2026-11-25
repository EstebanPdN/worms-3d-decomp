/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8b_record_nearest_hit_800d8fdc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
ceil_802e85fc = 0x802e85fc;
intersect_800419cc = 0x800419cc;
one_80389530 = 0x80389530;
zero_80389524 = 0x80389524;
SECTIONS {
  .text.f8b_record_nearest_hit_800d8fdc 0x800d8fdc : { *(.text.f8b_record_nearest_hit_800d8fdc) }
  .rodata 0x80389528 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
