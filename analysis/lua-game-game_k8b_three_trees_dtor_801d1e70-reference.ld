/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_three_trees_dtor_801d1e70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80416408 = 0x80416408;
lbl_80416468 = 0x80416468;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_handle_storage_release = 0x802134fc;
w3d_slot_tree_erase_80355aec = 0x80355aec;
SECTIONS {
  .text.w3d_k8b_three_trees_dtor_801d1e70 0x801d1e70 : { *(.text.w3d_k8b_three_trees_dtor_801d1e70) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
