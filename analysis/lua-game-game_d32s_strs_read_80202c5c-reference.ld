/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(strs__14D32sStrsReader)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_M_fill_insert__Q24_STLt6vector2Z12D32sStrsNameZQ24_STLt9allocator1Z12D32sStrsNameP12D32sStrsNameUiRC12D32sStrsName = 0x80347570;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__12D32sStrsName = 0x803426b8;
free = 0x802134fc;
get__14D32sStrsReaderPvi = 0x802025a8;
malloc = 0x80212fd4;
memset = 0x802eefe0;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.strs__14D32sStrsReader 0x80202c5c : { *(.text.strs__14D32sStrsReader) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
