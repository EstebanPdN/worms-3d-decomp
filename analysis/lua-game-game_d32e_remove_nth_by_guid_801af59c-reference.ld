/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32e_remove_nth_by_guid_801af59c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcmp = 0x802eedc0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.w3d_d32e_remove_nth_by_guid_801af59c 0x801af59c : { *(.text.w3d_d32e_remove_nth_by_guid_801af59c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
