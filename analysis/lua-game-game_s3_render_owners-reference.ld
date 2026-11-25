/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_render_owner_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_auto_80210abc = 0x80210abc;
w3d_descriptor_804551ec = 0x804551ec;
w3d_handle_storage_release = 0x802134fc;
w3d_lookup_8020b680 = 0x8020b680;
w3d_object_8040e188 = 0x8040e188;
w3d_object_80413a68 = 0x80413a68;
w3d_object_80413c78 = 0x80413c78;
w3d_object_804163f8 = 0x804163f8;
w3d_object_804551e8 = 0x804551e8;
w3d_register_80200a70 = 0x80200a70;
w3d_render_bind_8015f090 = 0x8015f090;
w3d_render_prepare_8015e598 = 0x8015e598;
w3d_str_803a4528 = 0x803a4528;
w3d_vtable_804112e0 = 0x804112e0;
w3d_vtable_80411378 = 0x80411378;
w3d_vtable_804114b8 = 0x804114b8;
SECTIONS {
  .text.w3d_render_owner_destroy 0x8015dcdc : { *(.text.w3d_render_owner_destroy) }
  .text.w3d_render_owner_initialize 0x8015df2c : { *(.text.w3d_render_owner_initialize) }
  .text.w3d_render_owner_finish 0x8015e900 : { *(.text.w3d_render_owner_finish) }
  .text.w3d_render_register_service 0x8015ea78 : { *(.text.w3d_render_register_service) }
  .text.w3d_render_alternate_owner_destroy 0x8015ee04 : { *(.text.w3d_render_alternate_owner_destroy) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
