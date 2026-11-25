/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25d_worm_input_yaw_8015139c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
input_8014c260 = 0x8014c260;
matrix_8014be44 = 0x8014be44;
normalize_801f6c2c = 0x801f6c2c;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d25d_worm_input_yaw_8015139c 0x8015139c : { *(.text.d25d_worm_input_yaw_8015139c) }
  .rodata 0x803a18a8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
