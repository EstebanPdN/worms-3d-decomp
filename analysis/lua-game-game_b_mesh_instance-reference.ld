/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_mesh_descriptor_bind_animation)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_class_80362844 = 0x80362844;
w3d_class_80362984 = 0x80362984;
w3d_class_80363474 = 0x80363474;
w3d_class_80363d34 = 0x80363d34;
w3d_class_80364694 = 0x80364694;
w3d_class_80365274 = 0x80365274;
w3d_class_80414160 = 0x80414160;
w3d_component_construct_8017990c = 0x8017990c;
w3d_component_destruct_801799d4 = 0x801799d4;
w3d_create_object_8020b680 = 0x8020b680;
w3d_fatal_801fcb64 = 0x801fcb64;
w3d_key_8040e0a8 = 0x8040e0a8;
w3d_member_construct_801f2678 = 0x801f2678;
w3d_member_destruct_801f2758 = 0x801f2758;
w3d_mesh_instance_vtable_804129e0 = 0x804129e0;
w3d_str_803a76f0 = 0x803a76f0;
w3d_str_803a779c = 0x803a779c;
w3d_str_803a7808 = 0x803a7808;
w3d_str_803a782c = 0x803a782c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_mesh_descriptor_bind_animation 0x801801b0 : { *(.text.w3d_mesh_descriptor_bind_animation) }
  .text.w3d_fn_801803f0 0x801803f0 : { *(.text.w3d_fn_801803f0) }
  .text.w3d_mesh_type_name 0x801803f8 : { *(.text.w3d_mesh_type_name) }
  .text.w3d_mesh_descriptor_get_clip 0x80180404 : { *(.text.w3d_mesh_descriptor_get_clip) }
  .text.w3d_mesh_filter_accepts 0x801804c8 : { *(.text.w3d_mesh_filter_accepts) }
  .text.w3d_mesh_target_reset_shared 0x80180804 : { *(.text.w3d_mesh_target_reset_shared) }
  .text.w3d_mesh_instance_construct 0x80180880 : { *(.text.w3d_mesh_instance_construct) }
  .text.w3d_mesh_instance_destruct 0x801808f4 : { *(.text.w3d_mesh_instance_destruct) }
  .text.w3d_fn_801809c0 0x801809c0 : { *(.text.w3d_fn_801809c0) }
  .text.w3d_mesh_instance_type_name 0x801809c8 : { *(.text.w3d_mesh_instance_type_name) }
  .sdata 0x804ab624 (NOLOAD) : {
    . = 0x0; w3d_mesh_instance_count_804ab624 = .;
    . = 0x4ba0; w3d_mesh_shared_804b01c4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
