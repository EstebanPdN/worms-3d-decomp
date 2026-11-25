/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28d_worm_trail_segment_8013f73c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Vec = 0x80343740;
tsonnet_b29_release_8013f6b4 = 0x8013f6b4;
w3d_mesh_instance_is_playing = 0x80181ccc;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_trail_graphic_entity_set_segment_80122800 = 0x80122800;
SECTIONS {
  .text.d28d_worm_trail_segment_8013f73c 0x8013f73c : { *(.text.d28d_worm_trail_segment_8013f73c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
