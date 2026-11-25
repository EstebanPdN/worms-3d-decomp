/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_apply_long_property_801ec224)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801f9fbc = 0x801f9fbc;
SECTIONS {
  .text.w3d_apply_long_property_801ec224 0x801ec224 : { *(.text.w3d_apply_long_property_801ec224) }
  .text.w3d_apply_long_property_801ec360 0x801ec360 : { *(.text.w3d_apply_long_property_801ec360) }
  .text.w3d_forward_indexed_801fb824 0x801fb824 : { *(.text.w3d_forward_indexed_801fb824) }
  .text.w3d_forward_indexed_801fb8b8 0x801fb8b8 : { *(.text.w3d_forward_indexed_801fb8b8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
