/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32i_camera_update_80120354)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
scale_8039b6c4 = 0x8039b6c4;
target_8044f2b4 = 0x8044f2b4;
w3d_a_80120648 = 0x80120648;
w3d_active_80164fc8 = 0x80164fc8;
w3d_b_8011fc48 = 0x8011fc48;
w3d_c_80120d64 = 0x80120d64;
w3d_cfg_801797b4 = 0x801797b4;
w3d_prop_float_80178df0 = 0x80178df0;
w3d_ref_80341584 = 0x80341584;
SECTIONS {
  .text.d32i_camera_update_80120354 0x80120354 : { *(.text.d32i_camera_update_80120354) }
  .rodata 0x8039b6c8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
