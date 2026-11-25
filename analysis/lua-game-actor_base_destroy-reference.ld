/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_base_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_cleanup_backend = 0x8015fa94;
w3d_actor_base_methods = 0x804116e8;
SECTIONS {
  .text.w3d_actor_base_destroy 0x80161050 : { *(.text.w3d_actor_base_destroy) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
