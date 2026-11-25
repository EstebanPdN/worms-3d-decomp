/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_type_list_80242e04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_803c023c = 0x803c023c;
w3d_object_alloc_801ea70c = 0x801ea70c;
w3d_object_base_construct_801ea0ec = 0x801ea0ec;
w3d_object_base_destroy_801ea138 = 0x801ea138;
w3d_object_free_801ea740 = 0x801ea740;
w3d_owner_list_remove = 0x8020fd2c;
w3d_state_register = 0x8020fd04;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_type_construct_80242ebc = 0x80242ebc;
w3d_type_construct_802449bc = 0x802449bc;
w3d_type_list_80367838 = 0x80367838;
w3d_type_list_80367888 = 0x80367888;
w3d_type_list_803678d8 = 0x803678d8;
w3d_type_list_80367928 = 0x80367928;
w3d_type_list_80367978 = 0x80367978;
w3d_vtable_8041b428 = 0x8041b428;
w3d_vtable_8041b450 = 0x8041b450;
w3d_vtable_8041b478 = 0x8041b478;
w3d_vtable_8041b4a0 = 0x8041b4a0;
w3d_vtable_8041b4c8 = 0x8041b4c8;
SECTIONS {
  .text.w3d_type_list_80242e04 0x80242e04 : { *(.text.w3d_type_list_80242e04) }
  .text.w3d_type_create_80242e10 0x80242e10 : { *(.text.w3d_type_create_80242e10) }
  .text.w3d_type_unlink_80242e78 0x80242e78 : { *(.text.w3d_type_unlink_80242e78) }
  .text.w3d_type_destroy_802432a8 0x802432a8 : { *(.text.w3d_type_destroy_802432a8) }
  .text.w3d_type_list_802441bc 0x802441bc : { *(.text.w3d_type_list_802441bc) }
  .text.w3d_type_create_802441c8 0x802441c8 : { *(.text.w3d_type_create_802441c8) }
  .text.w3d_type_unlink_80244230 0x80244230 : { *(.text.w3d_type_unlink_80244230) }
  .text.w3d_type_construct_80244274 0x80244274 : { *(.text.w3d_type_construct_80244274) }
  .text.w3d_type_destroy_802442fc 0x802442fc : { *(.text.w3d_type_destroy_802442fc) }
  .text.w3d_type_list_80244474 0x80244474 : { *(.text.w3d_type_list_80244474) }
  .text.w3d_type_create_80244480 0x80244480 : { *(.text.w3d_type_create_80244480) }
  .text.w3d_type_unlink_802444e8 0x802444e8 : { *(.text.w3d_type_unlink_802444e8) }
  .text.w3d_type_construct_8024452c 0x8024452c : { *(.text.w3d_type_construct_8024452c) }
  .text.w3d_type_destroy_80244588 0x80244588 : { *(.text.w3d_type_destroy_80244588) }
  .text.w3d_type_list_802446bc 0x802446bc : { *(.text.w3d_type_list_802446bc) }
  .text.w3d_type_create_802446c8 0x802446c8 : { *(.text.w3d_type_create_802446c8) }
  .text.w3d_type_unlink_80244730 0x80244730 : { *(.text.w3d_type_unlink_80244730) }
  .text.w3d_type_construct_80244774 0x80244774 : { *(.text.w3d_type_construct_80244774) }
  .text.w3d_type_destroy_802447d0 0x802447d0 : { *(.text.w3d_type_destroy_802447d0) }
  .text.w3d_type_list_80244904 0x80244904 : { *(.text.w3d_type_list_80244904) }
  .text.w3d_type_create_80244910 0x80244910 : { *(.text.w3d_type_create_80244910) }
  .text.w3d_type_unlink_80244978 0x80244978 : { *(.text.w3d_type_unlink_80244978) }
  .text.w3d_type_destroy_80244d60 0x80244d60 : { *(.text.w3d_type_destroy_80244d60) }
  .sdata 0x804b05b0 (NOLOAD) : {
    . = 0x0; w3d_shared_iface_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
