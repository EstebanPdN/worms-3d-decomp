/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_wind_gauge_update_801303d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atan2_802e7e5c = 0x802e7e5c;
sin_802e88ac = 0x802e88ac;
span_8039dfec = 0x8039dfec;
w3d_a_80130d1c = 0x80130d1c;
w3d_b_80131610 = 0x80131610;
w3d_c_80130fb8 = 0x80130fb8;
w3d_d_80131338 = 0x80131338;
w3d_e_80130ed8 = 0x80130ed8;
w3d_matrix_from_801f6c2c = 0x801f6c2c;
w3d_wind_direction_80131520 = 0x80131520;
SECTIONS {
  .text.d26i_wind_gauge_update_801303d4 0x801303d4 : { *(.text.d26i_wind_gauge_update_801303d4) }
  .rodata 0x8039dff0 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; world_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
