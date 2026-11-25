/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_pool_erase_800c56b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803f5718 = 0x803f5718;
lbl_8043e438 = 0x8043e438;
lbl_8043e448 = 0x8043e448;
lbl_804a87d8 = 0x804a87d8;
memmove = 0x802eeef4;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
w3d_pool_free_800c58a8 = 0x800c58a8;
SECTIONS {
  .text.w3d_d24h_pool_erase_800c56b8 0x800c56b8 : { *(.text.w3d_d24h_pool_erase_800c56b8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
