/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_payload_state_create_800cc7cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_payload_state_init_800cc8a0 = 0x800cc8a0;
w3d_state_class_80360b70 = 0x80360b70;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_k7a_payload_state_create_800cc7cc 0x800cc7cc : { *(.text.w3d_k7a_payload_state_create_800cc7cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
