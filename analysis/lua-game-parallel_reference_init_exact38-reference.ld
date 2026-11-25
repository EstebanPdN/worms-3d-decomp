/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_reference_initialize)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_node_methods = 0x80411590;
w3d_actor_reference_methods = 0x80411560;
SECTIONS {
  .text.w3d_actor_reference_initialize 0x8015fa40 : { *(.text.w3d_actor_reference_initialize) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
