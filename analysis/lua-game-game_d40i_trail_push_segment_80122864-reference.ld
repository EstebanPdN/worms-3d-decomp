/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40i_trail_push_segment_80122864)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
array_lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.d40i_trail_push_segment_80122864 0x80122864 : { *(.text.d40i_trail_push_segment_80122864) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
