/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_rope_unwind_segment_800d13d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
hit_8043ae20 = 0x8043ae20;
rescale_800d1628 = 0x800d1628;
sqrt_802e82c0 = 0x802e82c0;
trace_800b0824 = 0x800b0824;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d27c_rope_unwind_segment_800d13d0 0x800d13d0 : { *(.text.d27c_rope_unwind_segment_800d13d0) }
  .rodata 0x803881bc : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; frac_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
