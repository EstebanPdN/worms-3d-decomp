/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_null_get_class)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_destroy = 0x80190384;
w3d_component_construct_8017990c = 0x8017990c;
w3d_component_destruct_801799d4 = 0x801799d4;
w3d_descriptor_construct_801902e8 = 0x801902e8;
w3d_descriptor_method_801904c0 = 0x801904c0;
w3d_descriptor_method_80190538 = 0x80190538;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_instance_in_use_80185b0c = 0x80185b0c;
w3d_null_class_80361bc8 = 0x80361bc8;
w3d_null_instance_vtable_80412b00 = 0x80412b00;
w3d_null_interfaces_803a78dc = 0x803a78dc;
w3d_null_lookup_8034cc30 = 0x8034cc30;
w3d_null_vtable_80412aa0 = 0x80412aa0;
w3d_owner_list_remove = 0x8020fd2c;
w3d_query_interface_8020b460 = 0x8020b460;
w3d_state_register = 0x8020fd04;
w3d_str_803a78b8 = 0x803a78b8;
w3d_str_803a7918 = 0x803a7918;
w3d_string_assign = 0x8020bd38;
SECTIONS {
  .text.w3d_null_get_class 0x801825b8 : { *(.text.w3d_null_get_class) }
  .text.w3d_null_unlink 0x801825c4 : { *(.text.w3d_null_unlink) }
  .text.w3d_null_create 0x80182608 : { *(.text.w3d_null_create) }
  .text.w3d_null_interfaces 0x80182668 : { *(.text.w3d_null_interfaces) }
  .text.w3d_null_release 0x80182674 : { *(.text.w3d_null_release) }
  .text.w3d_null_add_ref 0x801826d0 : { *(.text.w3d_null_add_ref) }
  .text.w3d_null_query_interface 0x801826e8 : { *(.text.w3d_null_query_interface) }
  .text.w3d_null_construct 0x80182730 : { *(.text.w3d_null_construct) }
  .text.w3d_null_load 0x80182778 : { *(.text.w3d_null_load) }
  .text.w3d_null_copy_mode 0x801827d0 : { *(.text.w3d_null_copy_mode) }
  .text.w3d_null_destruct 0x80182818 : { *(.text.w3d_null_destruct) }
  .text.w3d_null_pool_size 0x801829bc : { *(.text.w3d_null_pool_size) }
  .text.w3d_null_pool_used 0x801829c4 : { *(.text.w3d_null_pool_used) }
  .text.w3d_null_set_override 0x801829d8 : { *(.text.w3d_null_set_override) }
  .text.w3d_null_check_override 0x801829f0 : { *(.text.w3d_null_check_override) }
  .text.w3d_null_clear_override 0x80182a0c : { *(.text.w3d_null_clear_override) }
  .text.w3d_null_find_instance 0x80182ba8 : { *(.text.w3d_null_find_instance) }
  .text.w3d_null_next_instance 0x80182c38 : { *(.text.w3d_null_next_instance) }
  .text.w3d_null_method_801904c0 0x80182d00 : { *(.text.w3d_null_method_801904c0) }
  .text.w3d_null_method_80190538 0x80182d20 : { *(.text.w3d_null_method_80190538) }
  .text.w3d_null_type_id 0x80182da0 : { *(.text.w3d_null_type_id) }
  .text.w3d_null_type_name 0x80182da8 : { *(.text.w3d_null_type_name) }
  .text.w3d_null_instance_construct 0x80182de0 : { *(.text.w3d_null_instance_construct) }
  .text.w3d_null_instance_destruct 0x80182e28 : { *(.text.w3d_null_instance_destruct) }
  .text.w3d_null_instance_type_id 0x80182e60 : { *(.text.w3d_null_instance_type_id) }
  .text.w3d_null_instance_type_name 0x80182e68 : { *(.text.w3d_null_instance_type_name) }
  .sdata 0x804ab634 (NOLOAD) : {
    . = 0x0; w3d_null_pool_804ab634 = .;
    . = 0x4; w3d_null_pool_size_804ab638 = .;
    . = 0x8; w3d_null_count_804ab63c = .;
    . = 0x10; w3d_null_free_count_804ab644 = .;
    . = 0x18; w3d_null_instance_count_804ab64c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
