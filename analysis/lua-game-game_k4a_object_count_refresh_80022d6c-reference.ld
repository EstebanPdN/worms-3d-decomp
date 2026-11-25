/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_object_count_refresh_80022d6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s9_update_value_80178c54 = 0x80178c54;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_803426b4 = 0x803426b4;
w3d_str_8036c53c = 0x8036c53c;
SECTIONS {
  .text.k4a_object_count_refresh_80022d6c 0x80022d6c : { *(.text.k4a_object_count_refresh_80022d6c) }
  .sdata 0x804aca48 (NOLOAD) : {
    . = 0x0; w3d_held_804aca48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
