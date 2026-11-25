/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19c_place_on_floor_800d5028)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d19c_default_velocity_8045e788 = 0x8045e788;
d19c_node_height_80178df0 = 0x80178df0;
d19c_placement_record_800fc6dc = 0x800fc6dc;
d19c_read_id_80178c48 = 0x80178c48;
SECTIONS {
  .text.d19c_place_on_floor_800d5028 0x800d5028 : { *(.text.d19c_place_on_floor_800d5028) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
