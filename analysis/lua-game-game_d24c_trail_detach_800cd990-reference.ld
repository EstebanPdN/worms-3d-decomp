/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_trail_detach_800cd990)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lookup_80164fc8 = 0x80164fc8;
trail_80122af8 = 0x80122af8;
SECTIONS {
  .text.d24c_trail_detach_800cd990 0x800cd990 : { *(.text.d24c_trail_detach_800cd990) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
