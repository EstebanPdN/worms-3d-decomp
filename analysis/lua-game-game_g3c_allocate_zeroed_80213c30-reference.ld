/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g3c_allocate_zeroed_80213c30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80212fd4 = 0x80212fd4;
SECTIONS {
  .text.g3c_allocate_zeroed_80213c30 0x80213c30 : { *(.text.g3c_allocate_zeroed_80213c30) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
