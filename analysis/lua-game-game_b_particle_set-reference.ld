/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pset_get_class)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_component_construct_8017990c = 0x8017990c;
w3d_component_destruct_801799d4 = 0x801799d4;
w3d_descriptor_load_80190538 = 0x80190538;
w3d_descriptor_save_801904c0 = 0x801904c0;
w3d_effect_set_state_801d4544 = 0x801d4544;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_owner_list_remove = 0x8020fd2c;
w3d_pset_class_80361bf8 = 0x80361bf8;
w3d_pset_construct_80183434 = 0x80183434;
w3d_pset_destruct_80183ae8 = 0x80183ae8;
w3d_pset_instance_vtable_80412c40 = 0x80412c40;
w3d_pset_interfaces_803a7974 = 0x803a7974;
w3d_pset_lookup_8034cc34 = 0x8034cc34;
w3d_query_interface_8020b460 = 0x8020b460;
w3d_state_register = 0x8020fd04;
w3d_str_803a7944 = 0x803a7944;
w3d_str_803a7a30 = 0x803a7a30;
w3d_str_803a7a64 = 0x803a7a64;
SECTIONS {
  .text.w3d_pset_get_class 0x801832bc : { *(.text.w3d_pset_get_class) }
  .text.w3d_pset_unlink 0x801832c8 : { *(.text.w3d_pset_unlink) }
  .text.w3d_pset_create 0x8018330c : { *(.text.w3d_pset_create) }
  .text.w3d_pset_interfaces 0x8018336c : { *(.text.w3d_pset_interfaces) }
  .text.w3d_pset_release 0x80183378 : { *(.text.w3d_pset_release) }
  .text.w3d_pset_add_ref 0x801833d4 : { *(.text.w3d_pset_add_ref) }
  .text.w3d_pset_query_interface 0x801833ec : { *(.text.w3d_pset_query_interface) }
  .text.w3d_pset_copy_settings 0x80183a30 : { *(.text.w3d_pset_copy_settings) }
  .text.w3d_pset_pool_size 0x80183eb4 : { *(.text.w3d_pset_pool_size) }
  .text.w3d_pset_pool_used 0x80183ebc : { *(.text.w3d_pset_pool_used) }
  .text.w3d_pset_check_override 0x80184954 : { *(.text.w3d_pset_check_override) }
  .text.w3d_pset_reset 0x80184970 : { *(.text.w3d_pset_reset) }
  .text.w3d_pset_set_flag_0 0x80184b70 : { *(.text.w3d_pset_set_flag_0) }
  .text.w3d_pset_set_flag_1 0x80184c18 : { *(.text.w3d_pset_set_flag_1) }
  .text.w3d_pset_set_flag_4 0x80184cc0 : { *(.text.w3d_pset_set_flag_4) }
  .text.w3d_pset_save 0x80184ec0 : { *(.text.w3d_pset_save) }
  .text.w3d_pset_load 0x80184f20 : { *(.text.w3d_pset_load) }
  .text.w3d_pset_type_id 0x801850ac : { *(.text.w3d_pset_type_id) }
  .text.w3d_pset_type_name 0x801850b4 : { *(.text.w3d_pset_type_name) }
  .text.w3d_pset_flag_0 0x801850c0 : { *(.text.w3d_pset_flag_0) }
  .text.w3d_pset_flag_1 0x801850cc : { *(.text.w3d_pset_flag_1) }
  .text.w3d_pset_flag_4 0x801850d8 : { *(.text.w3d_pset_flag_4) }
  .text.w3d_pset_instance_construct 0x80185110 : { *(.text.w3d_pset_instance_construct) }
  .text.w3d_pset_instance_destruct 0x80185160 : { *(.text.w3d_pset_instance_destruct) }
  .text.w3d_pset_instance_type_id 0x801851cc : { *(.text.w3d_pset_instance_type_id) }
  .text.w3d_pset_instance_type_name 0x801851d4 : { *(.text.w3d_pset_instance_type_name) }
  .sdata 0x804ab65c (NOLOAD) : {
    . = 0x0; w3d_pset_pool_size_804ab65c = .;
    . = 0xc; w3d_pset_free_count_804ab668 = .;
    . = 0x18; w3d_pset_instance_count_804ab674 = .;
    . = 0x4b78; w3d_pset_state_on_804b01d4 = .;
    . = 0x4b7c; w3d_pset_state_off_804b01d8 = .;
    . = 0x4b88; w3d_pset_state_off_804b01e4 = .;
    . = 0x4b8c; w3d_pset_state_on_804b01e8 = .;
    . = 0x4b94; w3d_pset_state_off_804b01f0 = .;
    . = 0x4b98; w3d_pset_state_on_804b01f4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
