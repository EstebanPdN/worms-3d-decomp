/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g2b_pair_callbacks_801ad974)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ad108 = 0x801ad108;
SECTIONS {
  .text.g2b_pair_callbacks_801ad974 0x801ad974 : { *(.text.g2b_pair_callbacks_801ad974) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
