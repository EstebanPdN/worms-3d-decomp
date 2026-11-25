/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_start_timed_800ddcbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800ddb28 = 0x800ddb28;
SECTIONS {
  .text.s19_start_timed_800ddcbc 0x800ddcbc : { *(.text.s19_start_timed_800ddcbc) }
  .rodata 0x80389b68 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
