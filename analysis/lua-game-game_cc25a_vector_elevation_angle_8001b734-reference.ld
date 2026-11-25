/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc25a_vector_elevation_angle_8001b734)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc25a_acos_802e79e0 = 0x802e79e0;
cc25a_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.cc25a_vector_elevation_angle_8001b734 0x8001b734 : { *(.text.cc25a_vector_elevation_angle_8001b734) }
  .rodata 0x8036b048 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
