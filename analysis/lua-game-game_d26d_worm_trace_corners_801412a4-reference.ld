/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_worm_trace_corners_801412a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
centre_804530a8 = 0x804530a8;
compute_800bd920 = 0x800bd920;
corners_80453030 = 0x80453030;
probe_800b11dc = 0x800b11dc;
rotation_801f725c = 0x801f725c;
traceNormal_8043ae38 = 0x8043ae38;
tracePoint_8043ae20 = 0x8043ae20;
trace_800b0cf8 = 0x800b0cf8;
SECTIONS {
  .text.d26d_worm_trace_corners_801412a4 0x801412a4 : { *(.text.d26d_worm_trace_corners_801412a4) }
  .rodata 0x803a0458 : { *(.rodata) }
  .sdata 0x804ab3cc (NOLOAD) : {
    . = 0x0; traceRange_804ab3cc = .;
    . = 0x6398; traceFrac_804b1764 = .;
    . = 0x63b8; traceReady_804b1784 = .;
    . = 0x63dc; traceB_804b17a8 = .;
    . = 0x63e0; traceA_804b17ac = .;
    . = 0x6444; traceDone_804b1810 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
