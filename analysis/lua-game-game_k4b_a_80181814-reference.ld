/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_mesh_instance_fade_named_80181814)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_mesh_instance_fade_index_80181884 = 0x80181884;
w3d_mesh_instance_find_clip = 0x80181598;
SECTIONS {
  .text.w3d_k4b_mesh_instance_fade_named_80181814 0x80181814 : { *(.text.w3d_k4b_mesh_instance_fade_named_80181814) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
