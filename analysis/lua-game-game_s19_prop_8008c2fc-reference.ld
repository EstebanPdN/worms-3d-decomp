/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_chicken_setup_8008c2fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_property_read_800fc550 = 0x800fc550;
s8_property_write_800fc3b0 = 0x800fc3b0;
SECTIONS {
  .text.s19_chicken_setup_8008c2fc 0x8008c2fc : { *(.text.s19_chicken_setup_8008c2fc) }
  .rodata 0x8037dfa8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
