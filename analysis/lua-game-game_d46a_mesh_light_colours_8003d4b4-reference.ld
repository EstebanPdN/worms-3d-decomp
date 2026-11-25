/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d46a_mesh_light_colours_8003d4b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__5Point = 0x80343740;
g_items_804273d4 = 0x804273d4;
g_normals_804273e0 = 0x804273e0;
s9_property_data_80189518 = 0x80189518;
s9_property_data_80189704 = 0x80189704;
s9_property_data_80189828 = 0x80189828;
tsonnet_b37_open_8018963c = 0x8018963c;
tsonnet_b37_open_80189760 = 0x80189760;
w3d_auto_801f7794 = 0x801f7794;
w3d_auto_801f77f4 = 0x801f77f4;
w3d_empty_8034380c = 0x8034380c;
w3d_s21_construct_801f757c = 0x801f757c;
w3d_sqrtf_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d46a_mesh_light_colours_8003d4b4 0x8003d4b4 : { *(.text.w3d_d46a_mesh_light_colours_8003d4b4) }
  .rodata 0x803745a0 : { *(.rodata) }
  .sdata 0x804aa93c (NOLOAD) : {
    . = 0x0; g_angle_804aa93c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
