/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_node_cleanup_backend)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_registry_remove = 0x802075d4;
SECTIONS {
  .text.w3d_actor_node_cleanup_backend 0x802075a0 : { *(.text.w3d_actor_node_cleanup_backend) }
  .sdata 0x804b18f0 (NOLOAD) : {
    . = 0x0; w3d_actor_node_registry = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
