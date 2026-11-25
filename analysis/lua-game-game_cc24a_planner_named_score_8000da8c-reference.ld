/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_named_score_8000da8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_constant_80369eb8 = 0x80369eb8;
cc24a_count_8000da34 = 0x8000da34;
cc24a_damage_8000d99c = 0x8000d99c;
cc24a_distance_8000b5f4 = 0x8000b5f4;
cc24a_exposure_8000b7dc = 0x8000b7dc;
cc24a_lookup_80341710 = 0x80341710;
cc24a_range_8000da0c = 0x8000da0c;
cc24a_reset_8000b2f8 = 0x8000b2f8;
cc24a_sum_8000b4c4 = 0x8000b4c4;
SECTIONS {
  .text.cc24a_planner_named_score_8000da8c 0x8000da8c : { *(.text.cc24a_planner_named_score_8000da8c) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; cc24a_config_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
