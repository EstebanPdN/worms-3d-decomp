/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f5b_transformed_bounds_800b7ed0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
largest_80382500 = 0x80382500;
smallest_80382504 = 0x80382504;
SECTIONS {
  .text.f5b_transformed_bounds_800b7ed0 0x800b7ed0 : { *(.text.f5b_transformed_bounds_800b7ed0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
