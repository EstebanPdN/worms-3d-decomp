/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16c_hud_backing_colour_8011b188)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d16c_String_8020bb54PCc = 0x8020bb54;
d16c_blue_8039aec0 = 0x8039aec0;
d16c_green_8039ae90 = 0x8039ae90;
d16c_handle_load_8015adf4 = 0x8015adf4;
d16c_handle_mesh_8034380c = 0x8034380c;
d16c_mesh_attr_a_80189884 = 0x80189884;
d16c_mesh_attr_b_801898e0 = 0x801898e0;
d16c_mesh_indices_80189828 = 0x80189828;
d16c_mesh_positions_80189518 = 0x80189518;
d16c_mesh_reserve_indices_8018920c = 0x8018920c;
d16c_mesh_reserve_vertices_80189450 = 0x80189450;
d16c_mesh_uvs_8018963c = 0x8018963c;
d16c_pink_8039aeac = 0x8039aeac;
d16c_red_8039aed4 = 0x8039aed4;
d16c_string_finish_8020c5c4 = 0x8020c5c4;
d16c_string_release_80341588 = 0x80341588;
d16c_team_800fc7f8 = 0x800fc7f8;
d16c_turq_8039aefc = 0x8039aefc;
d16c_yellow_8039aee8 = 0x8039aee8;
SECTIONS {
  .text.d16c_hud_backing_colour_8011b188 0x8011b188 : { *(.text.d16c_hud_backing_colour_8011b188) }
  .rodata 0x8039af10 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
