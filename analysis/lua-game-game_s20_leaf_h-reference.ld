/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_get_vector_item_800ffca4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_get_vector_item_800ffca4 0x800ffca4 : { *(.text.w3d_s20_get_vector_item_800ffca4) }
  .text.w3d_s20_init_registry_8016130c 0x8016130c : { *(.text.w3d_s20_init_registry_8016130c) }
  .text.w3d_s20_lookup_handle_object_80164fc8 0x80164fc8 : { *(.text.w3d_s20_lookup_handle_object_80164fc8) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . = 0x38; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
