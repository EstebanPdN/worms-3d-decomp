/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_lua_release)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_aligned_resize = 0x8020908c;
w3d_profile_begin = 0x80207d60;
w3d_profile_end = 0x80207e1c;
w3d_profile_refresh = 0x80207ed8;
w3d_system_allocate_aligned = 0x80213a8c;
w3d_system_release = 0x802134fc;
SECTIONS {
  .text.w3d_lua_release 0x8019e328 : { *(.text.w3d_lua_release) }
  .text.w3d_lua_gc_boundary 0x8019e350 : { *(.text.w3d_lua_gc_boundary) }
  .text.w3d_aligned_allocate 0x801fe2a8 : { *(.text.w3d_aligned_allocate) }
  .text.w3d_aligned_release 0x801fe2e0 : { *(.text.w3d_aligned_release) }
  .text.w3d_heap_core_allocate 0x802095ec : { *(.text.w3d_heap_core_allocate) }
  .text.w3d_heap_core_release 0x80209684 : { *(.text.w3d_heap_core_release) }
  .text.w3d_heap_core_resize 0x802096cc : { *(.text.w3d_heap_core_resize) }
  .text.w3d_heap_allocate 0x802098d8 : { *(.text.w3d_heap_allocate) }
  .text.w3d_heap_release 0x80209920 : { *(.text.w3d_heap_release) }
  .text.w3d_heap_resize 0x80209944 : { *(.text.w3d_heap_resize) }
  .rodata 0x803a9938 : { *(.rodata) }
  .sdata 0x804b031c (NOLOAD) : {
    . = 0x0; w3d_lua_heap = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
