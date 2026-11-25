/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35f6a_record32_insert_80347dec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35f6a_allocate_80212fd4 = 0x80212fd4;
sol35f6a_assign_80347ce0 = 0x80347ce0;
sol35f6a_copy_refs_802109fc = 0x802109fc;
sol35f6a_destroy_refs_80210abc = 0x80210abc;
sol35f6a_fallback_803413d8 = 0x803413d8;
sol35f6a_release_802134fc = 0x802134fc;
SECTIONS {
  .text.sol35f6a_record32_insert_80347dec 0x80347dec : { *(.text.sol35f6a_record32_insert_80347dec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
