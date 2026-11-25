/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10a_release_tables_800fbf64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10a_held_8044a524 = 0x8044a524;
d10a_held_8044a564 = 0x8044a564;
d10a_held_8044a574 = 0x8044a574;
d10a_held_8044a584 = 0x8044a584;
d10a_held_8044a5c4 = 0x8044a5c4;
d10a_held_8044a5d4 = 0x8044a5d4;
d10a_held_8044a5e4 = 0x8044a5e4;
SECTIONS {
  .text.d10a_release_tables_800fbf64 0x800fbf64 : { *(.text.d10a_release_tables_800fbf64) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
