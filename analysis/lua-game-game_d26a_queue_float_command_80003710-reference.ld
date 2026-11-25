/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_queue_float_command_80003710)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
heap_alloc_801fe1d8 = 0x801fe1d8;
storage_allocate_80212fd4 = 0x80212fd4;
storage_copy_802eee50 = 0x802eee50;
storage_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d26a_queue_float_command_80003710 0x80003710 : { *(.text.w3d_d26a_queue_float_command_80003710) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
