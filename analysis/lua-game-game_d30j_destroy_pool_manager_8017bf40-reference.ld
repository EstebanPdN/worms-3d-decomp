/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._15D30jPoolManager)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__vt_15D30jPoolManager = 0x804127a0;
__vt_4Base = 0x80412870;
d29j_shut_down_pools_8017c26c = 0x8017c26c;
lbl_80456f14 = 0x80456f14;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_auto_80170b10 = 0x80170b10;
w3d_auto_80174520 = 0x80174520;
w3d_auto_8017f524 = 0x8017f524;
w3d_auto_8018774c = 0x8018774c;
w3d_auto_8018a7e4 = 0x8018a7e4;
w3d_handle_storage_release = 0x802134fc;
w3d_null_pool_size = 0x801829bc;
w3d_pset_pool_size = 0x80183eb4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text._._15D30jPoolManager 0x8017bf40 : { *(.text._._15D30jPoolManager) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; lbl_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
