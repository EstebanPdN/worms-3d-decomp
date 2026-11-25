/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_host_stream_read_80218fe8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
format_803b393c = 0x803b393c;
read_802e4cf4 = 0x802e4cf4;
trace_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_cx11b_host_stream_read_80218fe8 0x80218fe8 : { *(.text.w3d_cx11b_host_stream_read_80218fe8) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; trace_context_804b0640 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
