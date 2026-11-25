/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pmf_forward_801f17f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_803582b4 = 0x803582b4;
SECTIONS {
  .text.w3d_pmf_forward_801f17f4 0x801f17f4 : { *(.text.w3d_pmf_forward_801f17f4) }
  .text.w3d_pmf_forward_801f1954 0x801f1954 : { *(.text.w3d_pmf_forward_801f1954) }
  .text.w3d_pmf_forward_801f1a5c 0x801f1a5c : { *(.text.w3d_pmf_forward_801f1a5c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
