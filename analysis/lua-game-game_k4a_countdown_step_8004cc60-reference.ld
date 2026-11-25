/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_countdown_step_8004cc60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8004c850 = 0x8004c850;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_string_803772bc = 0x803772bc;
SECTIONS {
  .text.k4a_countdown_step_8004cc60 0x8004cc60 : { *(.text.k4a_countdown_step_8004cc60) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
