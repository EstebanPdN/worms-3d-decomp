/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_camera_owner_position_800cfcac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_camera_read_float_800fc270 = 0x800fc270;
w3d_camera_read_int_800fc1f0 = 0x800fc1f0;
w3d_camera_resolve_800fc6dc = 0x800fc6dc;
w3d_f32_80388130 = 0x80388130;
w3d_str_80387f48 = 0x80387f48;
w3d_str_803880c0 = 0x803880c0;
SECTIONS {
  .text.w3d_camera_owner_position_800cfcac 0x800cfcac : { *(.text.w3d_camera_owner_position_800cfcac) }
  .text.w3d_camera_active_position_800cfcfc 0x800cfcfc : { *(.text.w3d_camera_active_position_800cfcfc) }
  .text.w3d_camera_owner_raised_position_800cfd98 0x800cfd98 : { *(.text.w3d_camera_owner_raised_position_800cfd98) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
