/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_triangle_dispatch_8010b318)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38a_high_8010b198 = 0x8010b198;
cc38a_low_8010b118 = 0x8010b118;
cc38a_prepare_8010ad24 = 0x8010ad24;
SECTIONS {
  .text.cc38a_triangle_dispatch_8010b318 0x8010b318 : { *(.text.cc38a_triangle_dispatch_8010b318) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
