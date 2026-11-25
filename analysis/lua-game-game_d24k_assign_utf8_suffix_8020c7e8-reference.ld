/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24k_assign_utf8_suffix_8020c7e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__Q214D24kUtf8Suffix6String = 0x803426b8;
string_allocate_8020bc88 = 0x8020bc88;
string_base_init_8020c5c0 = 0x8020c5c0;
string_character_count_8020c5cc = 0x8020c5cc;
string_finish_8020c5c4 = 0x8020c5c4;
string_free_8020bb2c = 0x8020bb2c;
string_header_80341884 = 0x80341884;
string_release_80341588 = 0x80341588;
string_transfer_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_d24k_assign_utf8_suffix_8020c7e8 0x8020c7e8 : { *(.text.w3d_d24k_assign_utf8_suffix_8020c7e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
