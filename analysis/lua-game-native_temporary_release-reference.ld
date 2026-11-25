/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_temporary_release)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_arena_high = 0x802fa668;
w3d_heap_trace = 0x802fb7ac;
w3d_temporary_records = 0x8045ebf8;
w3d_temporary_wrong_order = 0x803b2908;
SECTIONS {
  .text.w3d_temporary_release 0x801fe160 : { *(.text.w3d_temporary_release) }
  .sdata 0x804ab950 (NOLOAD) : {
    . = 0x0; w3d_temporary_count = .;
    . = 0x4; w3d_temporary_cursor = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
