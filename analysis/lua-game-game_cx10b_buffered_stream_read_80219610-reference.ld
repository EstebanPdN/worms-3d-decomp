/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_buffered_stream_read_80219610)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
copy_802eee50 = 0x802eee50;
refill_802198bc = 0x802198bc;
SECTIONS {
  .text.w3d_cx10b_buffered_stream_read_80219610 0x80219610 : { *(.text.w3d_cx10b_buffered_stream_read_80219610) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
