/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24f_record_vector_append_all_80346470)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
_vt.14D24fTimedWord2 = 0x804104d0;
_vt.15D24fTimedRecord = 0x80410500;
free = 0x802134fc;
malloc = 0x80212fd4;
SECTIONS {
  .text.d24f_record_vector_append_all_80346470 0x80346470 : { *(.text.d24f_record_vector_append_all_80346470) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
