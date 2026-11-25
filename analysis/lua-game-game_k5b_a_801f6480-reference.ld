/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_matrix3_axis_angle_801f6480)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e86d4 = 0x802e86d4;
fn_802e88ac = 0x802e88ac;
SECTIONS {
  .text.w3d_k5b_matrix3_axis_angle_801f6480 0x801f6480 : { *(.text.w3d_k5b_matrix3_axis_angle_801f6480) }
  .rodata 0x803b1620 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
