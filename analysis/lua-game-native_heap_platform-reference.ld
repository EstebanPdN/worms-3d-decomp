/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_heap_morecore)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_error = 0x801fcb64;
w3d_heap_format = 0x802ec254;
w3d_heap_format_error = 0x803b2868;
w3d_heap_format_trace = 0x803b28a4;
w3d_heap_trace = 0x802fb7ac;
SECTIONS {
  .text.w3d_heap_morecore 0x801fdfc8 : { *(.text.w3d_heap_morecore) }
  .text.w3d_heap_initialize 0x80212d90 : { *(.text.w3d_heap_initialize) }
  .text.w3d_heap_arena_high 0x802fa668 : { *(.text.w3d_heap_arena_high) }
  .text.w3d_heap_arena_low 0x802fa670 : { *(.text.w3d_heap_arena_low) }
  .sdata 0x804ac668 (NOLOAD) : {
    . = 0x0; w3d_heap_arena_low_value = .;
    . = 0x3fa8; w3d_heap_limit = .;
    . = 0x3fac; w3d_heap_start = .;
    . = 0x3fb0; w3d_heap_break = .;
    . = 0x4b78; w3d_heap_arena_high_value = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
