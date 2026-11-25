/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_half_count_score_80010464)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_base_8036a120 = 0x8036a120;
cc24a_count_800155ac = 0x800155ac;
cc24a_exposure_8000b7dc = 0x8000b7dc;
cc24a_flag_8036a124 = 0x8036a124;
cc24a_reset_8000b2f8 = 0x8000b2f8;
cc24a_weighted_8000b344 = 0x8000b344;
SECTIONS {
  .text.cc24a_planner_half_count_score_80010464 0x80010464 : { *(.text.cc24a_planner_half_count_score_80010464) }
  .rodata 0x8036a118 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; cc24a_config_804aa6d8 = .;
    . = 0x78; cc24a_entries_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
