/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f17b_query_8020b460)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802eedc0 = 0x802eedc0;
key_8040c950 = 0x8040c950;
SECTIONS {
  .text.f17b_query_8020b460 0x8020b460 : { *(.text.f17b_query_8020b460) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
