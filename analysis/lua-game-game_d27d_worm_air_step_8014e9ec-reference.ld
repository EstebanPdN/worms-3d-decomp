/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_air_step_8014e9ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
apply_80153f80 = 0x80153f80;
bump_80153cf0 = 0x80153cf0;
check_801531b0 = 0x801531b0;
collided_801418c4 = 0x801418c4;
direction_80146f10 = 0x80146f10;
fieldA_8014156c = 0x8014156c;
fieldB_80141574 = 0x80141574;
hit_8014f18c = 0x8014f18c;
level_80178df0 = 0x80178df0;
limit_8014c7fc = 0x8014c7fc;
point_8014155c = 0x8014155c;
slope_80149348 = 0x80149348;
sqrt_802e82c0 = 0x802e82c0;
step_80146e30 = 0x80146e30;
steps_80141554 = 0x80141554;
trace_801412a4 = 0x801412a4;
SECTIONS {
  .text.d27d_worm_air_step_8014e9ec 0x8014e9ec : { *(.text.d27d_worm_air_step_8014e9ec) }
  .rodata 0x803a176c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
