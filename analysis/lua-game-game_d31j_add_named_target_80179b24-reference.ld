/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31j_add_named_target_80179b24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d25j_update_one_target_8017a07c = 0x8017a07c;
lbl_80414a40 = 0x80414a40;
lbl_804163f8 = 0x804163f8;
lbl_804164c0 = 0x804164c0;
memcpy_802eee50 = 0x802eee50;
w3d_cx11b_compact_vector_grow_80210d54 = 0x80210d54;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_release = 0x802134fc;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_k5b_task_pool_reserve_801f29d0 = 0x801f29d0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.d31j_add_named_target_80179b24 0x80179b24 : { *(.text.d31j_add_named_target_80179b24) }
  .sdata 0x804b0160 (NOLOAD) : {
    . = 0x0; lbl_804b0160 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
