/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_wind_gauge_layout_80130fb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_mesh_8034380c = 0x8034380c;
w3d_prop_float_80178df0 = 0x80178df0;
w3d_prop_vec_80178ec4 = 0x80178ec4;
w3d_uvs_8018963c = 0x8018963c;
w3d_vertices_80189518 = 0x80189518;
SECTIONS {
  .text.d26i_wind_gauge_layout_80130fb8 0x80130fb8 : { *(.text.d26i_wind_gauge_layout_80130fb8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
