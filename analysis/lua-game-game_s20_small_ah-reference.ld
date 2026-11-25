/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_construct_three_vectors_800e7c78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_s20_construct_three_vectors_800e7c78 0x800e7c78 : { *(.text.w3d_s20_construct_three_vectors_800e7c78) }
  .text.w3d_s20_release_held_800f34a0 0x800f34a0 : { *(.text.w3d_s20_release_held_800f34a0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
