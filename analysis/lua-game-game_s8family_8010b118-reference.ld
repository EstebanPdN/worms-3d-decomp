/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_toggle_dispatch_8010b118)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8044c6ec = 0x8044c6ec;
SECTIONS {
  .text.s8_toggle_dispatch_8010b118 0x8010b118 : { *(.text.s8_toggle_dispatch_8010b118) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
