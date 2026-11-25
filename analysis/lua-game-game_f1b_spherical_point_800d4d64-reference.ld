/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f1b_spherical_point_800d4d64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cos_802e86d4 = 0x802e86d4;
sin_802e88ac = 0x802e88ac;
SECTIONS {
  .text.f1b_spherical_point_800d4d64 0x800d4d64 : { *(.text.f1b_spherical_point_800d4d64) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
