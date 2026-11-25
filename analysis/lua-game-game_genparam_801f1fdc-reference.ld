/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pmf_forward_801f1fdc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80359a88 = 0x80359a88;
SECTIONS {
  .text.w3d_pmf_forward_801f1fdc 0x801f1fdc : { *(.text.w3d_pmf_forward_801f1fdc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
