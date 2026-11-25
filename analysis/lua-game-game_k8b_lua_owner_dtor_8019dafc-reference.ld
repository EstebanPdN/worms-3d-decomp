/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_lua_owner_dtor_8019dafc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80413760 = 0x80413760;
lbl_804137b0 = 0x804137b0;
lua_close = 0x802d5bb0;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_auto_80210abc = 0x80210abc;
w3d_task_deferred_clear = 0x80210afc;
SECTIONS {
  .text.w3d_k8b_lua_owner_dtor_8019dafc 0x8019dafc : { *(.text.w3d_k8b_lua_owner_dtor_8019dafc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
