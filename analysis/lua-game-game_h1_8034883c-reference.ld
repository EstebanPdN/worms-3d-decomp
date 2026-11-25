/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_set_and_register_8034883c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80210b90 = 0x80210b90;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_h1_set_and_register_8034883c 0x8034883c : { *(.text.w3d_h1_set_and_register_8034883c) }
  .text.w3d_h1_set_and_register_80349b20 0x80349b20 : { *(.text.w3d_h1_set_and_register_80349b20) }
  .text.w3d_h1_fill_allocated_blocks_80353454 0x80353454 : { *(.text.w3d_h1_fill_allocated_blocks_80353454) }
  .text.w3d_h1_string_tree_erase_8035a3f8 0x8035a3f8 : { *(.text.w3d_h1_string_tree_erase_8035a3f8) }
  .text.w3d_h1_fill_allocated_blocks_8035ec0c 0x8035ec0c : { *(.text.w3d_h1_fill_allocated_blocks_8035ec0c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
