/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_forward_differences_80197208)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_forward_differences_80197208 0x80197208 : { *(.text.w3d_s20_forward_differences_80197208) }
  .text.w3d_s20_dispatch_item_801a4a58 0x801a4a58 : { *(.text.w3d_s20_dispatch_item_801a4a58) }
  .text.w3d_s20_set_block_801c7e34 0x801c7e34 : { *(.text.w3d_s20_set_block_801c7e34) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
