/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_actor_handle_member_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_handle_cleanup_backend = 0x8003f8e8;
w3d_heap_release = 0x80209920;
SECTIONS {
  .text.w3d_actor_handle_member_destroy 0x80126230 : { *(.text.w3d_actor_handle_member_destroy) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; w3d_actor_member_heap = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
