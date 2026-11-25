/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_tagged_construct_801fc3dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_vtable_80418328 = 0x80418328;
w3d_vtable_80418408 = 0x80418408;
SECTIONS {
  .text.w3d_tagged_construct_801fc3dc 0x801fc3dc : { *(.text.w3d_tagged_construct_801fc3dc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
