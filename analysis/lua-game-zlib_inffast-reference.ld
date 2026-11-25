/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(inflate_fast)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
inflate_mask = 0x80403f10;
SECTIONS {
  .text.inflate_fast 0x802ca168 : { *(.text.inflate_fast) }
  .rodata 0x803d8ffc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
