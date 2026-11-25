/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35f7a_string_insert_80347570)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35f7a_pool_allocate_80212fd4 = 0x80212fd4;
sol35f7a_pool_fallback_803413d8 = 0x803413d8;
sol35f7a_pool_free_802134fc = 0x802134fc;
sol35f7a_pool_header_release_8020bb2c = 0x8020bb2c;
sol35f7a_pool_string_finish_8020c5c4 = 0x8020c5c4;
sol35f7a_pool_string_header_80341884 = 0x80341884;
sol35f7a_pool_string_init_8020c5c0 = 0x8020c5c0;
sol35f7a_pool_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.sol35f7a_string_insert_80347570 0x80347570 : { *(.text.sol35f7a_string_insert_80347570) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
