/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_matrix4_axis_angle_801f725c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e86d4 = 0x802e86d4;
fn_802e88ac = 0x802e88ac;
SECTIONS {
  .text.w3d_k5b_matrix4_axis_angle_801f725c 0x801f725c : { *(.text.w3d_k5b_matrix4_axis_angle_801f725c) }
  .rodata 0x803b16f0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
