/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc35a_actor_capacity_query_800afb78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc35a_allocate_801613f0 = 0x801613f0;
cc35a_context_80341584 = 0x80341584;
cc35a_flush_800bd920 = 0x800bd920;
cc35a_get_801797b4 = 0x801797b4;
cc35a_id_8015f5a0 = 0x8015f5a0;
cc35a_limit_803822d8 = 0x803822d8;
cc35a_post_8016239c = 0x8016239c;
cc35a_query_800b0824 = 0x800b0824;
cc35a_vector_8043ae38 = 0x8043ae38;
cc35a_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc35a_actor_capacity_query_800afb78 0x800afb78 : { *(.text.cc35a_actor_capacity_query_800afb78) }
  .sdata 0x804ae434 (NOLOAD) : {
    . = 0x0; cc35a_cache_804ae434 = .;
    . = 0x3320; cc35a_arena_804b1754 = .;
    . = 0x3330; cc35a_result_804b1764 = .;
    . = 0x3350; cc35a_state_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
