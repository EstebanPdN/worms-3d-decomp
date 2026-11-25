/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(inflate_blocks_reset)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
inflate_codes = 0x802c99a8;
inflate_codes_free = 0x802ca134;
inflate_codes_new = 0x802c993c;
inflate_flush = 0x802cae50;
inflate_mask = 0x80403f10;
inflate_trees_bits = 0x802caa78;
inflate_trees_dynamic = 0x802caafc;
inflate_trees_fixed = 0x802cac50;
inflate_trees_free = 0x802cadd8;
memcpy = 0x802eee50;
SECTIONS {
  .text.inflate_blocks_reset 0x802c8be0 : { *(.text.inflate_blocks_reset) }
  .text.inflate_blocks_new 0x802c8cb8 : { *(.text.inflate_blocks_new) }
  .text.inflate_blocks 0x802c8d70 : { *(.text.inflate_blocks) }
  .text.inflate_blocks_free 0x802c98e0 : { *(.text.inflate_blocks_free) }
  .rodata 0x803d8f54 : { *(.rodata) }
  .data 0x80403cac : { *(.data) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
