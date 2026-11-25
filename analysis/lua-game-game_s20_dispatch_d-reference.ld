/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_target_or_record_801a381c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_dispatch_target_or_record_801a381c 0x801a381c : { *(.text.w3d_s20_dispatch_target_or_record_801a381c) }
  .text.w3d_s20_dispatch_masked_801a3a44 0x801a3a44 : { *(.text.w3d_s20_dispatch_masked_801a3a44) }
  .text.w3d_s20_dispatch_two_results_801ac41c 0x801ac41c : { *(.text.w3d_s20_dispatch_two_results_801ac41c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
