/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25k_nth_service_802118e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
next_bucket_8035c988 = 0x8035c988;
SECTIONS {
  .text.w3d_d25k_nth_service_802118e8 0x802118e8 : { *(.text.w3d_d25k_nth_service_802118e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
