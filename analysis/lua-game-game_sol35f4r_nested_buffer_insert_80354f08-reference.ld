/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35f4r_nested_buffer_insert_80354f08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35f4r_allocate_80212fd4 = 0x80212fd4;
sol35f4r_fallback_803413d8 = 0x803413d8;
sol35f4r_memcpy_802eee50 = 0x802eee50;
sol35f4r_release_802134fc = 0x802134fc;
sol35f4r_resize_80213750 = 0x80213750;
SECTIONS {
  .text.sol35f4r_nested_buffer_insert_80354f08 0x80354f08 : { *(.text.sol35f4r_nested_buffer_insert_80354f08) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
