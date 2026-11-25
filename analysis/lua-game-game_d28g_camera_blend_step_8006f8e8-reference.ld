/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28g_camera_blend_step_8006f8e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_camera_targets_8006fca0 = 0x8006fca0;
w3d_k2b_extend_bounds_8015ab54 = 0x8015ab54;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.w3d_d28g_camera_blend_step_8006f8e8 0x8006f8e8 : { *(.text.w3d_d28g_camera_blend_step_8006f8e8) }
  .rodata 0x8037c954 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
