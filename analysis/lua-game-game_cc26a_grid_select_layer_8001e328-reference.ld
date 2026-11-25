/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc26a_grid_select_layer_8001e328)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc26a_hop_8001e2dc = 0x8001e2dc;
cc26a_lower_8001e11c = 0x8001e11c;
cc26a_upper_8001e1a0 = 0x8001e1a0;
SECTIONS {
  .text.cc26a_grid_select_layer_8001e328 0x8001e328 : { *(.text.cc26a_grid_select_layer_8001e328) }
  .rodata 0x8036b840 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
