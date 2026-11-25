/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_arena_allocate_existing_80209d50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
grow_80209e08 = 0x80209e08;
SECTIONS {
  .text.w3d_cx10b_arena_allocate_existing_80209d50 0x80209d50 : { *(.text.w3d_cx10b_arena_allocate_existing_80209d50) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
