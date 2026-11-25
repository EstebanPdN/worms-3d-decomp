/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_slot_tree_erase_80355aec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._13W3dSlotObject = 0x801f2758;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_slot_tree_erase_80355aec 0x80355aec : { *(.text.w3d_slot_tree_erase_80355aec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
