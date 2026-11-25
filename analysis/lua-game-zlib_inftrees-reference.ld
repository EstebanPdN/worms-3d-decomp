/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(huft_build)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.huft_build 0x802ca4e8 : { *(.text.huft_build) }
  .text.inflate_trees_bits 0x802caa78 : { *(.text.inflate_trees_bits) }
  .text.inflate_trees_dynamic 0x802caafc : { *(.text.inflate_trees_dynamic) }
  .text.falloc 0x802cac30 : { *(.text.falloc) }
  .text.inflate_trees_fixed 0x802cac50 : { *(.text.inflate_trees_fixed) }
  .text.inflate_trees_free 0x802cadd8 : { *(.text.inflate_trees_free) }
  .rodata 0x803d9030 : { *(.rodata) }
  .data 0x80403cf8 : { *(.data) }
  .bss 0x80472594 : { *(.bss) }
  .sdata 0x804abca8 : { *(.sdata) }
  .sbss 0x804b10a0 : { *(.sbss) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
