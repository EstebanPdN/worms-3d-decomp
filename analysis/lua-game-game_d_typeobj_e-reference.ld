/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_type_list_80247838)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_array_write_8024b8dc = 0x8024b8dc;
w3d_array_write_8024b998 = 0x8024b998;
w3d_object_alloc_801ea70c = 0x801ea70c;
w3d_object_base_construct_801ea0ec = 0x801ea0ec;
w3d_object_base_destroy_801ea138 = 0x801ea138;
w3d_object_free_801ea740 = 0x801ea740;
w3d_owner_list_remove = 0x8020fd2c;
w3d_script_add_link_801ebf38 = 0x801ebf38;
w3d_script_finish_type_801e8d9c = 0x801e8d9c;
w3d_script_prop_803c3ed0 = 0x803c3ed0;
w3d_script_prop_803c3f1c = 0x803c3f1c;
w3d_script_prop_803c3f54 = 0x803c3f54;
w3d_script_prop_803c3f88 = 0x803c3f88;
w3d_script_prop_803c3fbc = 0x803c3fbc;
w3d_script_prop_803c3ff4 = 0x803c3ff4;
w3d_script_prop_803c402c = 0x803c402c;
w3d_script_prop_803c4064 = 0x803c4064;
w3d_script_prop_803c409c = 0x803c409c;
w3d_script_prop_803c40d4 = 0x803c40d4;
w3d_script_prop_803c4108 = 0x803c4108;
w3d_script_prop_803c4140 = 0x803c4140;
w3d_script_prop_803c4178 = 0x803c4178;
w3d_state_register = 0x8020fd04;
w3d_type_list_80367c98 = 0x80367c98;
w3d_type_list_80367ce8 = 0x80367ce8;
w3d_type_list_80367d38 = 0x80367d38;
w3d_type_list_80367d88 = 0x80367d88;
w3d_type_reset_80249104 = 0x80249104;
w3d_vtable_8041b220 = 0x8041b220;
w3d_vtable_8041b248 = 0x8041b248;
w3d_vtable_8041b270 = 0x8041b270;
w3d_vtable_8041b298 = 0x8041b298;
SECTIONS {
  .text.w3d_type_list_80247838 0x80247838 : { *(.text.w3d_type_list_80247838) }
  .text.w3d_type_create_80247844 0x80247844 : { *(.text.w3d_type_create_80247844) }
  .text.w3d_type_unlink_802478ac 0x802478ac : { *(.text.w3d_type_unlink_802478ac) }
  .text.w3d_type_construct_802478f0 0x802478f0 : { *(.text.w3d_type_construct_802478f0) }
  .text.w3d_type_destroy_802479b8 0x802479b8 : { *(.text.w3d_type_destroy_802479b8) }
  .text.w3d_type_list_80247ba0 0x80247ba0 : { *(.text.w3d_type_list_80247ba0) }
  .text.w3d_type_create_80247bac 0x80247bac : { *(.text.w3d_type_create_80247bac) }
  .text.w3d_type_unlink_80247c14 0x80247c14 : { *(.text.w3d_type_unlink_80247c14) }
  .text.w3d_type_construct_80247c58 0x80247c58 : { *(.text.w3d_type_construct_80247c58) }
  .text.w3d_type_destroy_80247c9c 0x80247c9c : { *(.text.w3d_type_destroy_80247c9c) }
  .text.w3d_type_register_80247cec 0x80247cec : { *(.text.w3d_type_register_80247cec) }
  .text.w3d_type_list_80247d2c 0x80247d2c : { *(.text.w3d_type_list_80247d2c) }
  .text.w3d_type_create_80247d38 0x80247d38 : { *(.text.w3d_type_create_80247d38) }
  .text.w3d_type_unlink_80247da0 0x80247da0 : { *(.text.w3d_type_unlink_80247da0) }
  .text.w3d_type_construct_80247de4 0x80247de4 : { *(.text.w3d_type_construct_80247de4) }
  .text.w3d_type_destroy_80247e5c 0x80247e5c : { *(.text.w3d_type_destroy_80247e5c) }
  .text.w3d_type_register_80247eac 0x80247eac : { *(.text.w3d_type_register_80247eac) }
  .text.w3d_type_list_80247f9c 0x80247f9c : { *(.text.w3d_type_list_80247f9c) }
  .text.w3d_type_create_80247fa8 0x80247fa8 : { *(.text.w3d_type_create_80247fa8) }
  .text.w3d_type_unlink_80248010 0x80248010 : { *(.text.w3d_type_unlink_80248010) }
  .text.w3d_type_construct_80248054 0x80248054 : { *(.text.w3d_type_construct_80248054) }
  .text.w3d_type_destroy_802480f0 0x802480f0 : { *(.text.w3d_type_destroy_802480f0) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; w3d_shared_iface_804b05a8 = .;
    . = 0x8; w3d_shared_iface_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
