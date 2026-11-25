/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15b_init_blender_800a9ee0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_initialize = 0x80161014;
w3d_half_80381a1c = 0x80381a1c;
w3d_neutral_vector_8045e788 = 0x8045e788;
w3d_vtable_8040f690 = 0x8040f690;
w3d_zero_80381a20 = 0x80381a20;
SECTIONS {
  .text.d15b_init_blender_800a9ee0 0x800a9ee0 : { *(.text.d15b_init_blender_800a9ee0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
