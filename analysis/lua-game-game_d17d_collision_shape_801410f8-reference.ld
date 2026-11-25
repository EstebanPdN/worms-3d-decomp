/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17d_collision_shape_initialize_801410f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_center_804530a8 = 0x804530a8;
w3d_points_80453030 = 0x80453030;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d17d_collision_shape_initialize_801410f8 0x801410f8 : { *(.text.d17d_collision_shape_initialize_801410f8) }
  .rodata 0x803a0450 : { *(.rodata) }
  .sdata 0x804ab3cc (NOLOAD) : {
    . = 0x0; w3d_radius_804ab3cc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
