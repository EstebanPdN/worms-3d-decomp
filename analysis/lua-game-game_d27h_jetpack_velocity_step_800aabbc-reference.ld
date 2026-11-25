/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_jetpack_velocity_step_800aabbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
as_float_80342a74 = 0x80342a74;
construct_801f7538 = 0x801f7538;
g_gravity_8045e788 = 0x8045e788;
get_float_80178df0 = 0x80178df0;
limit_800abfe0 = 0x800abfe0;
limit_800ac03c = 0x800ac03c;
multiply_801f740c = 0x801f740c;
pre_800abd30 = 0x800abd30;
sin_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d27h_jetpack_velocity_step_800aabbc 0x800aabbc : { *(.text.d27h_jetpack_velocity_step_800aabbc) }
  .rodata 0x80381a38 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
