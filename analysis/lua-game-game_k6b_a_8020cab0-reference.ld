/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_hash_table_construct_8020cab0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8035c9f8 = 0x8035c9f8;
memset = 0x802eefe0;
w3d_heap_allocate_entry_b = 0x801fe220;
w3d_s21_power_of_two_b_8020ca70 = 0x8020ca70;
SECTIONS {
  .text.w3d_k6b_hash_table_construct_8020cab0 0x8020cab0 : { *(.text.w3d_k6b_hash_table_construct_8020cab0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
