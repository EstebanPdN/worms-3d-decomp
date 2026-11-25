/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33a_grid_rect_insert_plain_8001cc90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
cc25a_grid_rectangle_init_8001ee00 = 0x8001ee00;
free = 0x802134fc;
malloc = 0x80212fd4;
SECTIONS {
  .text.w3d_d33a_grid_rect_insert_plain_8001cc90 0x8001cc90 : { *(.text.w3d_d33a_grid_rect_insert_plain_8001cc90) }
  .sdata 0x804b1758 (NOLOAD) : {
    . = 0x0; w3d_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
