/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_concrete_actor_type)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_concrete_actor_delete = 0x801421c8;
w3d_concrete_actor_descriptor = 0x803615f0;
w3d_owner_list_remove = 0x8020fd2c;
SECTIONS {
  .text.w3d_concrete_actor_type 0x80141c44 : { *(.text.w3d_concrete_actor_type) }
  .text.w3d_concrete_actor_unlink 0x80141c50 : { *(.text.w3d_concrete_actor_unlink) }
  .text.w3d_concrete_actor_release 0x80141cf4 : { *(.text.w3d_concrete_actor_release) }
  .text.w3d_concrete_actor_acquire 0x80141d50 : { *(.text.w3d_concrete_actor_acquire) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
