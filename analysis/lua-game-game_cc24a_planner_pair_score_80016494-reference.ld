/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_pair_score_80016494)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_factor_80016564 = 0x80016564;
SECTIONS {
  .text.cc24a_planner_pair_score_80016494 0x80016494 : { *(.text.cc24a_planner_pair_score_80016494) }
  .rodata 0x8036a65c : { *(.rodata) }
  .sdata 0x804aa6f8 (NOLOAD) : {
    . = 0x0; cc24a_pairs_804aa6f8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
