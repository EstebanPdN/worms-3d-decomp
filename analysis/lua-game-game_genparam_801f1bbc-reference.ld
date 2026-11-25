/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pmf_forward_801f1bbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80358d24 = 0x80358d24;
SECTIONS {
  .text.w3d_pmf_forward_801f1bbc 0x801f1bbc : { *(.text.w3d_pmf_forward_801f1bbc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
