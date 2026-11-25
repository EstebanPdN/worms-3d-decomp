/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_snapshot_reset_800e6be8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16s8_Base_800dca2cii = 0x800dca2c;
SECTIONS {
  .text.s8_snapshot_reset_800e6be8 0x800e6be8 : { *(.text.s8_snapshot_reset_800e6be8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
