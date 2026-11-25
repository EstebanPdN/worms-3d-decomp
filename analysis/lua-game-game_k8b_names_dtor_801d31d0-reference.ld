/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_names_dtor_801d31d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804164d0 = 0x804164d0;
lbl_80416518 = 0x80416518;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_destroy_801e828c = 0x801e828c;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k8b_names_dtor_801d31d0 0x801d31d0 : { *(.text.w3d_k8b_names_dtor_801d31d0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
