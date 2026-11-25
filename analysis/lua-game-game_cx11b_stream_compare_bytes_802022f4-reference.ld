/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_stream_compare_bytes_802022f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_80209060 = 0x80209060;
compare_802eedc0 = 0x802eedc0;
release_801fe288 = 0x801fe288;
SECTIONS {
  .text.w3d_cx11b_stream_compare_bytes_802022f4 0x802022f4 : { *(.text.w3d_cx11b_stream_compare_bytes_802022f4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
