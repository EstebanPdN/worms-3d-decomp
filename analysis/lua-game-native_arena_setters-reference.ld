/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_arena_set_high)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_arena_set_high 0x802fa678 : { *(.text.w3d_arena_set_high) }
  .text.w3d_arena_set_low 0x802fa680 : { *(.text.w3d_arena_set_low) }
  .sdata 0x804ac668 (NOLOAD) : {
    . = 0x0; w3d_heap_arena_low_value = .;
    . = 0x4b78; w3d_heap_arena_high_value = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
