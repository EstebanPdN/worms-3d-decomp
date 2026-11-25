/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc33b_texture_planes_802e22c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc33b_texture_filter_80309f1c = 0x80309f1c;
cc33b_texture_image_80309c88 = 0x80309c88;
SECTIONS {
  .text.w3d_cc33b_texture_planes_802e22c0 0x802e22c0 : { *(.text.w3d_cc33b_texture_planes_802e22c0) }
  .rodata 0x803db3b8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
