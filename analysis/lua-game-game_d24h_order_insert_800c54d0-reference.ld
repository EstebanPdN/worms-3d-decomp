/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_order_insert_800c54d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8043e448 = 0x8043e448;
lbl_804a85d8 = 0x804a85d8;
memmove = 0x802eeef4;
w3d_get_800f7508 = 0x800f7508;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d24h_order_insert_800c54d0 0x800c54d0 : { *(.text.w3d_d24h_order_insert_800c54d0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
