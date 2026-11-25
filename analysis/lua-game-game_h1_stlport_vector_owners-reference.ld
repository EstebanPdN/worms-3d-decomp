/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_list_holder_clear_8034aef4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_list_holder_clear_8034aef4 0x8034aef4 : { *(.text.w3d_list_holder_clear_8034aef4) }
  .text.w3d_row_table_destroy_8034be70 0x8034be70 : { *(.text.w3d_row_table_destroy_8034be70) }
  .text.w3d_vec4_tables_destroy_8035a244 0x8035a244 : { *(.text.w3d_vec4_tables_destroy_8035a244) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
