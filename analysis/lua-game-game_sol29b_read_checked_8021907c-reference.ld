/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol29b_read_checked_8021907c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol29b_read_802e4cfc = 0x802e4cfc;
SECTIONS {
  .text.sol29b_read_checked_8021907c 0x8021907c : { *(.text.sol29b_read_checked_8021907c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
