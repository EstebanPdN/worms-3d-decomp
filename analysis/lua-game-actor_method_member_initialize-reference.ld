/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_method_member_initialize)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_methods = 0x804108d8;
w3d_actor_method_initialize_backend = 0x800d75a8;
SECTIONS {
  .text.w3d_actor_method_member_initialize 0x801181bc : { *(.text.w3d_actor_method_member_initialize) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
