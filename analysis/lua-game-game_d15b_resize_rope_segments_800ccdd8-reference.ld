/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15b_resize_rope_segments_800ccdd8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__Q28D15bRope4NamePCc = 0x8020bb54;
sol35d12_resize_refs_80210b90 = 0x80210b90;
w3d_cx11b_compact_vector_grow_80210d54 = 0x80210d54;
w3d_handle_set_name = 0x8015adf4;
w3d_ninja_rope_name_80387e08 = 0x80387e08;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.d15b_resize_rope_segments_800ccdd8 0x800ccdd8 : { *(.text.d15b_resize_rope_segments_800ccdd8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
