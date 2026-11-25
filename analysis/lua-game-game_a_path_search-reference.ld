/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_path_search_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_empty_8034144c = 0x8034144c;
w3d_f32_minus_1e20_803694cc = 0x803694cc;
w3d_handle_storage_release = 0x802134fc;
w3d_memmove_802eeef4 = 0x802eeef4;
w3d_operator_delete_80015264 = 0x80015264;
w3d_path_cost_vtable_8040cba0 = 0x8040cba0;
w3d_path_search_clear_path_800062ec = 0x800062ec;
w3d_path_search_reset_80004394 = 0x80004394;
w3d_path_search_vtable_8040cb10 = 0x8040cb10;
w3d_path_table_take_80005858 = 0x80005858;
SECTIONS {
  .text.w3d_path_search_destroy 0x800042c0 : { *(.text.w3d_path_search_destroy) }
  .text.w3d_path_node_distance 0x8000443c : { *(.text.w3d_path_node_distance) }
  .text.w3d_path_bucket_find 0x80005248 : { *(.text.w3d_path_bucket_find) }
  .text.w3d_path_table_find 0x800052d4 : { *(.text.w3d_path_table_find) }
  .text.w3d_path_bucket_clear_8000532c 0x8000532c : { *(.text.w3d_path_bucket_clear_8000532c) }
  .text.w3d_path_table_clear_80005398 0x80005398 : { *(.text.w3d_path_table_clear_80005398) }
  .text.w3d_path_table_erase 0x8000553c : { *(.text.w3d_path_table_erase) }
  .text.w3d_path_search_pop 0x8000577c : { *(.text.w3d_path_search_pop) }
  .text.w3d_path_search_remove_candidate 0x800059dc : { *(.text.w3d_path_search_remove_candidate) }
  .text.w3d_path_search_status 0x80005e10 : { *(.text.w3d_path_search_status) }
  .text.w3d_path_search_remaining 0x800062b0 : { *(.text.w3d_path_search_remaining) }
  .text.w3d_path_search_next_step 0x800062bc : { *(.text.w3d_path_search_next_step) }
  .text.w3d_path_cost_construct 0x80006360 : { *(.text.w3d_path_cost_construct) }
  .text.w3d_path_cost_destroy 0x80006388 : { *(.text.w3d_path_cost_destroy) }
  .sdata 0x804aa54c (NOLOAD) : {
    . = 0x0; w3d_path_search_instance_804aa54c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
