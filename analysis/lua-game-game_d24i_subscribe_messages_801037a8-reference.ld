/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_subscribe_messages_801037a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._16d24i_MessageName = 0x8015f558;
__16d24i_MessageNamePCc = 0x8015f518;
allocate_80212fd4 = 0x80212fd4;
copy_802eee50 = 0x802eee50;
d24i_cached_id_8015f5a0 = 0x8015f5a0;
d24i_entry_allocate_801fe1d8 = 0x801fe1d8;
d24i_names_803fcd58 = 0x803fcd58;
d24i_subscribe_80162024 = 0x80162024;
free_802134fc = 0x802134fc;
SECTIONS {
  .text.d24i_subscribe_messages_801037a8 0x801037a8 : { *(.text.d24i_subscribe_messages_801037a8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
