/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_weapons_dont_end_turn_800157cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc1f0 = 0x800fc1f0;
SECTIONS {
  .text.s19_weapons_dont_end_turn_800157cc 0x800157cc : { *(.text.s19_weapons_dont_end_turn_800157cc) }
  .rodata 0x8036a5f8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
