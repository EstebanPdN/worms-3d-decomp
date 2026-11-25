/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_walk_step_8014be84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
acos_802e79e0 = 0x802e79e0;
construct_801f7538 = 0x801f7538;
identity_8045e748 = 0x8045e748;
same_80342a74 = 0x80342a74;
scale_80178df0 = 0x80178df0;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26d_worm_walk_step_8014be84 0x8014be84 : { *(.text.d26d_worm_walk_step_8014be84) }
  .rodata 0x803a147c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
