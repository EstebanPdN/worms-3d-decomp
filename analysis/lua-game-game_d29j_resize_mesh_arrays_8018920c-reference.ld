/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29j_resize_mesh_arrays_8018920c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.d29j_resize_mesh_arrays_8018920c 0x8018920c : { *(.text.d29j_resize_mesh_arrays_8018920c) }
  .rodata 0x803a7be8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
