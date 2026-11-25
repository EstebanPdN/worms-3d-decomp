/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_handle_activate_resource)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_table = 0x804273ec;
SECTIONS {
  .text.w3d_handle_activate_resource 0x8003f860 : { *(.text.w3d_handle_activate_resource) }
  .text.w3d_handle_update_resource 0x8003fb0c : { *(.text.w3d_handle_update_resource) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
