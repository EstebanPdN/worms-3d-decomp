/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_slots_shared)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_register_shutdown = 0x802ed7e0;
w3d_shared_slots = 0x8042e09c;
w3d_slots_clear = 0x801982c0;
SECTIONS {
  .text.w3d_slots_shared 0x803439d8 : { *(.text.w3d_slots_shared) }
  .sdata 0x804ad684 (NOLOAD) : {
    . = 0x0; w3d_slots_initialized = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
