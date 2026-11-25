/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_trail_spawn_8012ad58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_colours_80189760 = 0x80189760;
d24i_half_turn_8039d2a4 = 0x8039d2a4;
d24i_height_8039d2a8 = 0x8039d2a8;
d24i_pi_8039d2a0 = 0x8039d2a0;
d24i_positions_80189518 = 0x80189518;
d24i_random_8015ff5c = 0x8015ff5c;
d24i_rotations_80189574 = 0x80189574;
SECTIONS {
  .text.d24i_trail_spawn_8012ad58 0x8012ad58 : { *(.text.d24i_trail_spawn_8012ad58) }
  .rodata 0x8039d298 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
