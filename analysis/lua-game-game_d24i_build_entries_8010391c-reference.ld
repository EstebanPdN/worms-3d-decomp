/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_build_entries_8010391c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_80212fd4 = 0x80212fd4;
copy_802eee50 = 0x802eee50;
d24i_entry_construct_8005ff48 = 0x8005ff48;
d24i_heap_allocate_802098d8 = 0x802098d8;
d24i_ids_803fcdec = 0x803fcdec;
free_802134fc = 0x802134fc;
SECTIONS {
  .text.d24i_build_entries_8010391c 0x8010391c : { *(.text.d24i_build_entries_8010391c) }
  .sdata 0x804af15c (NOLOAD) : {
    . = 0x0; d24i_arena_804af15c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
