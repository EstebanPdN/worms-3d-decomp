/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_slot_shutdown_callback)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_shared_slots = 0x8042e09c;
SECTIONS {
  .text.w3d_slot_shutdown_callback 0x80069a90 : { *(.text.w3d_slot_shutdown_callback) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
