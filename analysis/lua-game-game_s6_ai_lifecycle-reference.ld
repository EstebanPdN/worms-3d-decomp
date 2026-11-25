/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_initialize_vectors_800067a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ai_planner_set_state = 0x800068a8;
w3d_auto_8001523c = 0x8001523c;
w3d_fn_80015d40 = 0x80015d40;
w3d_fn_80019978 = 0x80019978;
w3d_heap_allocate_entry_a = 0x801fe1d8;
SECTIONS {
  .text.w3d_ai_initialize_vectors_800067a8 0x800067a8 : { *(.text.w3d_ai_initialize_vectors_800067a8) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; w3d_ai_vector_804aa558 = .;
    . = 0x4; w3d_ai_vector_804aa55c = .;
    . = 0x8; w3d_ai_vector_804aa560 = .;
    . = 0xc; w3d_ai_vector_804aa564 = .;
    . = 0x50; w3d_ai_delays_804aa5a8 = .;
    . = 0x1f8; w3d_ai_vector_804aa750 = .;
    . = 0x1fc; w3d_ai_vector_804aa754 = .;
    . = 0x204; w3d_ai_vector_804aa75c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
