/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_jetpack_tilt_800abd30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
construct_801f7538 = 0x801f7538;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d27h_jetpack_tilt_800abd30 0x800abd30 : { *(.text.d27h_jetpack_tilt_800abd30) }
  .rodata 0x80381c2c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
