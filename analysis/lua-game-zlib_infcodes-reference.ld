/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(inflate_codes_new)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
inflate_fast = 0x802ca168;
inflate_flush = 0x802cae50;
inflate_mask = 0x80403f10;
SECTIONS {
  .text.inflate_codes_new 0x802c993c : { *(.text.inflate_codes_new) }
  .text.inflate_codes 0x802c99a8 : { *(.text.inflate_codes) }
  .text.inflate_codes_free 0x802ca134 : { *(.text.inflate_codes_free) }
  .rodata 0x803d8fc8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
