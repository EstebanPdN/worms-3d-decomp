/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_next_live_worm_801558dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_storage_allocate_80212fd4 = 0x80212fd4;
d24d_storage_release_802134fc = 0x802134fc;
d24d_worm_info_800fc6dc = 0x800fc6dc;
memcpy = 0x802eee50;
SECTIONS {
  .text.d24d_next_live_worm_801558dc 0x801558dc : { *(.text.d24d_next_live_worm_801558dc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
