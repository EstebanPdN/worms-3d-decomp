/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_file_owner_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_auto_8015b764 = 0x8015b764;
w3d_auto_80164f88 = 0x80164f88;
w3d_auto_8020b648 = 0x8020b648;
w3d_descriptor_804551a4 = 0x804551a4;
w3d_object_8040ca60 = 0x8040ca60;
w3d_object_80412790 = 0x80412790;
w3d_object_804551a0 = 0x804551a0;
w3d_register_80200a70 = 0x80200a70;
w3d_runtime_base_construct_8015b4ac = 0x8015b4ac;
w3d_str_803a4368 = 0x803a4368;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_vtable_80411168 = 0x80411168;
w3d_vtable_804111a0 = 0x804111a0;
w3d_vtable_804111c8 = 0x804111c8;
SECTIONS {
  .text.w3d_file_owner_destroy 0x8015bedc : { *(.text.w3d_file_owner_destroy) }
  .text.w3d_file_owner_virtual_step 0x8015c118 : { *(.text.w3d_file_owner_virtual_step) }
  .text.w3d_file_owner_apply_file 0x8015c2a4 : { *(.text.w3d_file_owner_apply_file) }
  .text.w3d_runtime_register_help 0x8015c384 : { *(.text.w3d_runtime_register_help) }
  .text.w3d_runtime_owner_construct 0x8015c4e0 : { *(.text.w3d_runtime_owner_construct) }
  .text.w3d_runtime_owner_finish 0x8015c880 : { *(.text.w3d_runtime_owner_finish) }
  .text.w3d_runtime_replace_global_handle 0x8015c8dc : { *(.text.w3d_runtime_replace_global_handle) }
  .text.w3d_runtime_query_service_handle 0x8015c960 : { *(.text.w3d_runtime_query_service_handle) }
  .text.w3d_runtime_prepare_services 0x8015c994 : { *(.text.w3d_runtime_prepare_services) }
  .text.w3d_runtime_prepare_renderer 0x8015ca48 : { *(.text.w3d_runtime_prepare_renderer) }
  .text.w3d_runtime_service_set_mode 0x8015cabc : { *(.text.w3d_runtime_service_set_mode) }
  .sdata 0x804b1880 (NOLOAD) : {
    . = 0x0; w3d_handle_804b1880 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
