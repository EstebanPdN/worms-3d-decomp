/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_named_record_reserve_80355858)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_allocate_80212fd4 = 0x80212fd4;
cx9c_allocation_fallback_803413d8 = 0x803413d8;
cx9c_deallocate_802134fc = 0x802134fc;
cx9c_string_finish_8020c5c4 = 0x8020c5c4;
cx9c_string_header_80341884 = 0x80341884;
cx9c_string_init_8020c5c0 = 0x8020c5c0;
cx9c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_cx9c_named_record_reserve_80355858 0x80355858 : { *(.text.w3d_cx9c_named_record_reserve_80355858) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
