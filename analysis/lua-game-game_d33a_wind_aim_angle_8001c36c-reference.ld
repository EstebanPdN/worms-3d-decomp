/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33a_wind_aim_angle_8001c36c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
sqrt_802e82c0 = 0x802e82c0;
value_80178df0 = 0x80178df0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_cx14a_wind_vector_8001a9a0 = 0x8001a9a0;
w3d_identity_80342a74 = 0x80342a74;
SECTIONS {
  .text.w3d_d33a_wind_aim_angle_8001c36c 0x8001c36c : { *(.text.w3d_d33a_wind_aim_angle_8001c36c) }
  .rodata 0x8036b0c4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
