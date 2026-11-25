/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_random_unit_80015810)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80162BA8 = 0x80162ba8;
SECTIONS {
  .text.s19_random_unit_80015810 0x80015810 : { *(.text.s19_random_unit_80015810) }
  .rodata 0x8036a610 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
