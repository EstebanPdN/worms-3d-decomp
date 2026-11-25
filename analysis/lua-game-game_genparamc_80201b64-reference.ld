/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_transfer_swapped32_80201b64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c = 0x8020bb2c;
fn_8020bc88 = 0x8020bc88;
lbl_803db449 = 0x803db449;
SECTIONS {
  .text.w3d_transfer_swapped32_80201b64 0x80201b64 : { *(.text.w3d_transfer_swapped32_80201b64) }
  .text.w3d_transfer_swapped32_80201c1c 0x80201c1c : { *(.text.w3d_transfer_swapped32_80201c1c) }
  .text.w3d_offer_to_children_8020a304 0x8020a304 : { *(.text.w3d_offer_to_children_8020a304) }
  .text.w3d_offer_to_children_8020a3b0 0x8020a3b0 : { *(.text.w3d_offer_to_children_8020a3b0) }
  .text.w3d_string_to_lower_8020c230 0x8020c230 : { *(.text.w3d_string_to_lower_8020c230) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
