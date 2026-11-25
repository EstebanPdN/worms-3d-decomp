/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_toggle_dispatch_8010ae30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8044c86c = 0x8044c86c;
SECTIONS {
  .text.s8_toggle_dispatch_8010ae30 0x8010ae30 : { *(.text.s8_toggle_dispatch_8010ae30) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
