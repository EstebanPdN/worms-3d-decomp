/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol30c_record_fill_insert_8034cc3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
native_array_allocate_801907a8 = 0x801907a8;
native_array_free_801907d0 = 0x801907d0;
sol30c_header_release_8020bb2c = 0x8020bb2c;
sol30c_string_finish_8020c5c4 = 0x8020c5c4;
sol30c_string_header_80341884 = 0x80341884;
sol30c_string_init_8020c5c0 = 0x8020c5c0;
sol30c_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.sol30c_record_fill_insert_8034cc3c 0x8034cc3c : { *(.text.sol30c_record_fill_insert_8034cc3c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
