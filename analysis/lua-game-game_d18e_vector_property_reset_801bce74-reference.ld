/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d18e_reset_pivots_801bce74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801f0210 = 0x801f0210;
fn_801f0504 = 0x801f0504;
key_803ab9f8 = 0x803ab9f8;
key_803aba28 = 0x803aba28;
key_803aba70 = 0x803aba70;
key_803abaa8 = 0x803abaa8;
key_803ac5f0 = 0x803ac5f0;
key_803ac620 = 0x803ac620;
value_803aba4c = 0x803aba4c;
value_803abacc = 0x803abacc;
value_803ac644 = 0x803ac644;
SECTIONS {
  .text.w3d_d18e_reset_pivots_801bce74 0x801bce74 : { *(.text.w3d_d18e_reset_pivots_801bce74) }
  .text.w3d_d18e_reset_joint_axes_801bd0a0 0x801bd0a0 : { *(.text.w3d_d18e_reset_joint_axes_801bd0a0) }
  .text.w3d_d18e_reset_plane_axes_801c16ec 0x801c16ec : { *(.text.w3d_d18e_reset_plane_axes_801c16ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
