/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_push_triple_8016e57c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016e608 = 0x8016e608;
SECTIONS {
  .text.w3d_s20_push_triple_8016e57c 0x8016e57c : { *(.text.w3d_s20_push_triple_8016e57c) }
  .text.w3d_s20_remap_item_indices_801ab98c 0x801ab98c : { *(.text.w3d_s20_remap_item_indices_801ab98c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
