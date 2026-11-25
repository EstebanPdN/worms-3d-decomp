/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_property_data_801898e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef048 = 0x801ef048;
SECTIONS {
  .text.s9_property_data_801898e0 0x801898e0 : { *(.text.s9_property_data_801898e0) }
  .text.s9_virtual_byte_8018c57c 0x8018c57c : { *(.text.s9_virtual_byte_8018c57c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
