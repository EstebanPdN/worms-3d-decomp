/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_flush_pending_ids_80162480)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_ids_80455244 = 0x80455244;
d24d_pending_80455250 = 0x80455250;
d24d_storage_allocate_80212fd4 = 0x80212fd4;
d24d_storage_release_802134fc = 0x802134fc;
memcpy = 0x802eee50;
SECTIONS {
  .text.d24d_flush_pending_ids_80162480 0x80162480 : { *(.text.d24d_flush_pending_ids_80162480) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
