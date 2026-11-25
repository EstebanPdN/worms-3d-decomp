/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k1d_compact_buffer_801a6668)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_k1d_compact_buffer_801a6668 0x801a6668 : { *(.text.w3d_k1d_compact_buffer_801a6668) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
