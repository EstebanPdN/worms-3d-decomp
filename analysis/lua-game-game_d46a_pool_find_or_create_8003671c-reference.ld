/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d46a_pool_find_or_create_8003671c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Item = 0x80036a90;
__builtin_new = 0x801fe1d8;
memcpy = 0x802eee50;
w3d_auto_80036c8c = 0x80036c8c;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_d46a_pool_find_or_create_8003671c 0x8003671c : { *(.text.w3d_d46a_pool_find_or_create_8003671c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
