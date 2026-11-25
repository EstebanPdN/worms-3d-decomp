/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_release_object_800e0400)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_s20_release_object_800e0400 0x800e0400 : { *(.text.w3d_s20_release_object_800e0400) }
  .text.w3d_s20_set_pending_vector_800ecec0 0x800ecec0 : { *(.text.w3d_s20_set_pending_vector_800ecec0) }
  .text.w3d_s20_update_span_800ecee8 0x800ecee8 : { *(.text.w3d_s20_update_span_800ecee8) }
  .text.w3d_s20_get_vector_800ed070 0x800ed070 : { *(.text.w3d_s20_get_vector_800ed070) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
