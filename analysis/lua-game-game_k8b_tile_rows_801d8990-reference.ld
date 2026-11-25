/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_tile_rows_801d8990)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cx14b_byte_tile_copy_801d7f9c = 0x801d7f9c;
SECTIONS {
  .text.w3d_k8b_tile_rows_801d8990 0x801d8990 : { *(.text.w3d_k8b_tile_rows_801d8990) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
