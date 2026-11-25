/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_rotate_list_80155c9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_record_800fc7f8 = 0x800fc7f8;
d24d_storage_allocate_80212fd4 = 0x80212fd4;
d24d_storage_release_802134fc = 0x802134fc;
memcpy = 0x802eee50;
SECTIONS {
  .text.d24d_rotate_list_80155c9c 0x80155c9c : { *(.text.d24d_rotate_list_80155c9c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
