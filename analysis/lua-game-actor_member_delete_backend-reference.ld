/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_member_delete_backend)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_task_array_release_backend = 0x801fe288;
SECTIONS {
  .text.w3d_actor_member_delete_backend 0x801fe1f8 : { *(.text.w3d_actor_member_delete_backend) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
