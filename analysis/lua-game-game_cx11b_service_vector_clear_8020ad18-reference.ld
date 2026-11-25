/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_service_vector_clear_8020ad18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
copy_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_cx11b_service_vector_clear_8020ad18 0x8020ad18 : { *(.text.w3d_cx11b_service_vector_clear_8020ad18) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
