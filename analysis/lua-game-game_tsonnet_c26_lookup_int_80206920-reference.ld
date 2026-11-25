/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c26_lookup_int_80206920)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
atoi = 0x802ed89c;
fn_802068fc = 0x802068fc;
fn_802ef074 = 0x802ef074;
SECTIONS {
  .text.tsonnet_c26_lookup_int_80206920 0x80206920 : { *(.text.tsonnet_c26_lookup_int_80206920) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
