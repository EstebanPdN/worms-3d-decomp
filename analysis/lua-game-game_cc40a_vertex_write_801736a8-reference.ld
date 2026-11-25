/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc40a_vertex_write_801736a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc40a_lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.cc40a_vertex_write_801736a8 0x801736a8 : { *(.text.cc40a_vertex_write_801736a8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
