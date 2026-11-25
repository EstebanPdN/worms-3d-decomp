/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k1d_compact_buffer_80153a58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_k1d_compact_buffer_80153a58 0x80153a58 : { *(.text.w3d_k1d_compact_buffer_80153a58) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
