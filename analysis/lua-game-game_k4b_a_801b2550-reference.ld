/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_writer_append_indent_801b2550)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memset = 0x802eefe0;
w3d_string_append = 0x8020bf2c;
SECTIONS {
  .text.w3d_k4b_writer_append_indent_801b2550 0x801b2550 : { *(.text.w3d_k4b_writer_append_indent_801b2550) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
