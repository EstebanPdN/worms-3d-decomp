/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pmf_forward_801f1b64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80358bfc = 0x80358bfc;
SECTIONS {
  .text.w3d_pmf_forward_801f1b64 0x801f1b64 : { *(.text.w3d_pmf_forward_801f1b64) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
