/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_state_create_800cdaf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_state_class_80360ba0 = 0x80360ba0;
w3d_state_init_800cdbcc = 0x800cdbcc;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_k7a_state_create_800cdaf8 0x800cdaf8 : { *(.text.w3d_k7a_state_create_800cdaf8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
