/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26j_set_colour_80173df0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.d26j_set_colour_80173df0 0x80173df0 : { *(.text.d26j_set_colour_80173df0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
