/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_snapshot_reset_800e6c30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16s8_Base_800dcbc4PC9s8_Triple = 0x800dcbc4;
SECTIONS {
  .text.s8_snapshot_reset_800e6c30 0x800e6c30 : { *(.text.s8_snapshot_reset_800e6c30) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
