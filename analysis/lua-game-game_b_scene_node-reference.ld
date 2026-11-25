/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8018573c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_empty_80343740 = 0x80343740;
w3d_f32_803a7a94 = 0x803a7a94;
w3d_f32_803a7a98 = 0x803a7a98;
w3d_f32_803a7a9c = 0x803a7a9c;
w3d_f32_803a7aa0 = 0x803a7aa0;
w3d_handle_storage_release = 0x802134fc;
w3d_identity_transform_8045e748 = 0x8045e748;
w3d_instance_finish_8017b348 = 0x8017b348;
w3d_node_vtable_80412cf0 = 0x80412cf0;
SECTIONS {
  .text.w3d_fn_8018573c 0x8018573c : { *(.text.w3d_fn_8018573c) }
  .text.w3d_pset_instance_owner_flags 0x80185744 : { *(.text.w3d_pset_instance_owner_flags) }
  .text.w3d_pset_instance_shutdown 0x80185778 : { *(.text.w3d_pset_instance_shutdown) }
  .text.w3d_node_construct 0x801857f4 : { *(.text.w3d_node_construct) }
  .text.w3d_node_destruct 0x801858fc : { *(.text.w3d_node_destruct) }
  .text.w3d_node_add_ref 0x80185970 : { *(.text.w3d_node_add_ref) }
  .text.w3d_node_release 0x80185990 : { *(.text.w3d_node_release) }
  .text.w3d_node_query_interface 0x801859e4 : { *(.text.w3d_node_query_interface) }
  .text.w3d_node_reset 0x801859f8 : { *(.text.w3d_node_reset) }
  .text.w3d_node_set_type 0x80185af0 : { *(.text.w3d_node_set_type) }
  .text.w3d_node_not_implemented 0x80185b00 : { *(.text.w3d_node_not_implemented) }
  .text.w3d_node_in_use 0x80185b0c : { *(.text.w3d_node_in_use) }
  .text.w3d_node_slot 0x80185b24 : { *(.text.w3d_node_slot) }
  .text.w3d_node_set_id 0x80185b2c : { *(.text.w3d_node_set_id) }
  .text.w3d_node_id 0x80185b38 : { *(.text.w3d_node_id) }
  .text.w3d_node_set_mode 0x80185b40 : { *(.text.w3d_node_set_mode) }
  .sdata 0x804ab670 (NOLOAD) : {
    . = 0x0; w3d_pset_active_count_804ab670 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
