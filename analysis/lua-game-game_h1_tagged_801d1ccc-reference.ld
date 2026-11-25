/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_tagged_construct_801d1ccc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_type_80416630 = 0x80416630;
w3d_vtable_80416408 = 0x80416408;
w3d_vtable_80416468 = 0x80416468;
SECTIONS {
  .text.w3d_tagged_construct_801d1ccc 0x801d1ccc : { *(.text.w3d_tagged_construct_801d1ccc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
