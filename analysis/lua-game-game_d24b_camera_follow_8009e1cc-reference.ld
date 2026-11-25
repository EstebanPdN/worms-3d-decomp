/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_camera_follow_8009e1cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cosf_802e86d4 = 0x802e86d4;
w3d_float_value_80178df0 = 0x80178df0;
w3d_index_query_800fc6dc = 0x800fc6dc;
w3d_int_value_80178c48 = 0x80178c48;
w3d_sinf_802e88ac = 0x802e88ac;
w3d_sqrtf_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d24b_camera_follow_8009e1cc 0x8009e1cc : { *(.text.w3d_d24b_camera_follow_8009e1cc) }
  .rodata 0x803805ac : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
