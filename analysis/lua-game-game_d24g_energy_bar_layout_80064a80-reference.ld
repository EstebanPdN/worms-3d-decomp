/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_energy_bar_layout_80064a80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
as_mesh_8034380c = 0x8034380c;
mesh_a_80189828 = 0x80189828;
mesh_alloc_8018920c = 0x8018920c;
mesh_b_8018963c = 0x8018963c;
mesh_c_80189518 = 0x80189518;
mesh_d_80189884 = 0x80189884;
mesh_e_801898e0 = 0x801898e0;
mesh_set_80189450 = 0x80189450;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_d24g_energy_bar_layout_80064a80 0x80064a80 : { *(.text.w3d_d24g_energy_bar_layout_80064a80) }
  .rodata 0x80379dc4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
