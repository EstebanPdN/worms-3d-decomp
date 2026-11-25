/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_runtime_service_lookup)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_auto_8015b1a8 = 0x8015b1a8;
w3d_auto_8016293c = 0x8016293c;
w3d_ctor_801628b0 = 0x801628b0;
w3d_fn_8015bedc = 0x8015bedc;
w3d_fn_8015d1ac = 0x8015d1ac;
w3d_fn_802cb01c = 0x802cb01c;
w3d_handle_storage_release = 0x802134fc;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_vtable_80411028 = 0x80411028;
w3d_vtable_804110e8 = 0x804110e8;
SECTIONS {
  .text.w3d_runtime_service_lookup 0x8015ae3c : { *(.text.w3d_runtime_service_lookup) }
  .text.w3d_runtime_service_query 0x8015ae74 : { *(.text.w3d_runtime_service_query) }
  .text.w3d_runtime_service_set_pair 0x8015aea8 : { *(.text.w3d_runtime_service_set_pair) }
  .text.w3d_runtime_service_set_byte_a 0x8015aee8 : { *(.text.w3d_runtime_service_set_byte_a) }
  .text.w3d_runtime_service_set_byte_b 0x8015af24 : { *(.text.w3d_runtime_service_set_byte_b) }
  .text.w3d_runtime_singleton_construct 0x8015b084 : { *(.text.w3d_runtime_singleton_construct) }
  .text.w3d_runtime_singleton_destroy 0x8015b0c4 : { *(.text.w3d_runtime_singleton_destroy) }
  .text.w3d_runtime_singleton_dispatch 0x8015b114 : { *(.text.w3d_runtime_singleton_dispatch) }
  .text.w3d_arguments_destroy 0x8015b2a4 : { *(.text.w3d_arguments_destroy) }
  .text.w3d_runtime_destroy_owned_resources 0x8015b630 : { *(.text.w3d_runtime_destroy_owned_resources) }
  .sdata 0x804ab438 (NOLOAD) : {
    . = 0x0; w3d_service_804ab438 = .;
    . = 0x63b4; w3d_context_804b17ec = .;
    . = 0x6448; w3d_runtime_value_804b1880 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
