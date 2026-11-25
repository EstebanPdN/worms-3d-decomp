/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_property_stream_deserialize_801e20e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_802098d8 = 0x802098d8;
collect_80209968 = 0x80209968;
release_80209920 = 0x80209920;
SECTIONS {
  .text.w3d_cx12b_property_stream_deserialize_801e20e0 0x801e20e0 : { *(.text.w3d_cx12b_property_stream_deserialize_801e20e0) }
  .sdata 0x804b0564 (NOLOAD) : {
    . = 0x0; heap_804b0564 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
