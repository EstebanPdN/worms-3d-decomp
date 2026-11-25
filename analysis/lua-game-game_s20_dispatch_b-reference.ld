/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_early_table_801a38c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_dispatch_early_table_801a38c8 0x801a38c8 : { *(.text.w3d_s20_dispatch_early_table_801a38c8) }
  .text.w3d_s20_dispatch_counted_801a4b4c 0x801a4b4c : { *(.text.w3d_s20_dispatch_counted_801a4b4c) }
  .text.w3d_s20_dispatch_counted_801a4bc4 0x801a4bc4 : { *(.text.w3d_s20_dispatch_counted_801a4bc4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
