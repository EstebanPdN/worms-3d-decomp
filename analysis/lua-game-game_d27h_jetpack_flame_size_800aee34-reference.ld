/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_jetpack_flame_size_800aee34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sin_802e88ac = 0x802e88ac;
SECTIONS {
  .text.d27h_jetpack_flame_size_800aee34 0x800aee34 : { *(.text.d27h_jetpack_flame_size_800aee34) }
  .rodata 0x80382208 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
