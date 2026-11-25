/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_lua_reallocate)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_copy_memory = 0x802eee50;
w3d_heap_allocate = 0x802098d8;
w3d_heap_release = 0x80209920;
w3d_heap_resize = 0x80209944;
SECTIONS {
  .text.w3d_lua_reallocate 0x8019e260 : { *(.text.w3d_lua_reallocate) }
  .sdata 0x804b031c (NOLOAD) : {
    . = 0x0; w3d_lua_heap = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
