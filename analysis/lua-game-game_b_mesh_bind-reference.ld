/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_mesh_instance_unbind)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strncmp = 0x802efb1c;
w3d_class_803627a4 = 0x803627a4;
w3d_class_80363834 = 0x80363834;
w3d_class_80417000 = 0x80417000;
w3d_create_object_8020b680 = 0x8020b680;
w3d_empty_80341348 = 0x80341348;
w3d_mesh_source_visit_801a381c = 0x801a381c;
w3d_ref_array_reserve_801f29d0 = 0x801f29d0;
w3d_resource_set_801ef174 = 0x801ef174;
w3d_resource_set_801ef380 = 0x801ef380;
w3d_str_803a7890 = 0x803a7890;
SECTIONS {
  .text.w3d_mesh_instance_unbind 0x80181e18 : { *(.text.w3d_mesh_instance_unbind) }
  .text.w3d_mesh_instance_owner_value 0x80182150 : { *(.text.w3d_mesh_instance_owner_value) }
  .text.w3d_mesh_instance_set_tint 0x80182178 : { *(.text.w3d_mesh_instance_set_tint) }
  .text.w3d_mesh_collect_visit 0x801821a8 : { *(.text.w3d_mesh_collect_visit) }
  .text.w3d_mesh_instance_collect 0x80182274 : { *(.text.w3d_mesh_instance_collect) }
  .text.w3d_mesh_instance_add_child 0x80182374 : { *(.text.w3d_mesh_instance_add_child) }
  .text.w3d_fn_80182408 0x80182408 : { *(.text.w3d_fn_80182408) }
  .text.w3d_mesh_instance_set_resource_value 0x80182410 : { *(.text.w3d_mesh_instance_set_resource_value) }
  .text.w3d_mesh_instance_reset_resource_value 0x80182450 : { *(.text.w3d_mesh_instance_reset_resource_value) }
  .sdata 0x804b01d0 (NOLOAD) : {
    . = 0x0; w3d_mesh_collect_target_804b01d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
