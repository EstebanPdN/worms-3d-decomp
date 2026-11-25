/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_table_rebuild_800994b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_alloc_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_free_802134fc = 0x802134fc;
w3d_move_802eeef4 = 0x802eeef4;
w3d_service_pair_8015aea8 = 0x8015aea8;
w3d_service_query_8015ae74 = 0x8015ae74;
SECTIONS {
  .text.w3d_d28b_table_rebuild_800994b4 0x800994b4 : { *(.text.w3d_d28b_table_rebuild_800994b4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
