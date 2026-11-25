/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_ray_misses_8015ac04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_test_ray_800b0788 = 0x800b0788;
SECTIONS {
  .text.w3d_k2b_ray_misses_8015ac04 0x8015ac04 : { *(.text.w3d_k2b_ray_misses_8015ac04) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
