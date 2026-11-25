/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_hash_service_lookup_802117ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
compare_802eedc0 = 0x802eedc0;
SECTIONS {
  .text.w3d_cx10b_hash_service_lookup_802117ec 0x802117ec : { *(.text.w3d_cx10b_hash_service_lookup_802117ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
