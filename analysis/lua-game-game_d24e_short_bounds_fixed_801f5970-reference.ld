/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24e_short_bounds_fixed_801f5970)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
constant_803b15d0 = 0x803b15d0;
SECTIONS {
  .text.w3d_d24e_short_bounds_fixed_801f5970 0x801f5970 : { *(.text.w3d_d24e_short_bounds_fixed_801f5970) }
  .rodata 0x803b15c8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
