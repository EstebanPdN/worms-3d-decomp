/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_hash_service_lookup_80211d18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
compare_802eedc0 = 0x802eedc0;
SECTIONS {
  .text.w3d_cx10b_hash_service_lookup_80211d18 0x80211d18 : { *(.text.w3d_cx10b_hash_service_lookup_80211d18) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
