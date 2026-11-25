/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9b_service_query_status_802081f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
interface_id_8040ca10 = 0x8040ca10;
SECTIONS {
  .text.w3d_cx9b_service_query_status_802081f8 0x802081f8 : { *(.text.w3d_cx9b_service_query_status_802081f8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
