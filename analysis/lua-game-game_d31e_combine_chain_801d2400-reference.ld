/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31e_combine_chain_801d2400)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_identity = 0x8045e748;
w3d_auto_801f740c = 0x801f740c;
SECTIONS {
  .text.w3d_d31e_combine_chain_801d2400 0x801d2400 : { *(.text.w3d_d31e_combine_chain_801d2400) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
