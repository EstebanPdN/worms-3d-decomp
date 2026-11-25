/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_node_construct_801bcb0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_node_base_init_801bc6c4 = 0x801bc6c4;
w3d_vtable_80415280 = 0x80415280;
SECTIONS {
  .text.w3d_k2b_node_construct_801bcb0c 0x801bcb0c : { *(.text.w3d_k2b_node_construct_801bcb0c) }
  .rodata 0x803ab920 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
