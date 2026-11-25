/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_entry_property_value_800fd388)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_indexed_property_800fd3e4 = 0x800fd3e4;
w3d_auto_801797b4 = 0x801797b4;
w3d_empty_80341584 = 0x80341584;
w3d_table_8044a524 = 0x8044a524;
SECTIONS {
  .text.k4a_entry_property_value_800fd388 0x800fd388 : { *(.text.k4a_entry_property_value_800fd388) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
