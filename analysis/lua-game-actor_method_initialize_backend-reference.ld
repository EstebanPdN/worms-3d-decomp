/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_method_initialize_backend)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_method_lower_methods = 0x8040fd60;
SECTIONS {
  .text.w3d_actor_method_initialize_backend 0x800d75a8 : { *(.text.w3d_actor_method_initialize_backend) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
