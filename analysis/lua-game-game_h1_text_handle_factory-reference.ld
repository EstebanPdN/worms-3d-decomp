/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_text_handle_make_80348e34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_new = 0x801fe1d8;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_text_construct_8015d0a8 = 0x8015d0a8;
w3d_text_owner_make_handle = 0x8015d278;
w3d_text_set_8015d2f4 = 0x8015d2f4;
SECTIONS {
  .text.w3d_text_handle_make_80348e34 0x80348e34 : { *(.text.w3d_text_handle_make_80348e34) }
  .text.w3d_text_handle_make_8034a128 0x8034a128 : { *(.text.w3d_text_handle_make_8034a128) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
