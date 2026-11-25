/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_base_cleanup_backend)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_child_detach = 0x8015f884;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_actor_node_methods = 0x80411590;
w3d_actor_reference_methods = 0x80411560;
SECTIONS {
  .text.w3d_actor_base_cleanup_backend 0x8015fa94 : { *(.text.w3d_actor_base_cleanup_backend) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
