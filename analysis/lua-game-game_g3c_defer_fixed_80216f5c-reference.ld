/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g3c_defer_fixed_80216f5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
callback_8040077c = 0x8040077c;
fn_80216e7c = 0x80216e7c;
SECTIONS {
  .text.g3c_defer_fixed_80216f5c 0x80216f5c : { *(.text.g3c_defer_fixed_80216f5c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
