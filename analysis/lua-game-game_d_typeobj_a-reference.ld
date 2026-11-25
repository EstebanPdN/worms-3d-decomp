/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_type_list_80241af4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_object_alloc_801ea70c = 0x801ea70c;
w3d_object_base_construct_801ea0ec = 0x801ea0ec;
w3d_object_base_destroy_801ea138 = 0x801ea138;
w3d_object_free_801ea740 = 0x801ea740;
w3d_owner_list_remove = 0x8020fd2c;
w3d_state_register = 0x8020fd04;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_shared_empty = 0x804b06a0;
w3d_type_construct_80241bac = 0x80241bac;
w3d_type_list_80367748 = 0x80367748;
w3d_type_list_80367798 = 0x80367798;
w3d_type_list_803677e8 = 0x803677e8;
w3d_vtable_8041b4f0 = 0x8041b4f0;
w3d_vtable_8041b518 = 0x8041b518;
w3d_vtable_8041b540 = 0x8041b540;
SECTIONS {
  .text.w3d_type_list_80241af4 0x80241af4 : { *(.text.w3d_type_list_80241af4) }
  .text.w3d_type_create_80241b00 0x80241b00 : { *(.text.w3d_type_create_80241b00) }
  .text.w3d_type_unlink_80241b68 0x80241b68 : { *(.text.w3d_type_unlink_80241b68) }
  .text.w3d_type_destroy_80241e4c 0x80241e4c : { *(.text.w3d_type_destroy_80241e4c) }
  .text.w3d_type_list_80242780 0x80242780 : { *(.text.w3d_type_list_80242780) }
  .text.w3d_type_create_8024278c 0x8024278c : { *(.text.w3d_type_create_8024278c) }
  .text.w3d_type_unlink_802427f4 0x802427f4 : { *(.text.w3d_type_unlink_802427f4) }
  .text.w3d_type_construct_80242838 0x80242838 : { *(.text.w3d_type_construct_80242838) }
  .text.w3d_type_destroy_80242910 0x80242910 : { *(.text.w3d_type_destroy_80242910) }
  .text.w3d_type_list_80242bbc 0x80242bbc : { *(.text.w3d_type_list_80242bbc) }
  .text.w3d_type_create_80242bc8 0x80242bc8 : { *(.text.w3d_type_create_80242bc8) }
  .text.w3d_type_unlink_80242c30 0x80242c30 : { *(.text.w3d_type_unlink_80242c30) }
  .text.w3d_type_construct_80242c74 0x80242c74 : { *(.text.w3d_type_construct_80242c74) }
  .text.w3d_type_destroy_80242cd0 0x80242cd0 : { *(.text.w3d_type_destroy_80242cd0) }
  .sdata 0x804b05b0 (NOLOAD) : {
    . = 0x0; w3d_shared_iface_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
