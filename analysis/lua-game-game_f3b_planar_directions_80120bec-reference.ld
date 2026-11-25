/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f3b_planar_directions_80120bec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
one_8039b6e0 = 0x8039b6e0;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.f3b_planar_directions_80120bec 0x80120bec : { *(.text.f3b_planar_directions_80120bec) }
  .rodata 0x8039b6dc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
