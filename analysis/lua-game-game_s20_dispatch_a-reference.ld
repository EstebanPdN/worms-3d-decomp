/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_dispatch_item_record_801a37a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_dispatch_item_record_801a37a0 0x801a37a0 : { *(.text.w3d_s20_dispatch_item_record_801a37a0) }
  .text.w3d_s20_dispatch_owner_record_801a3944 0x801a3944 : { *(.text.w3d_s20_dispatch_owner_record_801a3944) }
  .text.w3d_s20_dispatch_owner_record_801a39c4 0x801a39c4 : { *(.text.w3d_s20_dispatch_owner_record_801a39c4) }
  .text.w3d_s20_dispatch_two_targets_801a3adc 0x801a3adc : { *(.text.w3d_s20_dispatch_two_targets_801a3adc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
