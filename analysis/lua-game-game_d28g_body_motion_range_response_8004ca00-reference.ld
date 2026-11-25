/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28g_body_motion_range_response_8004ca00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k4a_countdown_step_8004cc60 = 0x8004cc60;
k5a_body_nudge_8004cbdc = 0x8004cbdc;
sqrt_802e82c0 = 0x802e82c0;
w3d_motion_get_20_800668f4 = 0x800668f4;
w3d_motion_get_24_800668fc = 0x800668fc;
w3d_motion_get_28_800668e4 = 0x800668e4;
w3d_motion_get_30_800668dc = 0x800668dc;
w3d_motion_get_position_80066894 = 0x80066894;
w3d_motion_get_velocity_800668b8 = 0x800668b8;
SECTIONS {
  .text.w3d_d28g_body_motion_range_response_8004ca00 0x8004ca00 : { *(.text.w3d_d28g_body_motion_range_response_8004ca00) }
  .rodata 0x80377400 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
