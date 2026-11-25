/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_items_remove_key_80357c90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.w3d_items_remove_key_80357c90 0x80357c90 : { *(.text.w3d_items_remove_key_80357c90) }
  .text.w3d_items_derive_key_80357d78 0x80357d78 : { *(.text.w3d_items_derive_key_80357d78) }
  .text.w3d_items_remove_key_80357ea0 0x80357ea0 : { *(.text.w3d_items_remove_key_80357ea0) }
  .text.w3d_items_derive_key_80357f88 0x80357f88 : { *(.text.w3d_items_derive_key_80357f88) }
  .text.w3d_items_remove_key_8035d960 0x8035d960 : { *(.text.w3d_items_remove_key_8035d960) }
  .text.w3d_items_derive_key_8035da48 0x8035da48 : { *(.text.w3d_items_derive_key_8035da48) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
