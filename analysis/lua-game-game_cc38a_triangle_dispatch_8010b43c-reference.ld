/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc38a_triangle_dispatch_8010b43c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc38a_high_8010b298 = 0x8010b298;
cc38a_low_8010b218 = 0x8010b218;
cc38a_prepare_8010ad24 = 0x8010ad24;
SECTIONS {
  .text.cc38a_triangle_dispatch_8010b43c 0x8010b43c : { *(.text.cc38a_triangle_dispatch_8010b43c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
