/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17a_clear_owned_items_800a5e04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
copy_802eee50 = 0x802eee50;
destroy_8015f558 = 0x8015f558;
release_80209920 = 0x80209920;
SECTIONS {
  .text.w3d_cc17a_clear_owned_items_800a5e04 0x800a5e04 : { *(.text.w3d_cc17a_clear_owned_items_800a5e04) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; heap_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
