/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_trigger_pool_allocate_8003f400)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__6StringPCc = 0x8020bb54;
free = 0x802134fc;
g_free_804273fc = 0x804273fc;
g_items_804273ec = 0x804273ec;
malloc = 0x80212fd4;
w3d_handle_set_name = 0x8015adf4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d32a_trigger_pool_allocate_8003f400 0x8003f400 : { *(.text.w3d_d32a_trigger_pool_allocate_8003f400) }
  .rodata 0x8037471c : { *(.rodata) }
  .sdata 0x804aa968 (NOLOAD) : {
    . = 0x0; g_named_804aa968 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
