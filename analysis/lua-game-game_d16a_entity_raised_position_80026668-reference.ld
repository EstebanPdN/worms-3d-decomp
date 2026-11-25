/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d16a_entity_raised_position_80026668)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d16a_entity_index_80178c48 = 0x80178c48;
d16a_entity_record_800fc6dc = 0x800fc6dc;
d16a_view_entity_803426b4 = 0x803426b4;
SECTIONS {
  .text.w3d_d16a_entity_raised_position_80026668 0x80026668 : { *(.text.w3d_d16a_entity_raised_position_80026668) }
  .rodata 0x8036ca50 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
