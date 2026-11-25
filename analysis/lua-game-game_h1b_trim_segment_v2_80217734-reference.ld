/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(h1b_trim_segment_v2_80217734)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80400770 = 0x80400770;
SECTIONS {
  .text.h1b_trim_segment_v2_80217734 0x80217734 : { *(.text.h1b_trim_segment_v2_80217734) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
