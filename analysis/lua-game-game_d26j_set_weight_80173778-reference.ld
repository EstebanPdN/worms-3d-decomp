/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26j_set_weight_80173778)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lock_801ef048 = 0x801ef048;
SECTIONS {
  .text.d26j_set_weight_80173778 0x80173778 : { *(.text.d26j_set_weight_80173778) }
  .rodata 0x803a6704 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
