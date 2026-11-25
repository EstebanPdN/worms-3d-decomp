/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_stream_format_801d6000)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802ed5e0 = 0x802ed5e0;
SECTIONS {
  .text.w3d_cx16b_stream_format_801d6000 0x801d6000 : { *(.text.w3d_cx16b_stream_format_801d6000) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
