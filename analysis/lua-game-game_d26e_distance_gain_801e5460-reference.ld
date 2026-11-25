/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26e_distance_gain_801e5460)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_getf_801df1bc = 0x801df1bc;
w3d_getf_801df1c4 = 0x801df1c4;
SECTIONS {
  .text.w3d_d26e_distance_gain_801e5460 0x801e5460 : { *(.text.w3d_d26e_distance_gain_801e5460) }
  .rodata 0x803b071c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
