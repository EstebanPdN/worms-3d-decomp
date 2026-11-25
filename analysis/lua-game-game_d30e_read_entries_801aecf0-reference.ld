/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_read_entries_801aecf0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__6String = 0x803426b8;
free = 0x802134fc;
lbl_803aa754 = 0x803aa754;
lbl_803aa75c = 0x803aa75c;
lbl_803aa764 = 0x803aa764;
malloc = 0x80212fd4;
reserve__Q24_STLt6vector2Z5EntryZQ24_STLt9allocator1Z5EntryUi = 0x80355858;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d30e_read_entries_801aecf0 0x801aecf0 : { *(.text.w3d_d30e_read_entries_801aecf0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
