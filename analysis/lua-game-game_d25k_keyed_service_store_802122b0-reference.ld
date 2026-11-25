/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25k_keyed_service_store_802122b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
compare_802eedc0 = 0x802eedc0;
insert_8035c75c = 0x8035c75c;
SECTIONS {
  .text.w3d_d25k_keyed_service_store_802122b0 0x802122b0 : { *(.text.w3d_d25k_keyed_service_store_802122b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
