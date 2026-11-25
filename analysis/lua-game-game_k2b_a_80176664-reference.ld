/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_table_acquire_80176664)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_table_find_80177eb0 = 0x80177eb0;
SECTIONS {
  .text.w3d_k2b_table_acquire_80176664 0x80176664 : { *(.text.w3d_k2b_table_acquire_80176664) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
