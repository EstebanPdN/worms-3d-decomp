/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_relative_health_score_8001210c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_reset_8000b2f8 = 0x8000b2f8;
cc24a_weighted_8000b344 = 0x8000b344;
cc24a_zero_8036a45c = 0x8036a45c;
SECTIONS {
  .text.cc24a_planner_relative_health_score_8001210c 0x8001210c : { *(.text.cc24a_planner_relative_health_score_8001210c) }
  .rodata 0x8036a460 : { *(.rodata) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; cc24a_entries_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
