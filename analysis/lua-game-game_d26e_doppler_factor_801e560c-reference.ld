/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26e_doppler_factor_801e560c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d26e_doppler_factor_801e560c 0x801e560c : { *(.text.w3d_d26e_doppler_factor_801e560c) }
  .rodata 0x803b0724 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
