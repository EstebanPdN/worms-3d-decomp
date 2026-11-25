/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29e_find_by_name_801e9e84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
fn_8020cc90 = 0x8020cc90;
w3d_cx9b_hashed_string_index_8020cbcc = 0x8020cbcc;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_k6b_hash_table_construct_8020cab0 = 0x8020cab0;
w3d_s21_vector_get_801e9db8 = 0x801e9db8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d29e_find_by_name_801e9e84 0x801e9e84 : { *(.text.w3d_d29e_find_by_name_801e9e84) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
