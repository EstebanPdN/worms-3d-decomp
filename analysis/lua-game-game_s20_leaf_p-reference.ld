/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_query_then_run_801ad108)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_query_then_run_801ad108 0x801ad108 : { *(.text.w3d_s20_query_then_run_801ad108) }
  .text.w3d_s20_release_both_801b1ac4 0x801b1ac4 : { *(.text.w3d_s20_release_both_801b1ac4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
