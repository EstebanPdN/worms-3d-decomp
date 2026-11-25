/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_shape_construct_801bfc38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_shape_base_init_801bf6a4 = 0x801bf6a4;
w3d_vtable_80414f10 = 0x80414f10;
SECTIONS {
  .text.w3d_k2b_shape_construct_801bfc38 0x801bfc38 : { *(.text.w3d_k2b_shape_construct_801bfc38) }
  .rodata 0x803ac124 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
