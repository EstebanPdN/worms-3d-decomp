/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_slot_actor_destroy_800276d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_vtable_8040e1c8 = 0x8040e1c8;
SECTIONS {
  .text.w3d_k8a_slot_actor_destroy_800276d0 0x800276d0 : { *(.text.w3d_k8a_slot_actor_destroy_800276d0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
