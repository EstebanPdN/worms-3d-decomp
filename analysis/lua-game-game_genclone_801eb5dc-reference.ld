/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_pmf_read_801eb5dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_pmf_read_801eb5dc 0x801eb5dc : { *(.text.w3d_pmf_read_801eb5dc) }
  .text.w3d_pmf_read_801ebea0 0x801ebea0 : { *(.text.w3d_pmf_read_801ebea0) }
  .text.w3d_pmf_read_801ec060 0x801ec060 : { *(.text.w3d_pmf_read_801ec060) }
  .text.w3d_pmf_read_801ec784 0x801ec784 : { *(.text.w3d_pmf_read_801ec784) }
  .text.w3d_pmf_read_801ecbd4 0x801ecbd4 : { *(.text.w3d_pmf_read_801ecbd4) }
  .text.w3d_pmf_read_801ecd94 0x801ecd94 : { *(.text.w3d_pmf_read_801ecd94) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
