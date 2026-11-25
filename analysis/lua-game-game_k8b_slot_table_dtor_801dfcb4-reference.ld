/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_slot_table_dtor_801dfcb4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80416cc8 = 0x80416cc8;
lbl_80416d78 = 0x80416d78;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_auto_801e6ec4 = 0x801e6ec4;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_k8b_slot_table_dtor_801dfcb4 0x801dfcb4 : { *(.text.w3d_k8b_slot_table_dtor_801dfcb4) }
  .sdata 0x804ab834 (NOLOAD) : {
    . = 0x0; lbl_804ab834 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
