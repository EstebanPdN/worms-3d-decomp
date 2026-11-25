/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26h_land_bounds_publish_800bae54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
as_float_80342a74 = 0x80342a74;
as_vector_80342fa4 = 0x80342fa4;
float_assign_800fc4c8 = 0x800fc4c8;
lookup_800fc1b0 = 0x800fc1b0;
set_float_80178dfc = 0x80178dfc;
set_vector_80178fa4 = 0x80178fa4;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26h_land_bounds_publish_800bae54 0x800bae54 : { *(.text.d26h_land_bounds_publish_800bae54) }
  .rodata 0x80382b20 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
