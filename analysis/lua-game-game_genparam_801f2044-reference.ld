/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pmf_forward_801f2044)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80359bb0 = 0x80359bb0;
SECTIONS {
  .text.w3d_pmf_forward_801f2044 0x801f2044 : { *(.text.w3d_pmf_forward_801f2044) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
