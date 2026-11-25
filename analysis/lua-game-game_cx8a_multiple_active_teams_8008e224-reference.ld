/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8a_multiple_active_teams_8008e224)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.w3d_cx8a_multiple_active_teams_8008e224 0x8008e224 : { *(.text.w3d_cx8a_multiple_active_teams_8008e224) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
