/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_handle_cleanup_backend)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_free_handles = 0x804273fc;
w3d_handle_copy_memory = 0x802eee50;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_handle_table = 0x804273ec;
SECTIONS {
  .text.w3d_actor_handle_cleanup_backend 0x8003f8e8 : { *(.text.w3d_actor_handle_cleanup_backend) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
