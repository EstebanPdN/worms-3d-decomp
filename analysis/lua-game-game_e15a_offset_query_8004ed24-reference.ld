/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_e15a_offset_query_8004ed24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80377898 = 0x80377898;
SECTIONS {
  .text.w3d_e15a_offset_query_8004ed24 0x8004ed24 : { *(.text.w3d_e15a_offset_query_8004ed24) }
  .rodata 0x80377890 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
