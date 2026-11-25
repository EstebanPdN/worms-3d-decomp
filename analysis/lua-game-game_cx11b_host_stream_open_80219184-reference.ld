/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_host_stream_open_80219184)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
close_80219264 = 0x80219264;
fail_803b3910 = 0x803b3910;
format_803b395c = 0x803b395c;
open_802e4ce4 = 0x802e4ce4;
success_803b390c = 0x803b390c;
trace_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_cx11b_host_stream_open_80219184 0x80219184 : { *(.text.w3d_cx11b_host_stream_open_80219184) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; trace_context_804b0640 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
