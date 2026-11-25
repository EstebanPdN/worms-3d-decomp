/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_movie_graphics_setup_802e23e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alpha_8030b4ac = 0x8030b4ac;
blend_8030b9b8 = 0x8030b9b8;
channels_803080a4 = 0x803080a4;
coords_8030b314 = 0x8030b314;
depth_8030ba64 = 0x8030ba64;
mapping_8030b35c = 0x8030b35c;
order_8030af88 = 0x8030af88;
stages_8030b648 = 0x8030b648;
state_80308be8 = 0x80308be8;
texgens_8030990c = 0x8030990c;
SECTIONS {
  .text.w3d_cx12b_movie_graphics_setup_802e23e8 0x802e23e8 : { *(.text.w3d_cx12b_movie_graphics_setup_802e23e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
