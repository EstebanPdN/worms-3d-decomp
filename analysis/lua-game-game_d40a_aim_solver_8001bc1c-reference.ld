/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40a_aim_solver_8001bc1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc25a_vector_scaled_offsets_8001c134 = 0x8001c134;
cc25a_vector_scaled_offsets_v2_8001c250 = 0x8001c250;
g_none_8041e774 = 0x8041e774;
sqrt_802e82c0 = 0x802e82c0;
w3d_d33a_wind_aim_angle_8001c36c = 0x8001c36c;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d40a_aim_solver_8001bc1c 0x8001bc1c : { *(.text.w3d_d40a_aim_solver_8001bc1c) }
  .rodata 0x8036b07c : { *(.rodata) }
  .sdata 0x804ac8ec (NOLOAD) : {
    . = 0x0; g_none_ready_804ac8ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
