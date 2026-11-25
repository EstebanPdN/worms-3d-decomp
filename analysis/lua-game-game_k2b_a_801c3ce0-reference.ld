/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_region_construct_801c3ce0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_region_base_init_801ea0ec = 0x801ea0ec;
w3d_vtable_80414c68 = 0x80414c68;
SECTIONS {
  .text.w3d_k2b_region_construct_801c3ce0 0x801c3ce0 : { *(.text.w3d_k2b_region_construct_801c3ce0) }
  .rodata 0x803ac8fc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
