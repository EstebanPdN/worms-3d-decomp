/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_component_list_get_800af330)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_construct_800d78ec = 0x800d78ec;
w3d_base_destroy_800d797c = 0x800d797c;
w3d_base_handle_message_800d7d7c = 0x800d7d7c;
w3d_component_apply_800af6b4 = 0x800af6b4;
w3d_component_list_803608a0 = 0x803608a0;
w3d_component_refresh_800ecb20 = 0x800ecb20;
w3d_component_start_800afccc = 0x800afccc;
w3d_component_vtable_8040f760 = 0x8040f760;
w3d_empty_80341584 = 0x80341584;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_owner_list_remove = 0x8020fd2c;
w3d_resource_touch_801797b4 = 0x801797b4;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_component_list_get_800af330 0x800af330 : { *(.text.w3d_component_list_get_800af330) }
  .text.w3d_component_unlink_800af33c 0x800af33c : { *(.text.w3d_component_unlink_800af33c) }
  .text.w3d_component_create_800af380 0x800af380 : { *(.text.w3d_component_create_800af380) }
  .text.w3d_component_release_800af3f0 0x800af3f0 : { *(.text.w3d_component_release_800af3f0) }
  .text.w3d_component_retain_800af458 0x800af458 : { *(.text.w3d_component_retain_800af458) }
  .text.w3d_component_handle_message_800af470 0x800af470 : { *(.text.w3d_component_handle_message_800af470) }
  .text.w3d_component_stop_800af4f8 0x800af4f8 : { *(.text.w3d_component_stop_800af4f8) }
  .text.w3d_component_update_800af4fc 0x800af4fc : { *(.text.w3d_component_update_800af4fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
