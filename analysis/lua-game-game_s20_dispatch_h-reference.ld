/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_two_records_801a3d90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_dispatch_two_records_801a3d90 0x801a3d90 : { *(.text.w3d_s20_dispatch_two_records_801a3d90) }
  .text.w3d_s20_dispatch_five_targets_801a4874 0x801a4874 : { *(.text.w3d_s20_dispatch_five_targets_801a4874) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
