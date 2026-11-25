/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b37_clear_entries_80198744)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80197f98 = 0x80197f98;
SECTIONS {
  .text.tsonnet_b37_clear_entries_80198744 0x80198744 : { *(.text.tsonnet_b37_clear_entries_80198744) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
