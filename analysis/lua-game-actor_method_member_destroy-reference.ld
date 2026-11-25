/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_method_member_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_methods = 0x804108d8;
w3d_actor_method_cleanup_backend = 0x800d75bc;
SECTIONS {
  .text.w3d_actor_method_member_destroy 0x80118200 : { *(.text.w3d_actor_method_member_destroy) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
