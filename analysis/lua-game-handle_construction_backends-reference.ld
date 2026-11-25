/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_handle_set_bounds)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_table = 0x804273ec;
w3d_handle_update_resource = 0x8003fb0c;
SECTIONS {
  .text.w3d_handle_set_bounds 0x8003fa2c : { *(.text.w3d_handle_set_bounds) }
  .text.w3d_handle_set_slot_word 0x8003fbb8 : { *(.text.w3d_handle_set_slot_word) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
