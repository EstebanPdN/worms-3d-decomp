/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f9b_random_decay_80036b08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
context_80165254 = 0x80165254;
random_80162ba8 = 0x80162ba8;
SECTIONS {
  .text.f9b_random_decay_80036b08 0x80036b08 : { *(.text.f9b_random_decay_80036b08) }
  .rodata 0x80373cc0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
